#pragma once
#include "LedgerService.h"

class CommandService {
private:
    LedgerService* ledger;

public:
    CommandService(LedgerService* l);
    bool transfer(const Transaction& tx);
};