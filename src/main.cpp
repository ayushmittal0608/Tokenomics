#include "RaftNode.h"
#include "LedgerService.h"
#include "TokenomicsEngine.h"
#include "EventBus.h"
#include "QueryService.h"
#include "CommandService.h"

int main() {
    EventBus eventBus;
    QueryService queryService;
    eventBus.subscribe([&](const Transaction& tx) {
        queryService.handleEvent(tx);
    });
    TokenomicsEngine tokenEngine(&eventBus);
    RaftNode raft(1);
    LedgerService ledger(&raft, &tokenEngine);
    raft.setCommitCallback([&](const Transaction& tx) {
        ledger.onCommit(tx);
    });
    CommandService command(&ledger);
    Transaction tx = {"tx1", TxType::TRANSFER, "A", "B", 100, 10, 123456};
    command.transfer(tx);

    return 0;
}