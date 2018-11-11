#include "MyString.hpp"

#include <cstring>
#include <algorithm>
#include <stdexcept>

CString::CString()
{
	create();
}

CString::CString(const char* str)
{
	create(str, std::strlen(str));
}

CString::CString(const CString& str)
{
	create(str.str_, str.size_);
}

CString::~CString()
{
	destroy();
}

CString& CString::operator=(const CString& str)
{
	CString temp(str);
	Swap(temp);
	return *this;
}

CString& CString::operator+=(const CString& cs)
{
	size_type sz = size_ + cs.size_ + 1;
	char* temp = new char[sz];
	std::strcpy(temp, str_);
	std::strcat(temp, cs.str_);

	destroy();
	str_ = temp;
	size_ = strlen(temp);

	return *this;
}

CString::size_type CString::size()
{
	return size_;
}

bool CString::empty()
{
	return (size_ == 0);
}

void CString::create()
{
	size_ = 0;
	str_ = NULL;
}

void CString::create(const char* str, size_type sz)
{
	str_ = new char[sz + 1];
	std::strcpy(str_, str);
	size_ = sz;
}

void CString::destroy()
{
	delete[] str_;
	size_ = 0;
	str_ = NULL;
}

void CString::Swap(CString &cs) throw()
{
	std::swap(size_, cs.size_);
	std::swap(str_, cs.str_);
}

std::ostream& operator<< (std::ostream& os, const CString& cs)
{
	os << cs.str_;
	return os;
}

std::istream& operator>> (std::istream& is, CString& cs)
{
	char temp[256]; // string input maxsize
	is >> temp;
	cs = temp;
	return is;
}

const CString operator+(const CString& cs1, const CString& cs2)
{
	CString temp(cs1);
	temp += cs2;
	return temp;
}
