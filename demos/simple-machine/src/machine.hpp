#include "behaviortree_cpp/bt_factory.h"

class Machine
{
public:
    void registerNodes(BT::BehaviorTreeFactory& factory);

    BT::NodeStatus isMachineReady();
    BT::NodeStatus isOrderReady();
    BT::NodeStatus fixIssue();

private:
    bool _isMachineReady = false;
    bool _isOrderReady = false;
};
