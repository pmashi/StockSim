#pragma once

#include "FinancialAsset.h"
#include "PriceHistory.h"

namespace stocksim {
    class Stock : public FinancialAsset {
    private:
        PriceHistory* priceHistory;

    public: 
        Stock(const string& ticker, const string& name); 
        ~Stock();

        void loadFromCSV(const string& filename); 
        PriceHistory* getHistory() const; 
        double getPriceOnDate(const string& date) const; 
        double calculateAnnualReturn(int year) const override; //(end_price - start_price) /start_price * 100
        void printSummary() const override; // print ticker, date range, total return, number of trading days
        string getType() const override; // returns "Stock"
    };
}