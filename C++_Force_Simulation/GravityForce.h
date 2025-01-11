#pragma once
#include "Force.h"

// Concrete class for gravitational force, derived from Force.
class GravityForce : public Force {
    double gx, gy; // Gravitational acceleration components (e.g., gx = 0, gy = -9.81 for Earth gravity on y-axis)

public:
    // Constructor to initialize gravity components.
    GravityForce(double gx, double gy);

    // Overridden method to apply gravitational force to a particle.
    void apply(Particle& particle, double dt) override;
};
