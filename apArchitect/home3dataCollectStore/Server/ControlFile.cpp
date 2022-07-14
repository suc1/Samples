#include <fstream>
#include <assert.h>
#include <iostream>

#include "ControlFile.h"

using namespace std;

ControlFile* ControlFile::m_pInst = nullptr;

ControlFile::ControlFile(const std::string& fileHash, uint64_t length, uint32_t	chunkSize ) {
	struct stat stat1;
	string fileName( FileName(fileHash) );
	if (stat(fileName.c_str(), &stat1) == 0) {
		ifstream conf(fileName, ios_base::in | ios_base::binary);
		if (conf.is_open()) {
			char* buf = new char[stat1.st_size];
			conf.read(buf, stat1.st_size);
			conf.close();

			m_pRec = reinterpret_cast<RECORD*>(buf);
			return;
		}
		assert(!"ControlFile cannot open");
		m_pRec = nullptr;
	}

	assert(length > 0 && chunkSize > 0);
	uint32_t chunkSum = uint32_t (length + chunkSize - 1) / chunkSize;
	int len = sizeof(RECORD) - sizeof(bool) + sizeof(bool) * chunkSum;
	m_pRec = reinterpret_cast<RECORD*>(new char[len]);

	m_pRec->length = length;
	m_pRec->chunkSize = chunkSize;
	m_pRec->chunkSum = chunkSum;
	for (uint32_t i = 0; i < chunkSum; ++i) m_pRec->flag[i] = false;

	SaveChunk(fileHash);
}

ControlFile::~ControlFile() {
	delete[]((char*)m_pRec);	//delete m_pInst;???
}

bool ControlFile::SaveChunk(const std::string& fileHash) {
	ofstream conf(FileName(fileHash), ios_base::out | ios_base::binary);
	if (conf.is_open()) {
		int len = sizeof(RECORD) - sizeof(bool) + sizeof(bool) * m_pRec->chunkSum;
		conf.write((char*)m_pRec, len);
		conf.close();
		return true;
	}
	return false;
}

ControlFile* ControlFile::Instance(const std::string& fileHash, uint64_t length/*=0*/, uint32_t	chunkSize /*=0*/) {
	if (ControlFile::m_pInst != nullptr) return ControlFile::m_pInst;

	//ToDo: thread safe
	ControlFile::m_pInst = new ControlFile(fileHash, length, chunkSize);
	return ControlFile::m_pInst;
}
int ControlFile::StartPoint(const std::string& fileHash) {
	for (uint32_t i = 0; i < m_pRec->chunkSum; ++i) {
		if (m_pRec->flag[i] != true) return i;
	}

	return -1; //All finished
}

bool ControlFile::SaveChunk(const std::string& fileHash, int no) {
	m_pRec->flag[no] = true;
	return SaveChunk(fileHash);
}