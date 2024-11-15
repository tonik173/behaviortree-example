#include "wire-drawer.hpp"

using namespace std::chrono_literals;

// ***************************************************************
// Condition
// ***************************************************************

BT::NodeStatus isWireDrawn()
{
    std::this_thread::sleep_for(300ms);
    return RunState::_wireDrawn ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

// ***************************************************************
// Action
// ***************************************************************

BT::NodeStatus DrawWire::onStart()
{
    completion_time = std::chrono::system_clock::now() + std::chrono::seconds(3);

    int slot;
    BT::Result result = getInput<int>("slot", slot);
    if (result)
        std::cout << "start drawing wire from slot " << slot << std::endl;
    else
        std::cout << "ERROR: getting slot failed" << std::endl; 

    return BT::NodeStatus::RUNNING;
}

BT::NodeStatus DrawWire::onRunning()
{
    if(std::chrono::system_clock::now() >= completion_time)
    {
        RunState::_wireDrawn = true;
    }

    std::cout << "draw wire " << std::flush;
    std::this_thread::sleep_for(300ms);
    return BT::NodeStatus::RUNNING;
}

void DrawWire::onHalted()
{
    std::cout << "wire drawing terminated " << std::endl;
}
    