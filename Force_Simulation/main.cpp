#include "Simulator.h"
#include "GravityForce.h"  // Include the specific header for gravity force

// Main function: sets up and runs the simulation.
int main() {
    Simulator sim;
    sim.addParticle(Particle(1.0, 0, 0, 10, 10)); // Adding a particle with initial position and velocity
    GravityForce* gravity = new GravityForce(0, -9.8); // Creating gravity force with Earth-like gravity
    sim.addForce(gravity); // Adding gravity to the simulation

    sim.runSimulation(10, 0.01); // Run the simulation for 10 seconds with 0.01s time step

    delete gravity; // Clean up dynamically allocated memory
    return 0;
}
