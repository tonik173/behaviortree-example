#include "base-node.hpp"

BT::NodeStatus isWireDrawn();

class DrawWire : public BaseStatefulActionNode
{
public:
    DrawWire(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { BT::InputPort<int>("slot") };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
    void onHalted() override;
};
