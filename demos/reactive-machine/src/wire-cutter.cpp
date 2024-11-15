#include "wire-cutter.hpp"
#include <stdlib.h>

using namespace std::chrono_literals;

// ***************************************************************
// Condition
// ***************************************************************

BT::NodeStatus isWireCut()
{
    std::this_thread::sleep_for(300ms);
    return RunState::_wireCut ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

// ***************************************************************
// Action CutWire
// ***************************************************************

BT::NodeStatus CutWire::onStart()
{
    std::cout << "start cutting wire" << std::endl;
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(3);
    srand((unsigned)time(0));
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    _length = r * 300.0 + 30.0;
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus CutWire::onRunning()
{
    if(std::chrono::system_clock::now() >= completion_time)
    {
        setOutput("length", _length);
        return BT::NodeStatus::SUCCESS;
    }

    std::cout << "cut wire at " << _length << "mm " << std::flush;
    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}

// ***************************************************************
// Action CloseShuttleGrippers
// ***************************************************************

BT::NodeStatus CloseShuttleGrippers::onStart()
{
    std::cout << "start closing shuttle grippers " << std::endl;
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(1);
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus CloseShuttleGrippers::onRunning()
{
    if(std::chrono::system_clock::now() >= completion_time)
    {
        return BT::NodeStatus::SUCCESS;
    }

    std::cout << "closing shuttle grippers " << std::flush;
    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}

// ***************************************************************
// Action OpenLoopGripper
// ***************************************************************

BT::NodeStatus OpenLoopGripper::onStart()
{
    std::cout << "start open loop gripper " << std::endl;
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(1);
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus OpenLoopGripper::onRunning()
{
    if(std::chrono::system_clock::now() >= completion_time)
    {
        return BT::NodeStatus::SUCCESS;
    }

    std::cout << "open loop gripper " << std::flush;
    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}

// ***************************************************************
// Action MoveLeftShuttleGripperForward
// ***************************************************************

BT::NodeStatus MoveLeftShuttleGripperForward::onStart()
{
    std::cout << "start move left shuttle gripper forward " << std::endl;
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(1);
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus MoveLeftShuttleGripperForward::onRunning()
{
    if(std::chrono::system_clock::now() >= completion_time)
    {
        return BT::NodeStatus::SUCCESS;
    }

    std::cout << "move left shuttle gripper forward " << std::flush;
    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}

// ***************************************************************
// Action MoveLeftShuttleGripperBackward
// ***************************************************************

BT::NodeStatus MoveLeftShuttleGripperBackward::onStart()
{
    std::cout << "start move left shuttle gripper backward " << std::endl;
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(1);
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus MoveLeftShuttleGripperBackward::onRunning()
{
    if(std::chrono::system_clock::now() >= completion_time)
    {
        RunState::_wireCut = true;
    }

    std::cout << "move left shuttle gripper backward " << std::flush;
    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}


    