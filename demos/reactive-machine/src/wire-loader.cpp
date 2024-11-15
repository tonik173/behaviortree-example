#include "wire-loader.hpp"
#include <stdlib.h>

using namespace std::chrono_literals;

// ***************************************************************
// Condition
// ***************************************************************

BT::NodeStatus isWireLoaded()
{
    std::this_thread::sleep_for(300ms);
    return RunState::_wireLoaded ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

// ***************************************************************
// Action MoveToSlot
// ***************************************************************

BT::NodeStatus MoveToSlot::onStart()
{
    std::cout << "start moving to slot " << std::endl;
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(3);
    srand((unsigned)time(0));
    _slot = (rand()%36)+1;
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus MoveToSlot::onRunning()
{
    if(std::chrono::system_clock::now() >= completion_time)
    {
        setOutput("slot", _slot);
        std::cout << "slot " << _slot << " reached" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    std::cout << "moving to slot " << _slot << " " << std::flush;
    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}

// ***************************************************************
// Action CloseWireDrive
// ***************************************************************

BT::NodeStatus CloseWireDrive::onStart()
{
    std::cout << "start closing wire drive " << std::endl;
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(3);
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus CloseWireDrive::onRunning()
{
    if(std::chrono::system_clock::now() >= completion_time)
    {
        RunState::_wireLoaded = true;
    }

    std::cout << "closing wire drive " << std::flush;
    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}

// ***************************************************************
// Action ResetLoopFormer
// ***************************************************************

BT::NodeStatus ResetLoopFormer::onStart()
{
    std::cout << "start rotating loop former to 0 " << std::endl;
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(3);
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus ResetLoopFormer::onRunning()
{
    if(std::chrono::system_clock::now() >= completion_time)
    {
        return BT::NodeStatus::SUCCESS;
    }

    std::cout << "rotating loop former " << std::flush;
    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}

// ***************************************************************
// Action MoveShuttleToWireLoadPosition
// ***************************************************************

BT::NodeStatus MoveShuttleToWireLoadPosition::onStart()
{
    std::cout << "start moving shuttle to wire load position " << std::endl;
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(3);
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus MoveShuttleToWireLoadPosition::onRunning()
{
    if(std::chrono::system_clock::now() >= completion_time)
    {
        return BT::NodeStatus::SUCCESS;
    }

    std::cout << "moving shuttle " << std::flush;
    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}