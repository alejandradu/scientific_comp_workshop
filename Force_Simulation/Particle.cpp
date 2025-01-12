#include "Particle.h"

// Constructor implementation.
Particle::Particle(double m, double posX, double posY, double velX, double velY)
    : mass(m), x(posX), y(posY), vx(velX), vy(velY) {}

// Method to update particle position based on its velocity and timestep.
void Particle::updatePosition(double dt) {
    x += vx * dt;
    y += vy * dt;
}

// Method to apply a force to the particle, changing its velocity.
void Particle::applyForce(double fx, double fy, double dt) {
    vx += (fx / mass) * dt;
    vy += (fy / mass) * dt;
}

// Computes and returns the kinetic energy of the particle.
double Particle::kineticEnergy() const {
    return 0.5 * mass * (vx * vx + vy * vy);
}
