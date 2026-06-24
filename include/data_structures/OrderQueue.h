#pragma once

#include <string> 
using std::string; 

namespace stocksim {
    struct Order {
        string  ticker; 
        string  type;           // "MARKET" or "LIMIT"
        string  side;           // "BUY" or "SELL"
        double  targetPrice; 
        int     shares; 
        string  submittedDate; 
    };

    struct QueueNode {
        Order       data; 
        QueueNode*  next; 
    };

    class OrderQueue {
    private:
        QueueNode*  front; 
        QueueNode*  back; 
        int         size; 
    public: 
        OrderQueue(); 
        ~OrderQueue();
         
        void enqueue(const Order& order); 
        Order dequeue(); 
        Order peek() const; 
        bool isEmpty() const; 
        int getSize() const; 
        void printAll() const; // front to back 
    };
}