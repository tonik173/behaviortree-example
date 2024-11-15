#include "common.h"
#include "wire-drawer.hpp"

using namespace std::chrono_literals;
using BT::NodeStatus;

void WireDrawer::registerNodes(BT::BehaviorTreeFactory &factory)
{
    factory.registerSimpleCondition("IsWireDrawn", std::bind(&WireDrawer::isWireDrawn, this));
    factory.registerSimpleAction("DrawWire", std::bind(&WireDrawer::drawWire, this));
}

NodeStatus WireDrawer::isWireDrawn()
{
    std::this_thread::sleep_for(200ms);
    std::cout << "wire drawn: " << YES_NO(_isWireDrawn) << std::endl;
    return _isWireDrawn ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}

NodeStatus WireDrawer::drawWire()
{
    std::cout << "drawing wire..." << std::endl;
    std::this_thread::sleep_for(3s);
    _isWireDrawn = true;
    return _isWireDrawn ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}
