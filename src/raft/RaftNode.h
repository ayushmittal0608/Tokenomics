# pragma once
#include <bits/stdc++.h>
#include "LogEntry.h"

using namespace std;

enum class State { FOLLOWER, CANDIDATE, LEADER };

class RaftNode{
    private:
        int id;
        int currentTerm;
        int votedFor;
        State state;
        vector<LogEntry>log;
        int commitIndex;

        function<void(const Transaction&)>onCommit;

    public:
        RaftNode(int nodeId);
        void setCommitCallback(function<void(const Transaction&)>cb);
        bool appendEntry(const Transaction& tx);
        void replicateLog();
        void applyCommitted();
};