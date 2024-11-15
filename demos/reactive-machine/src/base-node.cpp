#include "base-node.hpp"

using namespace std::chrono_literals;

BaseStatefulActionNode::BaseStatefulActionNode(const std::string& name, const BT::NodeConfiguration& config)
    : StatefulActionNode(name, config)
{
}

BT::NodeStatus BaseStatefulActionNode::onStart()
{
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(3);
    return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus BaseStatefulActionNode::onRunning()
{
    return BT::NodeStatus::RUNNING;
}
    
void BaseStatefulActionNode::onHalted()
{
}


BaseSyncActionNode::BaseSyncActionNode(const std::string& name, const BT::NodeConfiguration& config)
    : SyncActionNode(name, config)
{
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(5);
}

BT::NodeStatus BaseSyncActionNode::tick()
{
    return BT::NodeStatus::RUNNING;
}