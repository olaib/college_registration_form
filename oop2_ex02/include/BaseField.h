#pragma once
#include <iostream>
#include <string>
#include <windows.h>
//-------------------------------------------------------------------
using std::string;
//the colors is a parameter we added for the printing
enum class colors :int { BLUE = 1, GREEN, RED = 4, WHITE = 7 };
//-------------------------------------------------------------------
class BaseField {
public:
    //c-tor
	BaseField(const string& question)
		:m_question(question) {}
	//destructor
	virtual ~BaseField()=default;
	//to fill the fields
	virtual void fillField()=0;
	//checking if the field is ok
	virtual bool isValidField() = 0;
	//printing the answer
	virtual void printAnswer(std::ostream& out) = 0;
	//check if valid content
	const bool& getValid();
	void setValid(const bool& val);
	//we added it for the pritning on the board
	static void changeColor(colors color);

protected:
	bool m_isValid = false;
	string m_errorMessage;
	string m_question;

private:
    //for the colors we added in the console
	static HANDLE m_hConsole;
};