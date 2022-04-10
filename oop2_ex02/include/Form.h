#pragma once
#include <vector>
#include <memory>
#include "FormValidator.h"
//-------------------------------------------------------------------
using std::vector;
using std::unique_ptr;
//-------------------------------------------------------------------
class Form {
public:
    //c-tor
	Form() {};
	void addValidator(FormValidator* formValidator);
	void addField(BaseField* filedPtr);
	void fillForm();
	bool validateForm();
	void printField(std::ostream& out)const;
private:
	vector<BaseField*> m_fieldVec;
	vector<FormValidator*> m_formValidator;
	bool m_printThanks = false;
};
//-------------------------------------------------------------------
std::ostream & operator<<(std::ostream & output, const Form & form);