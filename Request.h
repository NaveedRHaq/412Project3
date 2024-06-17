#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <cstdlib>
using namespace std;
/**
 * @class Request
 * @brief Represents a request with random IP addresses and a processing time.
 */
class Request {
public:
    std::string ip_in; ///< Incoming IP address
    std::string ip_out; ///< Outgoing IP address
    int time; ///< Time required to process the request

    /**
     * @brief Constructs a new Request object with random IP addresses and time.
     */
    Request() {
        ip_in = generateIP();
        ip_out = generateIP();
        time = rand() % 15 + 1; // Random time between 1 and 15
    }

private:
    /**
     * @brief Generates a random IP address.
     * @return A string representing a random IP address.
     */
string generateIP() {
        string IP = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." +  to_string(rand() % 256) + "." + to_string(rand() % 256);

        return IP;
    }
};

#endif // REQUEST_H
