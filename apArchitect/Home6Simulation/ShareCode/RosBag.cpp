#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "RosBag.h"

using namespace std;

RosBag::RosBag(const char* fileName, bool record /*= true*/) {
	m_file.open(fileName, record ? ios_base::out : ios_base::in);
	assert(m_file.is_open());
}

RosBag::~RosBag() {
	m_file.close();
}

void RosBag::Play( std::function< void(const char*) > rec ) {
	char buf[64];
	while (!m_file.eof()) {
		m_file.getline(buf, sizeof(buf));
		rec(buf);
	}
}

void RosBag::Process(int type, int count) {
	char buf[64];
	sprintf_s(buf, "%d,%d\n", type, count);
	m_file.write(buf, strlen(buf));

	//cout << "RosBag::Process = " << buf << endl;
}

void RosBag::ProcessImage(int type, IMAGE img) {
	char buf[64];
	sprintf_s(buf, "%d,%d\n", type, img);
	m_file.write(buf, strlen(buf));

	//cout << "RosBag::ProcessImage = " << buf << endl;
}
