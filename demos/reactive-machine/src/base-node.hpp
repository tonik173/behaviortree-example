#ifndef BASE_NODE_H
#define BASE_NODE_H

#include "common.h"

class BaseStatefulActionNode : public BT::StatefulActionNode
{
public:
    BaseStatefulActionNode(const std::string& name, const BT::NodeConfiguration& config);

    BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
    void onHalted() override;

protected:
    std::chrono::system_clock::time_point completion_time;
};


class BaseSyncActionNode : public BT::SyncActionNode
{
public:
    BaseSyncActionNode(const std::string& name, const BT::NodeConfiguration& config);

    BT::NodeStatus tick() override;

protected:
    std::chrono::system_clock::time_point completion_time;
};

#endif