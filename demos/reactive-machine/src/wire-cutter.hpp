#include "base-node.hpp"

BT::NodeStatus isWireCut();

class CutWire : public BaseStatefulActionNode
{
public:
    CutWire(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { BT::OutputPort<double>("length") };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
    
private:
    float _length;
};

class CloseShuttleGrippers : public BaseStatefulActionNode
{
public:
    CloseShuttleGrippers(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
};

class OpenLoopGripper : public BaseStatefulActionNode
{
public:
    OpenLoopGripper(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
};

class MoveLeftShuttleGripperForward : public BaseStatefulActionNode
{
public:
    MoveLeftShuttleGripperForward(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
};

class MoveLeftShuttleGripperBackward : public BaseStatefulActionNode
{
public:
    MoveLeftShuttleGripperBackward(const std::string& name, const BT::NodeConfiguration& config)
      : BaseStatefulActionNode(name, config)
    { }

    static BT::PortsList providedPorts()
    {
        return { };
    }

    virtual BT::NodeStatus onStart() override;
    BT::NodeStatus onRunning() override;
};


