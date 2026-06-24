#pragma once 

namespace stocksim {
    class CircularQueue {
    private: 
        double* buffer; 
        int     capacity; 
        int     head; 
        int     tail; 
        int     count; 
        double  sum; 
    public: 
        CircularQueue(int capacity); 
        ~CircularQueue(); 

        void enqueue(double value);
        double dequeue(); 

        double peek() const; 

        double getAverage() const; 

        bool isFull() const; 
        bool isEmpty() const; 

        int getCount() const; 
        int getCapacity() const; 
    };
}