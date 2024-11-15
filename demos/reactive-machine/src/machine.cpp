#include "machine.hpp"

using namespace std::chrono_literals;

// ***************************************************************
// Condition
// ***************************************************************

BT::NodeStatus isMachineReady()
{
    std::this_thread::sleep_for(300ms);
    return RunState::_isMachineReady ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

// ***************************************************************
// Action
// ***************************************************************

BT::NodeStatus FixIssue::onStart()
{
    std::cout << "start fixing issue" << std::endl;
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(1);
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus FixIssue::onRunning()
{
    if(std::chrono::system_clock::now() >= completion_time)
    {
        RunState::_isMachineReady = true;
    }

    std::cout << "FixIssue " << std::flush;
    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}
