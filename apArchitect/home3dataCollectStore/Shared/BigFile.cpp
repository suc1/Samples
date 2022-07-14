#include <fstream>
#include <assert.h>
#include <iostream>

#include "BigFile.h"

using namespace std;

BigFile::BigFile(const char* fileName, bool forRead)	//Client=Read, Server=Write
{
	if (forRead) {
		int i = stat(fileName, &m_stat);
		assert(i == 0);

		m_file.open(fileName, ios_base::in | ios_base::binary);
		assert(m_file.is_open());
	}
	else {
		m_file.open(fileName, ios_base::in | ios_base::out | ios_base::binary);
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

	//printf("Start hash ")
	return md5;
}

std::unique_ptr<char> BigFile::ReadChunk(int chunkNo)
{
	//std::unique_ptr<char*> ret = std::make_unique< char[] >(m_chunkSize);
	std::unique_ptr<char> ret ( new char[m_chunkSize] );
	return std::move(ret);
}

//Server=Write
bool BigFile::WriteChunk(const string& fileHash, int chunkNo)
{
	return true;
}
