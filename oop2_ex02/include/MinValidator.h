#pragma once
#include "Validator.h"
//-------------------------------------------------------------------
template<class T>
class MinValidator :public Validator<T> {
public:
    //c-tor
	MinValidator(const T& min) :m_min(min) {};
	const T& getMinVal()const { return m_min; }
	bool checkIfValid(const T& val)override;
	string getErrorMessage()const override { return ERROR_MSG; }
private:
	T m_min;
};
//-------------------------------------------------------------------
template<typename T>
bool MinValidator<T>::checkIfValid(const T& val)
{
	return val >= m_min;
}