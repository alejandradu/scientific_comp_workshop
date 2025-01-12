#include "Simulator.h"
#include <iostream>

// Adds a particle to the simulation.
void Simulator::addParticle(const Particle& particle) {
    particles.push_back(particle);
}

// Adds a force to the simulation.
void Simulator::addForce(Force* force) {
    forces.push_back(force);
}

// Simulates the particle dynamics over a specified time and timestep.
void Simulator::runSimulation(double time, double dt) {
    for (double t = 0; t < time; t += dt) {
        for (auto& particle : particles) {
            for (auto& force : forces) {
                force->apply(particle, dt);
            }
            particle.updatePosition(dt);
        }
        printState();
    }
}

// Prints the current state of each particle.
void Simulator::printState() const {
    for (const auto& particle : particles) {
        std::cout << "Particle at (" << particle.x << ", " << particle.y
                  << ") with KE=" << particle.kineticEnergy() << std::endl;
    }
}
