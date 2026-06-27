#pragma once 

#include "TradingStrategy.h"

namespace stocksim {
    class GoldenCrossStrategy : public TradingStrategy {
    private: 

    public: 
        GoldenCrossStrategy(); 
        ~GoldenCrossStrategy(); 

        SimResult backtest(PriceHistory* history, double monthlyCapital, int startYear, int endYear) override; 
        string getName() const override; 
    };
}