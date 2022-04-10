# include "FacultyValue.h"
//-------------------------------------------------------------------
istream& operator>>(istream& inp,FacultyValue& facultyValue)
{
	auto input = int();
	inp >> input;
	facultyValue.setFacultyNum(input);
	return inp;
}
//-------------------------------------------------------------------
static void GetFacultyName(std::ostream& output ,const facultyVal value)
{
    //hash table
	const auto static facultyVal2string = std::map<facultyVal, string>
	{   
		{ facultyVal::CS         ,"Computer Science" },
		{ facultyVal::Medicine   , "Medicine" },
		{ facultyVal::Literature , "Literature" }
	};

	auto res = facultyVal2string.find(value);
	//if it is not found in map return the value it-self
	if (res == facultyVal2string.end())
		output << (int)value;
	else
		output << res->second;
}
//-------------------------------------------------------------------
std::ostream& operator<<(std::ostream& output, const FacultyValue& facultyValue)
{
    //for the enum
	const auto val = static_cast<facultyVal>(facultyValue.getFacultyNum());
	GetFacultyName(output, val);
	return output;
}
//-------------------------------------------------------------------
bool operator>=(const FacultyValue& f1, const FacultyValue& f2)
{
	return f1.getFacultyNum() >= f2.getFacultyNum();
}
//-------------------------------------------------------------------
bool operator<=(const FacultyValue& f1, const FacultyValue& f2)
{
	return f1.getFacultyNum() <= f2.getFacultyNum();
}
