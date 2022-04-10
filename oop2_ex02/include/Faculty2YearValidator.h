#pragma once
#include "FormValidator.h"
//-------------------------------------------------------------------
const auto COMPUTER_SCIENCE = 4;
const auto LITERATURE = 3;
const auto MEDICINE = 7;
const auto CS_VAL = 1;
const auto LITER_VAL = 2;
const auto MED_VAL = 3;
const auto DEFAULT = false;
const auto FACULTY2YEAR_ERROR= "Faculty and year doesnt match\n";
//-------------------------------------------------------------------
template<class T1, typename T2>
class Faculty2YearValidator :public FormValidator{
public:
    //c-tor
	Faculty2YearValidator(T1* facultyValPtr, T2* yearFieldPtr);
	bool isValid()override;
	void repeatInp()override;
	string getErrorMessage() { return FACULTY2YEAR_ERROR; }
private:
	T1* m_facultyValPtr;
	T2* m_yearFieldPtr;
};
//-------------------------------------------------------------------
template<class T1, typename T2>
Faculty2YearValidator<T1, T2>::Faculty2YearValidator(T1* facultyValPtr, T2* yearFieldPtr) :
	m_facultyValPtr(facultyValPtr), m_yearFieldPtr(yearFieldPtr) {}
//-------------------------------------------------------------------
template<class T1, typename T2>
bool Faculty2YearValidator<T1, T2>::isValid()
{    
	const int faculty = m_facultyValPtr->getAnswer().getFacultyNum();
	const int year = m_yearFieldPtr->getAnswer();
	m_Valid = true;
	//check what to do by the faculty
	switch (faculty) {
	case CS_VAL:
		if (year > COMPUTER_SCIENCE)
			m_Valid = false;
		break;

	case MED_VAL:
		if (year > MEDICINE)
			m_Valid = false;
		break;

	case LITER_VAL:
		if (year > LITERATURE)
			m_Valid = false;
		break;

	default:
		m_Valid = false;
		break;
	}
	return m_Valid;
}
//-------------------------------------------------------------------
template<class T1, typename T2>
void Faculty2YearValidator<T1, T2>::repeatInp()
{
	std::cout << getErrorMessage();
	m_facultyValPtr->setValid(false);
	m_yearFieldPtr->setValid(false);
}
