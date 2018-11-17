#pragma once

#include <iostream>

class CString {
public:
	typedef size_t size_type;
	// friend functions for in, out stream
	friend std::ostream& operator<< (std::ostream& os, const CString& cs);
	friend std::istream& operator>> (std::istream& is, CString& cs);
	//! default constructor
	CString();
	//! constructor overloading
	/*!
		\param str char* type or char[]
	*/
	CString(const char* str);
	//! constructor overloading
	/*!
		\param str CString type
	*/
	CString(const CString& str);
	//! destructor
	~CString();
	//! operator= overloading
	CString& operator=(const CString& str);
	//! operator+= overaloding
	CString& operator+=(const CString& cs);
	//! get size
	size_type size();
	//! is empty?
	bool empty();

private:
	//! initial
	void create();
	//! create & allocate memory
	void create(const char* str, size_type sz);
	//! destroy memory
	void destroy();
	//! swap the memober variables
	void Swap(CString &cs) throw();

	size_type   size_;	///< string size
	char*       str_;	///< string literal
};

const CString operator+ (const CString& cs1, const CString& cs2);
