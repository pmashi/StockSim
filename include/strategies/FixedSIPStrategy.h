#pragma once 

#include "TradingStrategy.h"

namespace stocksim {
    class FixedSIPStrategy : public TradingStrategy {
    private: 

    public: 
        FixedSIPStrategy(); 
        ~FixedSIPStrategy(); 

        SimResult backtest(PriceHistory* history, double monthlyCapital, int startYear, int endYear) override; 
        string getName() const override; 
    };
}