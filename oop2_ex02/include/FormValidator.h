#pragma once
#include "BaseField.h"
//-------------------------------------------------------------------
const auto MY_ERROR_MSG = "\nCourses2YearValidator\n";
//-------------------------------------------------------------------
//this is a class for checking if 1 field is ok with the second one
class FormValidator {
public:
    //c-tor
	FormValidator() {};
	//d-tor
	virtual ~FormValidator()=default;
	virtual void repeatInp()=0;
	virtual bool isValid()=0;
	const bool& getValid() { return m_Valid; }
	virtual string getErrorMessage()=0;
protected:
	bool m_Valid=true;
};