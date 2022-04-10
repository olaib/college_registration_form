#pragma once
#include <string>
//-------------------------------------------------------------------
using std::string;
const auto ERROR_MSG = "out of range";
//-------------------------------------------------------------------
template<class T>
class Validator{
public:
    //c-tor
	Validator() {}
	virtual bool checkIfValid(const T&) =0;
	bool isValid()const { return m_isValid; }
	void setValid(const bool& newVal) { m_isValid = newVal; }
	virtual string getErrorMessage()const = 0;
private:
	bool m_isValid=false;
};