# pragma once
# include <bits/stdc++.h>
# include "Transaction.h"

using namespace std;

class EventBus {
    private:
        vector<function<void(const Transaction&)>> subscribers;

    public:
        void subscribe(function<void(const Transaction&)> handler);
        void publish(const Transaction& tx);
};