#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <chrono>
#include "behaviortree_cpp/action_node.h"
#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/loggers/groot2_publisher.h"

#define YES_NO(x) (x ? "yes" : "no")

// use a blackboard 
class RunState
{
public:
    inline static bool _isMachineReady;
    inline static bool _wireCut;
    inline static bool _wireDrawn;
    inline static bool _wireLoaded;

    // use a custom decorator instead
    inline static bool _isWireEndStripped[2];
    inline static int _wireEnd;                   

    static void reset()
    {
        _isMachineReady = false;
        _wireCut = false;
        _wireDrawn = false;
        _wireLoaded = false;
        _wireEnd = 1;
        _isWireEndStripped[0] = false;
        _isWireEndStripped[1] = false;
    }
};

#endif