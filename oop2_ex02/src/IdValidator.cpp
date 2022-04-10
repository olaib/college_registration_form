#include "IdValidator.h"
#include <map>
//-------------------------------------------------------------------
const auto ZERO_ASCII = '0';
//-------------------------------------------------------------------
static int GetDouble(const int& i)
{
    //for the switch
    const auto static map = std::map<int, int>{ 
        {0,0},{1,2},{3,6},{4,8},{5,1}
        ,{6,3} ,{7,5},{8,7},{9,9} 
    };
    auto res = map.find(i);
    if (res == map.end())
        return 0;
    else
        return res->second;
}
//-------------------------------------------------------------------
//checking if the id number is correct
bool IDValidator::checkIfValid(const uint32_t& id)
{
    const auto id_str = std::to_string(id);
    if (id_str.size() != 9)
        return false;

    int sum = 0;

    for (int i = 0; i < id_str.size(); i++)
    {
        int digit = id_str[id_str.size() - 1 - i] - ZERO_ASCII;
        sum += (i % 2 != 0) ? GetDouble(digit) : digit;
    }
    return sum % 10 == 0;
}