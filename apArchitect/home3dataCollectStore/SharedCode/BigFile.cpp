#include <fstream>
#include <assert.h>
#include <iostream>
#include <chrono>

#include "BigFile.h"
#include "../../../ThirdPartyLib/hash-library/md5.h"

using namespace std;

BigFile::BigFile(const char* fileName, bool forRead)	//Client=Read, Server=Write
{
	m_fileName = fileName;

	if (forRead) {
		int i = stat(fileName, &m_stat);
		assert(i == 0);

		m_file.open(fileName, ios_base::in | ios_base::binary);
		assert(m_file.is_open());
	}
	else {
		m_file.open(fileName, ios_base::in | ios_base::out | ios_base::binary);
		if (!m_file.is_open()) {
			m_file.open(fileName, ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);
		}
		assert(m_file.is_open());
	}
}

BigFile::~BigFile()
{
	m_file.close();
}

//Client=Read
std::string BigFile::HashFileContent()
{
	static string md5;
	if (!md5.empty()) return md5;

	string hashFileName = m_fileName + ".hash";
	//ToDo: file was changed

	struct stat stat1;
	if (0 == stat(hashFileName.c_str(), &stat1)) {
		ifstream conf(hashFileName, ios_base::in);
		if (conf.is_open()) {
			char* buf = new char[stat1.st_size + 1];
			conf.read(buf, stat1.st_size);
			conf.close();
			buf[stat1.st_size] = '\0';
			md5 = buf;
			delete[] buf;

			return md5;
		}
		assert(!"hash file is corrupted");
	}
	
	ifstream bg(m_fileName, ios_base::in);
	if (!bg.is_open()) {
		assert(!"can not open bigFile");
		return md5;
	}
	
	cout << "Hash begin..." << endl;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	char buf[1024 * 2];
	MD5 md5Class;

	for (int i = 0; i < m_stat.st_size; ) {
		int readLen = GetReadWriteLen(i, sizeof(buf));
		bg.read(buf, readLen);

		md5Class.add(buf, readLen);
		i += readLen;
	}
	bg.close();
	md5 = md5Class.getHash();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Hash end: take " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[ns]" << std::endl;

	ofstream conf(hashFileName, ios_base::out);
	if (conf.is_open()) {
		conf.write(md5.c_str(), md5.length());
		conf.close();
	}
	
	return md5;
}

std::unique_ptr<char> BigFile::ReadChunk(int chunkNo, int& pos)
{
	pos = chunkNo * m_chunkSize;
	m_file.seekg(pos);
	pos = GetReadWriteLen(pos);
	assert( pos >= 0 );		//ToDo: If server ask more (chunsize changed), crash here

	//std::unique_ptr<char*> ret = std::make_unique< char[] >(m_chunkSize);
	std::unique_ptr<char> ret(new char[pos]);
	m_file.read(ret.get(), pos);
	return std::move(ret);
}

//Server=Write
bool BigFile::WriteChunk(const char* content, int chunkNo, int len)
{
	int pos = chunkNo * m_chunkSize;
	m_file.seekg(pos);
	m_file.write(content, len);
	m_file.flush(); //ToDo: Make sure Save to disk
	return true;
}
