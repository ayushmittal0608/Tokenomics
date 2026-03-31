# pragma once
# include "RaftNode.h"
# include "TokenomicsEngine.h"

using namespace std;

class LedgerService{
    private:
        RaftNode* raftNode;
        TokenomicsEngine* tokenEngine;

    public:
        LedgerService(RaftNode* raft, TokenomicsEngine* tokenEngine);
        bool processTransaction(const Transaction& tx);
        void onCommit(const Transaction& tx);
}