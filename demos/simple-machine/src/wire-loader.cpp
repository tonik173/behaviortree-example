#include "common.h"
#include "wire-loader.hpp"

using namespace std::chrono_literals;
using BT::NodeStatus;

void WireLoader::registerNodes(BT::BehaviorTreeFactory &factory)
{
    factory.registerSimpleCondition("IsWireLoaded", std::bind(&WireLoader::isWireLoaded, this));
    factory.registerSimpleAction("LoadWire", std::bind(&WireLoader::loadWire, this));
}

NodeStatus WireLoader::isWireLoaded()
{
    std::this_thread::sleep_for(200ms);
    std::cout << "wire loaded: " << YES_NO(_isWireLoaded) << std::endl;
    return _isWireLoaded ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}

NodeStatus WireLoader::loadWire()
{
    std::cout << "loading wire..." << std::endl;
    std::this_thread::sleep_for(3s);
    _isWireLoaded = true;
    return _isWireLoaded ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
}
