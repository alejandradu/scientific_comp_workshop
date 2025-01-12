#pragma once
#include "Particle.h"

// Abstract base class for forces acting on particles.
class Force {
public:
    virtual void apply(Particle& particle, double dt) = 0;
};
