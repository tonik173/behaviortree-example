#include "base-node.hpp"

BT::NodeStatus isWireLoaded();

class MoveToSlot : public BaseStatefulActionNode
{
public:
    MoveToSlot(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { BT::OutputPort<int>("slot") };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;

private:
    int _slot;
};

class CloseWireDrive : public BaseStatefulActionNode
{
public:
    CloseWireDrive(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
};

class ResetLoopFormer : public BaseStatefulActionNode
{
public:
    ResetLoopFormer(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
};

class MoveShuttleToWireLoadPosition : public BaseStatefulActionNode
{
public:
    MoveShuttleToWireLoadPosition(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
};