# pragma once
# include <Transaction.h>

using namespace std;

struct LogEntry{
    int term;
    Transaction tx;
}