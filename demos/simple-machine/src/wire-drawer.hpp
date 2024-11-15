#include "common.h"

class WireDrawer
{
public:
    void registerNodes(BT::BehaviorTreeFactory& factory);

    BT::NodeStatus isWireDrawn();
    BT::NodeStatus drawWire();

private:
    bool _isWireDrawn = false;
};
