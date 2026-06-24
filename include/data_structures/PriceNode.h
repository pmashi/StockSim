#pragma once 

#include <string> 
using std::string; 

namespace stocksim {
    struct PriceNode {
        string      date;        // "YYYY-MM-DD"
        double      open;
        double      high;
        double      low;
        double      close;
        long        volume;
        PriceNode*  next;
        PriceNode*  prev;

        PriceNode(const string& d, double o, double h, double l, double c, long v)
        :   date(d), 
            open(o), 
            high(h), 
            low(l), 
            close(c), 
            volume(v), 
            next(nullptr), 
            prev(nullptr) {}
    };
}