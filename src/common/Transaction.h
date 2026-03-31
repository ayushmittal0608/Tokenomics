# pragma once
# include <string>

using namespace std;

enum class TxType{
    TRANSFER,
    MINT, 
    BURN, 
    STAKE
}

struct Transaction{
    string txId;
    TxType type;
    string from;
    string to;
    int amount;
    int fee;
    long timestamp;
}