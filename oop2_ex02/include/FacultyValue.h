#pragma once
#include "RangeValidator.h"
#include <iostream>
#include <map>
//-------------------------------------------------------------------
using std::istream;
using std::ostream;
enum class facultyVal :int { CS = 1, Medicine , Literature};
//-------------------------------------------------------------------
class FacultyValue {
public:
    //c-tor
	FacultyValue(const int& facultyNum=0) :m_facultyNum(facultyNum) {}
	const int& getFacultyNum()const { return m_facultyNum; }
	void setFacultyNum(const int& value) { m_facultyNum = value; }
private:
	int m_facultyNum ;
};
//-------------------------------------------------------------------
istream& operator>>(istream&, FacultyValue&);
ostream& operator<<(ostream&, const FacultyValue&);
bool operator>=(const FacultyValue& f1, const FacultyValue& f2);
bool operator<=(const FacultyValue& f1, const FacultyValue& f2);