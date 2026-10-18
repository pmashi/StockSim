#pragma once 

#include "TradingStrategy.h"

namespace stocksim {
    class DynamicSIPStrategy : public TradingStrategy {
    private:

    public:
        DynamicSIPStrategy();
        ~DynamicSIPStrategy();

        SimResult backtest(PriceHistory* history, double monthlyCapital, int startYear, int endYear) override;
        string getName() const override;
    };
}