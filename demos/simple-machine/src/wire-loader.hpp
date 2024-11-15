#include "common.h"

class WireLoader
{
public:
    void registerNodes(BT::BehaviorTreeFactory& factory);

    BT::NodeStatus isWireLoaded();
    BT::NodeStatus loadWire();

private:
    bool _isWireLoaded = false;
};
