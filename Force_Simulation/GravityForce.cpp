#include "GravityForce.h"

// Constructor implementation to set gravity components.
GravityForce::GravityForce(double gx, double gy) : gx(gx), gy(gy) {}

// Implement apply() to exert gravitational force on a particle.
void GravityForce::apply(Particle& particle, double dt) {
    particle.applyForce(particle.mass * gx, particle.mass * gy, dt);
}
