bool LedgerService::processTransaction(const Transaction& tx) {
    return raftNode->appendEntry(tx);
}

void LedgerService::onCommit(const Transaction& tx) {
    tokenEngine->applyTransaction(tx);
}