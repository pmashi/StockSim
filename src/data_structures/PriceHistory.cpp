#include "data_structures/PriceHistory.h"

#include <iostream> 
#include <iomanip>

using std::cout;

namespace stocksim { 
    PriceHistory::PriceHistory() : head(nullptr), tail(nullptr), size(0) {}
    
    PriceHistory::~PriceHistory() { 
        PriceNode* current = head; 
        while(current != nullptr) { 
            PriceNode* next = current->next; 
            delete current; 
            current = next; 
        }
        head = tail = nullptr;
        size = 0;  
    }

    void PriceHistory::append(const string& date, double open, double high, double low, double close, long volume) {
        // create new node
        PriceNode* node = new PriceNode(date, open, high, low, close, volume); 
        if(tail == nullptr) {       // if list is empty
            head = node;            
            tail = node; 
        } else {                    // appends to end of the DLL 
            node->prev = tail;      // former tail is behind new node
            tail->next = node;      // former tail points to ne wnode
            tail = node;            // tail is now new node 
        }
        size++;                     // increase list size accordingly 
    }

    PriceNode* PriceHistory::findByDate(const string& date) const { 
        PriceNode* current = head; 
        while(current != nullptr) { 
            if(current->date == date) return current; 
            current = current -> next; 
        }
        return nullptr; // no node found
    }

    void PriceHistory::printRange(const string& startDate, const string& endDate) const { 
        if(head == nullptr) { 
            std::cout << "[PriceHistory] No data available.\n";
            return; 
        }

        cout << std::left
         << std::setw(12) << "Date"
         << std::setw(10) << "Open"
         << std::setw(10) << "High"
         << std::setw(10) << "Low"
         << std::setw(10) << "Close"
         << std::setw(14) << "Volume"
         << "\n";
        cout << string(66, '-') << "\n";

        int printed = 0;
        PriceNode* current = head;
        while (current != nullptr) {
            //YYYY-MM-DD
            if (current->date >= startDate && current->date <= endDate) {
                cout << std::left
                    << std::setw(12) << current->date
                    << std::fixed << std::setprecision(2)
                    << std::setw(10) << current->open
                    << std::setw(10) << current->high
                    << std::setw(10) << current->low
                    << std::setw(10) << current->close
                    << std::setw(14) << current->volume
                    << "\n";
                printed++;
            }
            if (current->date > endDate) break;
            current = current->next;
        }

        if (printed == 0) {
            cout << "  No trading days found in range " << startDate << " to " << endDate << "\n";
        } else {
            cout << "  " << printed << " trading day(s) displayed.\n";
        }
    }

    int PriceHistory::getSize() const { 
        return size; 
    }

    /**
     * Iterator Class Implementation 
     */
    PriceHistory::Iterator::Iterator(PriceNode* node) : current(node) {}

    PriceHistory::Iterator& PriceHistory::Iterator::operator++() { 
        if(current != nullptr) current = current-> next; 
        return *this; 
    }

    PriceNode& PriceHistory::Iterator::operator*() const { 
        return *current; 
    }

    bool PriceHistory::Iterator::operator!=(const Iterator& other) const { 
        return current != other.current; 
    }

    PriceHistory::Iterator PriceHistory::begin() const { 
        return Iterator(head); 
    }
    
    PriceHistory::Iterator PriceHistory::end() const { 
        return Iterator(nullptr);
    }
    /**
     * Reverse Iterator Class Implementation 
     */
    PriceHistory::ReverseIterator::ReverseIterator(PriceNode* node) : current(node) {}

    PriceHistory::ReverseIterator& PriceHistory::ReverseIterator::operator++() { 
        if(current != nullptr) current = current->prev; 
        return *this; 
    }

    PriceNode& PriceHistory::ReverseIterator::operator*() const { 
        return *current; 
    }

    bool PriceHistory::ReverseIterator::operator!=(const ReverseIterator& other) const { 
        return current != other.current; 
    }

    PriceHistory::ReverseIterator PriceHistory::rbegin() const { 
        return ReverseIterator(tail); 
    }
    
    PriceHistory::ReverseIterator PriceHistory::rend() const { 
        return ReverseIterator(nullptr); 
    }
}