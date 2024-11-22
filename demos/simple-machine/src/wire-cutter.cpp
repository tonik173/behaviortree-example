#include "common.h"
#include "wire-cutter.hpp"

using namespace std::chrono_literals;

void WireCutter::registerNodes(BT::BehaviorTreeFactory &factory)
{
    factory.registerSimpleCondition("IsWireCut", std::bind(&WireCutter::isWireCut, this));
    factory.registerSimpleAction("CutWire", std::bind(&WireCutter::cutWire, this));
}

BT::NodeStatus WireCutter::isWireCut()
{
    std::this_thread::sleep_for(200ms);
    std::cout << "wire cut: " << YES_NO(_isWireCut) << std::endl;
    return _isWireCut ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

BT::NodeStatus WireCutter::cutWire()
{
    std::cout << "cutting wire..." << std::endl;
    std::this_thread::sleep_for(3s);
    _isWireCut = true;
    return _isWireCut ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}
