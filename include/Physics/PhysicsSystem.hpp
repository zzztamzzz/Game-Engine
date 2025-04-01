#pragma once

#include <memory>
#include <vector>
#include "Vector4D.hpp"
// #include "PhysicsBody.hpp" // need to set up a body for physics to apply on
// #include "Collider.hpp" // collisions happen on physics bodies

class PhysicsSystem {
    public:
        virtual ~PhysicsSystem() = default;

        virtual void Initialize() = 0;
        virtual void Update(float deltaTime) = 0;
        // need body instance reference to apply forces to
        // need to be able to remove a physics body

        // default physics and time properties
        void SetGravity(const Vector4D& gravity) {this->gravity = gravity;};
        void SetTimeScale(float scale) {timeScale = scale;};

    protected:
    Vector4D gravity;
    float timeScale = 1.0f; // default time scale is 1.0f
    // instantiate bodies here

    virtual void IntegratedForces(float deltaTime) = 0; // apply forces over time
    
    // what collisions are happening, where and how to resolve them
    virtual void DetectCollisions() = 0;
    virtual void ResolveCollisions() = 0;
};

// 4D dimensional stuff. this is gonna be great :)
class Physics2D: public PhysicsSystem{

};

class Physics3D: public PhysicsSystem{

};

class Physics4D: public PhysicsSystem{

};