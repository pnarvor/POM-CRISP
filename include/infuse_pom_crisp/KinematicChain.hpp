#ifndef _DEF_POSITION_MANAGER_KINEMATIC_CHAIN_H_
#define _DEF_POSITION_MANAGER_KINEMATIC_CHAIN_H_

#include <iostream>
#include <list>

#include <infuse_pom_base/PositionManagerBase.hpp>

namespace PositionManager
{

class KinematicChain
{
    enum TransformType {NONE, FLOATING, FIXED};

    protected:

    std::list<const PositionManager::Transform*> _chain;
    std::list<PositionManager::Transform> _cachedFixedTransform;
    TransformType _lastInsertedType;

    mutable PositionManager::Pose _composed;

    public:

    KinematicChain(const PositionManager::FrameId& parent, const PositionManager::FrameId& child);

    void update() const;
    PositionManager::Pose getPose() const;
    PositionManager::FrameId getParent() const;
    PositionManager::FrameId getChild() const;

    void pushFixedTransform(const PositionManager::Transform& tr);
    void pushFloatingTransform(const PositionManager::Transform* tr);
};

};

#endif //_DEF_POSITION_MANAGER_KINEMATIC_CHAIN_H_