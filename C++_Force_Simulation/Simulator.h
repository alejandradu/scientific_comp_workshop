#pragma once
#include <vector>
#include "Particle.h"
#include "Force.h"

// Class to simulate physics interactions over time.
class Simulator {
    std::vector<Particle> particles;  // List of particles in the simulation
    std::vector<Force*> forces;       // List of forces acting on the particles

public:
    // Adds a particle to the simulation.
    void addParticle(const Particle& particle);

    // Adds a force to act on the particles.
    void addForce(Force* force);

    // Runs the simulation for a given time with a specific timestep.
    void runSimulation(double time, double dt);

    // Prints the current state of all particles in the simulation.
    void printState() const;
};
