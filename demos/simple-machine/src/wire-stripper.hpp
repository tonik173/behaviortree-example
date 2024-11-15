#include "common.h"

class WireStripper
{
public:
    void registerNodes(BT::BehaviorTreeFactory& factory);

    BT::NodeStatus isWireStripped();
    BT::NodeStatus stripWire();

private:
    bool _isWireStripped = false;
};
