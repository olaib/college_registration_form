#include "NoDigitValidator.h"
//-------------------------------------------------------------------
const auto EMPTY = 0;
const auto NAME_ERROR = "                    Name can not contain digits";
//-------------------------------------------------------------------
NoDigitValidator::NoDigitValidator() {}
//-------------------------------------------------------------------
bool NoDigitValidator::checkIfValid(const string& name) {
	if (name.size() == EMPTY)
		return false;

	for (auto litter : name)
		if (isdigit(litter))
			return false;
	return true;
}
//-------------------------------------------------------------------
string NoDigitValidator::getErrorMessage()const {
	return NAME_ERROR;
}