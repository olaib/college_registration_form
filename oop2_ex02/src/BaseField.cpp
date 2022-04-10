#include "BaseField.h"
//-------------------------------------------------------------------
HANDLE BaseField::m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//-------------------------------------------------------------------
const bool& BaseField::getValid()
{
	return m_isValid;
}
//-------------------------------------------------------------------
void BaseField::setValid(const bool& val)
{
	m_isValid = val;
}
//-------------------------------------------------------------------
void BaseField::changeColor(colors color)
{
    //for the color we added
	SetConsoleTextAttribute(BaseField::m_hConsole, static_cast<int>(color));
}
