#include "common.h"
#include "machine.hpp"
#include "wire-loader.hpp"
#include "wire-drawer.hpp"
#include "wire-cutter.hpp"
#include "wire-stripper.hpp"

using namespace std::chrono_literals;

int main(int argc, char *argv[])
{
    // register the nodes
    BT::BehaviorTreeFactory factory;
    factory.registerSimpleCondition("IsMachineReady", std::bind(isMachineReady));
    factory.registerNodeType<FixIssue>("FixIssue");
    factory.registerSimpleCondition("IsWireLoaded", std::bind(isWireLoaded));
    factory.registerNodeType<MoveToSlot>("MoveToSlot");
    factory.registerNodeType<CloseWireDrive>("CloseWireDrive");
    factory.registerNodeType<ResetLoopFormer>("ResetLoopFormer");
    factory.registerNodeType<MoveShuttleToWireLoadPosition>("MoveShuttleToWireLoadPosition");
    factory.registerSimpleCondition("IsWireDrawn", std::bind(isWireDrawn));
    factory.registerNodeType<DrawWire>("DrawWire");
    factory.registerSimpleCondition("IsWireCut", std::bind(isWireCut));
    factory.registerNodeType<CutWire>("CutWire");
    factory.registerNodeType<OpenLoopGripper>("OpenLoopGripper");
    factory.registerNodeType<CloseShuttleGrippers>("CloseShuttleGrippers");
    factory.registerNodeType<MoveLeftShuttleGripperForward>("MoveLeftShuttleGripperForward");
    factory.registerNodeType<MoveLeftShuttleGripperBackward>("MoveLeftShuttleGripperBackward");
    factory.registerSimpleCondition("IsWireEndStripped", std::bind(isWireEndStripped));
    factory.registerNodeType<StripWireEnd>("StripWireEnd");

    // create the tree
    if (argc <= 1)
        factory.registerBehaviorTreeFromFile("./../_tree.xml");
    else 
    {
        std::cout << "loading behavior tree configuration from " << argv[1] << std::endl;
        factory.registerBehaviorTreeFromFile(argv[1]);
    }
    auto tree = factory.createTree("MainTree");
    BT::printTreeRecursively(tree.rootNode());
    BT::Groot2Publisher publisher(tree);

    // run the tree
    while (true)
    {
        RunState::reset();
        BT::NodeStatus status = BT::NodeStatus::IDLE;
        while(status != BT::NodeStatus::SUCCESS)
        {
            std::cout << "ticking: " << std::flush;
            status = tree.tickOnce();
            std::cout << "status: " << BT::toStr(status) << std::endl;

            if(status == BT::NodeStatus::RUNNING)
                tree.sleep(100ms);
        }

        std::cout << "============= RESTART WHOLE SEQUENCE " << std::endl;
    }

    return 0;
}