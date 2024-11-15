#include "common.h"

class WireCutter
{
public:
    void registerNodes(BT::BehaviorTreeFactory& factory);

    BT::NodeStatus isWireCut();
    BT::NodeStatus cutWire();

private:
    bool _isWireCut = false;
};
