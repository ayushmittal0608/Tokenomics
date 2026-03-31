#pragma once
#include <bits/stdc++.h>
#include "Transaction.h"

using namespace std;

class QueryService {
private:
    unordered_map<string, int> balances;

public:
    void handleEvent(const Transaction& tx);
    int getBalance(const string& user);
};