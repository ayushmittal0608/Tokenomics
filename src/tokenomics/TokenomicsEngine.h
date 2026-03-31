# pragma once
# include <bits/stdc++.h>
# include "Transaction.h"
# include "EventBus.h"

using namespace std;

class TokenomicsEngine{
    private:
        unordered_map<string, int> balances;
        int totalSupply=0;
        int treasury=0;
        double burnRate=0.4;
        double rewardRate=0.4;
        EventBus* eventBus;
    
    public:
        TokenomicsEngine(EventBus* bus);
        void applyTransaction(const Transaction& tx);

    private:
        void distributeFees(int fee);
};
