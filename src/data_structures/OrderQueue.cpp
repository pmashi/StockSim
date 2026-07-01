#include "OrderQueue.h"
#include <iostream>

using namespace std; 

namespace stocksim {
    OrderQueue::OrderQueue()
    : front(nullptr), back(nullptr), size(0) {}


    OrderQueue::~OrderQueue() {
        while (!isEmpty()) dequeue();
    }

    //fix the pointers to enqueue to queue
    void OrderQueue::enqueue(const Order& order) {
        //new append
        QueueNode* newNode = new QueueNode;
        //populate with information
        newNode->data = order;
        newNode->next = nullptr;

        //empty then this is the first in order queue
        if (isEmpty()) {
            front = newNode;
            back = newNode;
        } else {
            //otherwise fix accordingly and attatch to end
            back->next = newNode;
            back = newNode;
        }

        //size of queue grows
        size++;
    }

    Order OrderQueue::dequeue() {
        //leave if the queue is empty
        if (isEmpty()) return Order();

        //get rid of oldest
        QueueNode* temp = front;    //temp node
        Order removed = front->data; //data of the dequeued node
        front = front->next;    //fix pointers, front is the following node
        delete temp;            //delete the front node

        size--;

        if (front == nullptr) back = nullptr;

        return removed;
    }

    Order OrderQueue::peek() const {
        if (isEmpty()) return Order();
        return front->data;
    }

    bool OrderQueue::isEmpty() const {
        return size == 0;
    }

    int OrderQueue::getSize() const {
        return size;
    }

    void OrderQueue::printAll() const {
        QueueNode* current = front;

        while (current != nullptr) {
            cout << current->data.ticker << " | " << current->data.type << " | " << current->data.side << " | " << current->data.shares << "\n";
            current = current->next;
        }
    }
}