#pragma once
#include "Field.h"
#include "FormValidator.h"
//-------------------------------------------------------------------
//for each year
enum class years:int {First=1,Second,Third,Fourth,Fifth};
const auto COURSE2YEAR_ERROR = "Num of Courses and year doesnt match";
//-------------------------------------------------------------------
//this is a template class
template<typename T1, typename T2>
class Courses2YearValidator :public FormValidator {
public:
    //c-tor
	Courses2YearValidator(T1* courseFieldPtr, T2* yearFieldPtr)
		:m_courseFieldPtr(courseFieldPtr), m_yearFieldPtr(yearFieldPtr) {}
	//check if valid
	bool isValid() override;
	//set valid for each field
	void repeatInp()override;
	string getErrorMessage() { return COURSE2YEAR_ERROR; }
private:
	T1* m_courseFieldPtr;
	T2* m_yearFieldPtr;
};
//-------------------------------------------------------------------
template<class T1, typename T2>
bool Courses2YearValidator<T1, T2>::isValid()
{
	const short courseVal = m_courseFieldPtr->getAnswer();
	const int yearVal = m_yearFieldPtr->getAnswer();
	m_Valid = true;

	//check the year and by the year check the valid
	switch (static_cast<years>(yearVal)) {
	case years::First:
	case years::Second:
		if (courseVal > 6)
			m_Valid = false;
		break;

	case years::Third:
	case years::Fourth:
		if (courseVal > 10)
			m_Valid = false;
		break;
	default:
		if (courseVal > 8)
			m_Valid = false;
		break;
	}
	return m_Valid;
}
//-------------------------------------------------------------------
template<typename T1, typename T2>
void Courses2YearValidator<T1, T2>::repeatInp()
{
	std::cout << getErrorMessage();
	m_courseFieldPtr->setValid(false);
	m_yearFieldPtr->setValid(false);
}