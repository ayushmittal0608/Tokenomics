void eventBus::publish(const Transaction& tx){
    for(auto& sub:subscribers){
        sub(tx);
    }
}