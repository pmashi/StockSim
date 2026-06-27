#pragma once 

#include "TradingStrategy.h"

namespace stocksim {
    class MomentumStrategy : public TradingStrategy {
    private: 

    public: 
        MomentumStrategy(); 
        ~MomentumStrategy(); 

        SimResult backtest(PriceHistory* history, double monthlyCapital, int startYear, int endYear) override; 
        string getName() const override; 
    };
}