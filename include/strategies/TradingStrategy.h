#pragma once 

#include "PriceHistory.h"
#include <vector> 
using std::vector; 

namespace stocksim {
    struct SimResult { 
        string strategyName; 
        double finalValue; 
        double totalInvested; 
        double totalReturn; 
        double cagr; 
        double maxDrawdown; 
        int totalTrades; 
    };
    
    class TradingStrategy { 
    private:
        virtual ~TradingStrategy(); 
        virtual SimResult backtest(PriceHistory* history, double monthlyCapital, int startYear, int endYear) = 0; 
        virtual string getName() const = 0; 

        void printResult(const SimResult& result) const; 

    protected: 
        double calculateCAGR(double startVal, double endVal, int years) const; 
        double calculateMaxDrawdown(const vector<double>& portfolioValues) const; 
    }; 
}