#include "utils/CSVParser.h"

#include <fstream> 
#include <sstream> 
#include <iostream> 
#include <vector> 

using std::ifstream;

namespace stocksim {

    PriceHistory* CSVParser::loadHistory(const string& filename) {
        ifstream file(filename); 
        
        if(!file.is_open()) { 
            std::cerr << "Could not open file: " << filename << "\n"; 
            return nullptr; 
        }


        PriceHistory* history = new PriceHistory(); 

        string line; 

        if(!getline(file, line)) {
            std::cerr << "File is empty: " << filename << "\n"; 
            delete history; 
            return nullptr; 
        }

        std::vector<std::string> headers; 
        std::istringstream headerStream(line); 
        string column; 
        
        while(getline(headerStream, column, ',')) {
            headers.push_back(column); 
        }

        int dateIdx, openIdx, highIdx, lowIdx, closeIdx, volumeIdx;
        
        for(int i = 0; i < headers.size(); i++) {
            if (headers[i] == "Date") {
                dateIdx = i;
            } else if (headers[i] == "Open") {
                openIdx = i;
            } else if (headers[i] == "High") {
                highIdx = i;
            } else if (headers[i] == "Low") {
                lowIdx = i;
            } else if (headers[i] == "Close") {
                closeIdx = i;
            } else if (headers[i] == "Volume") {
                volumeIdx = i;
            } 
        }

        int rowsParsed = 0; 
        int rowsSkipped = 0; 
        
    }

    bool dateInRange(const string& date, const string& start, const string& end) {
        return date > start && date <= end; 
    }

    int extractYear(const string& date) {
        return std::stoi(date.substr(0, 4)); // assume that the date format is YYYY-MM-DD
    }
    
    int extractMonth(const string& date) { 
        return std::stoi(date.substr(5, 2)); // 
    }


}