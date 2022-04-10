#pragma once
#include "BaseField.h"
#include "Validator.h"
#include <vector>
#include <windows.h>
//-------------------------------------------------------------------
const auto LINE = "\n--------------------------------------------------------------------------\n";
//-------------------------------------------------------------------
template<class T> 
class Field :public BaseField{
public:
	using BaseField::BaseField;
	void addValidator(Validator<T>* fieldPtr);
	bool isValidField() override;
	void setAnswer(T answer) { m_answer = answer; }
	const T& getAnswer()const { return m_answer; }
	void printAnswer(std::ostream& out)override;
	void fillField() override;
protected:
	T m_answer;
	std::vector<Validator<T>*> m_FieldValidators;
};
//-------------------------------------------------------------------
template<typename T>
void Field<T>::addValidator(Validator<T>* fieldPtr)
{
	m_FieldValidators.push_back(fieldPtr);
}
//-------------------------------------------------------------------
template<typename T>
bool Field<T>::isValidField()
{
    //will check validation of the fields
	m_isValid = true;
	for(auto &fieldValidator: m_FieldValidators)
		if (!fieldValidator->checkIfValid(m_answer)) {
			m_errorMessage = fieldValidator->getErrorMessage();
			m_isValid = false;
			return m_isValid;
		}
	return m_isValid;
}
//-------------------------------------------------------------------
template<typename T>
void Field<T>::printAnswer(std::ostream& out)
{   
    //func for the colors we add iin the printing
	out << m_question << " = ";
	!m_isValid ? changeColor(colors::RED) : changeColor(colors::GREEN);
	out<< m_answer << (!m_isValid ? "           "+m_errorMessage : "") << std::endl;
	changeColor(colors::WHITE);
}
//-------------------------------------------------------------------
template<typename T>
void Field<T>::fillField()
{
	std::cout << LINE << m_question;
	std::cin >> m_answer;
}