#pragma once
#include "Validator.h"
#include <cstdint>
//-------------------------------------------------------------------
class NoDigitValidator :public Validator<string> {
public:
    //c-tor
	NoDigitValidator();
	bool checkIfValid(const string& name);
	string getErrorMessage()const override;
private:
};