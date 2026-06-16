#pragma once 

#include <string> 
#include "PriceHistory.h"

using std::string; 

namespace stocksim 
{
    class CSVParser 
    {
    public: 
        static PriceHistory* loadHistory(const string& filename); 

        static bool dateInRange(const string& date, const string& start, const string& end); 
        static int extractYear(const string& date); 
        static int extractMonth(const string& date); 
    };
}