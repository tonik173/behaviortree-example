#include "common.h"
#include "machine.hpp"

using namespace std::chrono_literals;
using BT::NodeStatus;

void Machine::registerNodes(BT::BehaviorTreeFactory &factory)
{
    factory.registerSimpleCondition("IsMachineReady", std::bind(&Machine::isMachineReady, this));
    factory.registerSimpleCondition("IsOrderReady", std::bind(&Machine::isOrderReady, this));
    factory.registerSimpleAction("FixIssue", std::bind(&Machine::fixIssue, this));
}

NodeStatus Machine::isMachineReady()
{
    std::this_thread::sleep_for(200ms);
    std::cout << "machine ready: " << YES_NO(_isMachineReady) << std::endl;
    return _isMachineReady ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}

NodeStatus Machine::isOrderReady()
{
    std::this_thread::sleep_for(200ms);
    std::cout << "order ready " << YES_NO(_isOrderReady) << std::endl;
    std::this_thread::sleep_for(2s);
    std::cout << "waiting for order " << std::endl;

    return NodeStatus::SUCCESS;
}

NodeStatus Machine::fixIssue()
{
    std::cout << "fixing issue..." << std::endl;
    std::this_thread::sleep_for(3s);
    _isMachineReady = true;
    return NodeStatus::SUCCESS;
}
