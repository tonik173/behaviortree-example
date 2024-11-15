#include "common.h"
#include "machine.hpp"
#include "wire-loader.hpp"
#include "wire-drawer.hpp"
#include "wire-cutter.hpp"
#include "wire-stripper.hpp"

int main(int argc, char *argv[])
{
    BT::BehaviorTreeFactory factory;

    Machine machine;
    machine.registerNodes(factory);

    WireLoader wireLoader;
    wireLoader.registerNodes(factory);
    
    WireDrawer wireDrawer;
    wireDrawer.registerNodes(factory);

    WireStripper wireStripper;
    wireStripper.registerNodes(factory);

    WireCutter wireCutter;
    wireCutter.registerNodes(factory);

    if (argc <= 1)
        factory.registerBehaviorTreeFromFile("./../_tree.xml");
    else 
    {
        std::cout << "loading behavior tree configuration from " << argv[1] << std::endl;
        factory.registerBehaviorTreeFromFile(argv[1]);
    }
    auto tree = factory.createTree("MainTree");

    BT::printTreeRecursively(tree.rootNode());

    tree.tickWhileRunning();

    return 0;
}