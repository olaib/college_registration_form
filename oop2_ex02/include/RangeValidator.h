#pragma once
#include "Validator.h"
#include "MinValidator.h"
//-------------------------------------------------------------------
template<class T>
class RangeValidator:public Validator<T> {
public:
    //c-tor
	RangeValidator(const T& min,const T& max)
		:m_max(max), m_min(min) {}
	//d-tor
	virtual ~RangeValidator() = default;
	bool checkIfValid(const T&) override;
	string getErrorMessage()const override {return ERROR_MSG; }
private:
	T m_max,m_min;
	//MinValidator<T> m_min;
};
//-------------------------------------------------------------------
template<typename T>
bool RangeValidator<T>::checkIfValid(const T& val)
{
	return val <= m_max && val >= m_min;//m_min.checkIfValid(val);//
}