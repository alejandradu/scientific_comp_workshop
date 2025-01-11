#pragma once
#include <iostream>

// Class that represents a particle with mass, position, and velocity.
class Particle {
public:
    double mass;   // Mass of the particle
    double x, y;   // Position coordinates
    double vx, vy; // Velocity components

    // Constructor initializes particle properties.
    Particle(double m, double posX, double posY, double velX, double velY);

    // Updates the position based on velocity and timestep.
    void updatePosition(double dt);

    // Applies a force to the particle, updating its velocity.
    void applyForce(double fx, double fy, double dt);

    // Calculates and returns the kinetic energy of the particle.
    double kineticEnergy() const;
};
