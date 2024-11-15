#include "base-node.hpp"

BT::NodeStatus isMachineReady();

class FixIssue : public BaseStatefulActionNode
{
public:
    FixIssue(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
};
