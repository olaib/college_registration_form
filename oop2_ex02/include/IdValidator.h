#pragma once
#include "Validator.h"
#include <cstdint>
//-------------------------------------------------------------------
const auto ID_ERROR = "                     Wrong control";
//-------------------------------------------------------------------
class IDValidator :public Validator <uint32_t>{
public:
    //c-tor
	IDValidator() {};
	bool checkIfValid(const uint32_t& id) override;
	string getErrorMessage()const override {return  ID_ERROR;}
private:
};