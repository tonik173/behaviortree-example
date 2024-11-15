#include "base-node.hpp"

BT::NodeStatus isWireEndStripped();

class StripWireEnd : public BaseStatefulActionNode
{
public:
    StripWireEnd(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { BT::InputPort<int>("num_cycles") };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
};
