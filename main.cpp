#include <iostream>
#include "loadbalancer.h"

/**
 * @brief Main function to run the load balancer simulation.
 * @return Exit status of the program.
 */
int main() {
    srand(time(0)); 

    int num_servers;
    int simulation_time;

    std::cout << "Number of servers: ";
    std::cin >> num_servers;

    std::cout << "Simulation time (in clock cycles): ";
    std::cin >> simulation_time;

    LoadBalancer load_balancer(num_servers);

    for (int i = 0; i < num_servers * 100; ++i) 
        load_balancer.addRequest(Request());
    
    load_balancer.simulate(simulation_time);

    std::cout << "Simulation Done" << std::endl;

    return 0;
}
