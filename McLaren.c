#include <stdio.h>

int main() {
    float mass, velocity, kinetic_energy;

    // Ask the user for input
    printf("Enter the mass of the object (in kg): ");
    scanf("%f", &mass);

    printf("Enter the velocity of the object (in m/s): ");
    scanf("%f", &velocity);

    // Calculate kinetic energy
    kinetic_energy = 0.5 * mass * velocity * velocity;

    // Display the result
    printf("The kinetic energy of the object is: %.2f Joules\n", kinetic_energy);

    return 0;
}