void TokenomicsEngine::applyTransaction(const Transaction& tx){
    if(tx.type==TxType::TRANSFER){
        balances[tx.from]-=(tx.amount+tx.fee);
        balances[tx.to]+=tx.amount;
        distributeFees(tx.fee);
    }
    else if(tx.type==TxType::MINT){
        balances[tx.to]+=tx.amount;
        totalSupply+=tx.amount;
    }
    else if(tx.type==TxType::BURN){
        balances[tx.from]-=tx.amount;
        totalSupply-=tx.amount;
    }
    eventBus->publish(tx);
}
