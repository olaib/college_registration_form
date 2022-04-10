#include "Form.h"
#include "BaseField.h"
#include <fstream>
//-------------------------------------------------------------------
const auto VALID_FORM = true;
const auto NOT_VALID_FORM = false;
const auto FILE_NAME = "resources/text.txt";
const auto OPEN_FAILED = "failed to open input file\n";
//-------------------------------------------------------------------
void Form::addValidator(FormValidator* formValidator)
{
	m_formValidator.push_back(formValidator);
}
//-------------------------------------------------------------------
void Form::addField(BaseField* filedPtr)
{
	m_fieldVec.push_back(filedPtr);
}
//-------------------------------------------------------------------
void Form::fillForm()
{
	for (auto& field : m_fieldVec)
	{
		if (!field->getValid()) {
			field->fillField();
		}
	}
}
//-------------------------------------------------------------------
bool Form::validateForm()
{
	auto formValid = true;
	for (auto& forms : m_fieldVec)
		if (!forms->isValidField())
			formValid = NOT_VALID_FORM;

	if (formValid) {
		for (auto& form : m_formValidator)
		{
			if (!form->isValid()) {
				formValid = NOT_VALID_FORM;
			}
		}
	}
	//if all the form is valid we print 3D thank you text
	if (formValid)
		m_printThanks = true;

	return formValid;
}
//-------------------------------------------------------------------
//read from text file for the thank you message
void openAndReadFile()
{
	auto thanksText = string();
	auto txtFile = std::ifstream(FILE_NAME);
	if (!txtFile) {
		std::cerr << OPEN_FAILED;
		exit(EXIT_FAILURE);
	}
	//read all text from file
	thanksText = string((std::istreambuf_iterator<char>(txtFile)), std::istreambuf_iterator<char>());
	txtFile.close();
	std::cout << thanksText;
}
//-------------------------------------------------------------------
void Form::printField(std::ostream& out) const
{
	for (auto& field : m_fieldVec)
		field->printAnswer(out);

	for (auto& form : m_formValidator)
		if (!form->getValid()) {
			form->repeatInp();
		}

	if (m_printThanks)
		openAndReadFile();
}
//-------------------------------------------------------------------
std::ostream& operator<<(std::ostream& output, const Form& form)
{
	form.printField(output);
	return output;
}
