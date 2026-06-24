#pragma once 

#include <vector> 
#include <algorithm>
#include <iostream> 
#include "FinancialAsset.h"

using std::vector;
using std::cout;

namespace stocksim {
    template <typename T> 
    class StockManager {
    private:
        vector<T*> assets; 
    public: 
        void addAsset(T* asset); 
        void removeAsset(const string& ticker);
        T* findByTicker(const string& ticker); 
        void sortByAnnualReturn(int year); // sort assets vector by calculateAnnualReturn(year)
        void sortByTicker(); 
        void printAll() const; 
        int getCount() const; 
        ~StockManager(); 
    };

    template<typename T> 
    void StockManager<T>::addAsset(T* asset) {
        if (asset != nullptr) {
            assets.push_back(asset);
        }
    } 

    template<typename T> 
    void StockManager<T>::removeAsset(const string& ticker) {
        for (int i = 0; i < static_cast<int>(assets.size()); i++) { 
            if(assets[i]->getTicker() == ticker) {      // getTicker is a function in FinancialAsset since StockManager will take the Stock/ETF type
                delete assets[i]; 
                assets.erase(assets.begin() + i); 
                return; 
            }
        } 
        cout << "[StockManager] Ticker not found: " << ticker << "\n"; 
    }

    template<typename T> 
    T* StockManager<T>::findByTicker(const string& ticker) {
        for (int i = 0; i < static_cast<int>(assets.size()); i++) {
            if(assets[i]->getTicker() == ticker) {
                return assets[i];
            }
        }
        return nullptr; 
    }

    template<typename T> 
    void StockManager<T>::sortByAnnualReturn(int year) {
        std::sort(assets.begin(), assets.end(), 
            [year](T* a, T* b) {
                FinancialAsset* fa = static_cast<FinancialAsset*>(a); 
                FinancialAsset* fb = static_cast<FinancialAsset*>(b);
                return fa->calculateAnnualReturn(year) > fb->calculateAnnualReturn(year);  
            })
    }
    
    template<typename T> 
    void StockManager<T>::sortByTicker() {
        std::sort(assets.begin(), assets.end(), [](T* a, T* b) {
                return a->getTicker() < b->getTicker();
            });
    }
    
    template<typename T> 
    void StockManager<T>::printAll() const { 
        if (assets.empty()) {
            cout << "[StockManager] No assets loaded.\n";
            return;
        }
        for (int i = 0; i < static_cast<int>(assets.size()); i++) assets[i]->printSummary();
    }
    
    template<typename T> 
    int StockManager<T>::getCount() const {
        return static_cast<int>(assets.size());
    }
    
    template<typename T> 
    StockManager<T>::~StockManager() { 
        for (int i = 0; i < static_cast<int>(assets.size()); i++) delete asset[i];
        assets.clear(); 
    }
}

