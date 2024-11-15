#include "wire-stripper.hpp"

using namespace std::chrono_literals;

// ***************************************************************
// Condition
// ***************************************************************

BT::NodeStatus isWireEndStripped()
{
    std::this_thread::sleep_for(300ms);
    return RunState::_isWireEndStripped[0] && RunState::_isWireEndStripped[1] 
        ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

// ***************************************************************
// Action
// ***************************************************************

BT::NodeStatus StripWireEnd::onStart()
{
    // onStart is called once, independent of the cycles of the repeater
    std::cout << "start stripping wire end " << std::endl;
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(3);
    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus StripWireEnd::onRunning()
{
    std::cout << "stripping wire end " << RunState::_wireEnd << " " << std::flush;

    if(std::chrono::system_clock::now() >= completion_time)
    {
        RunState::_isWireEndStripped[RunState::_wireEnd-1] = true;
        RunState::_wireEnd++;

        // restarts timer
        completion_time = std::chrono::system_clock::now() + std::chrono::seconds(3);
    }

    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}
