#pragma once

#include <string> 
using std::string; 

namespace stocksim {
    struct TradeRecord {
        string  ticker; 
        string  date; 
        double  price; 
        int     shares; 
        string  action; 
        double  totalCost; 
    };

    struct StackNode {
        TradeRecord data; 
        StackNode*  next; 
    };
    

    class TradeStack {
    private: 
        StackNode* top; 
        int size;     
    public: 
        TradeStack();
        ~TradeStack(); // frees all StackNodes

        void push(const TradeRecord& record);
        TradeRecord pop();
        TradeRecord peek() const;
        bool isEmpty() const;
        int  getSize() const;
        void printAll() const;  //top to bottom order
    };
}