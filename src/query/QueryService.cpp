void QueryService::handleEvent(const Transaction& tx) {
    if (tx.type == TxType::TRANSFER) {
        balances[tx.from] -= (tx.amount + tx.fee);
        balances[tx.to] += tx.amount;
    }
}