bool CommandService::transfer(const Transaction& tx) {
    return ledger->processTransaction(tx);
}