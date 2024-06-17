#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <queue>
#include <iostream>
#include "WebServer.h"
#include <fstream>
using namespace std;

/**
 * @class LoadBalancer
 * @brief Manages a pool of web servers and a queue of requests.
 */
class LoadBalancer {
private:
    std::vector<WebServer> servers; ///< Vector of web servers
    std::queue<Request> request_queue; ///< Queue of requests
    int currTime; ///< Current time in the simulation
    std::ofstream log; ///< Log file for simulation status

public:
    /**
     * @brief Constructs a new LoadBalancer object.
     * @param num_servers The number of web servers to initialize.
     */
    LoadBalancer(int num_servers) : currTime(0) {
        for (int i = 0; i < num_servers; ++i) {
            servers.push_back(WebServer());
        }
        log.open("simulation_log.txt");
    }

    /**
     * @brief Destroys the LoadBalancer object and closes the log file.
     */
    ~LoadBalancer() {
        if (log.is_open()) {
            log.close();
        }
    }

    /**
     * @brief Adds a new request to the request queue.
     * @param request The request to add.
     */
    void addRequest(Request request) {
        request_queue.push(request);
    }

    /**
     * @brief Balances the load among available web servers.
     */
    void balanceLoad() {
        for (auto& server : servers) {
            if (!server.is_busy && !request_queue.empty()) {
                server.processRequest(request_queue.front());
                request_queue.pop();
            }
        }
    }

    /**
     * @brief Simulates the load balancing process for a given number of clock cycles. 
     * @param total_cycles The total number of clock cycles to simulate.
     */
    void simulate(int total_cycles) {
        for (int i = 0; i < total_cycles; ++i) {
            currTime++;
            balanceLoad();
            for (WebServer &server : servers) {
                server.updateServerTime(1);
            }
            if (rand() % 10 < 2) { 
                addRequest(Request());
                log << "Random Request Added" << std::endl;
            }
            logStatus();
        }
    }

    /**
     * @brief Logs the current status of the load balancer.
     */
    void logStatus() {
        log << "Time: " << currTime << std::endl;
        log << "Request Queue Size: " << request_queue.size() << std::endl;
        for (size_t i = 0; i < servers.size(); ++i) {
            log << "Server " << i << " - " << (servers[i].is_busy ? "Busy" : "Available");
            log << ", Remaining Time: " << servers[i].timeLeft;
            if (servers[i].is_busy) {
                log << " || " << servers[i].ip_in << " -> " << servers[i].ip_out;
            }
            log << std::endl;
        }
        log << "------------------------------------------" << std::endl;
    }
};

#endif 