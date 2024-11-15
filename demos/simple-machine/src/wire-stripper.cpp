#include "common.h"
#include "wire-stripper.hpp"

using namespace std::chrono_literals;
using BT::NodeStatus;

void WireStripper::registerNodes(BT::BehaviorTreeFactory &factory)
{
    factory.registerSimpleCondition("IsWireStripped", std::bind(&WireStripper::isWireStripped, this));
    factory.registerSimpleAction("StripWire", std::bind(&WireStripper::stripWire, this));
}

NodeStatus WireStripper::isWireStripped()
{
    std::this_thread::sleep_for(200ms);
    std::cout << "wire stripped: " << YES_NO(_isWireStripped) << std::endl;
    return _isWireStripped ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}

NodeStatus WireStripper::stripWire()
{
    std::cout << "stripping wire..." << std::endl;
    std::this_thread::sleep_for(3s);
    _isWireStripped = true;
    return _isWireStripped ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}
