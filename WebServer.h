#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

/**
 * @class WebServer
 * @brief Represents a web server that processes requests.
 */
class WebServer {
public:
    bool is_busy; ///< Indicates if the server is busy
    int timeLeft; ///< Time remaining to process the current request
    std::string ip_in, ip_out; ///< Ip in and out address of the current request

    /**
     * @brief Constructs a new WebServer object.
     */
    WebServer() : is_busy(false), timeLeft(0), ip_in(""), ip_out("") {}

    /**
     * @brief Processes a given request.
     * @param request The request to process.
     */
    void processRequest(Request& request) {
        is_busy = true;
        timeLeft = request.time;
        ip_in = request.ip_in;
        ip_out = request.ip_out;
    }

    /**
     * @brief Updates the server's remaining processing time.
     * @param clock_cycles The number of clock cycles to update.
     */
    void updateServerTime(int clock_cycles) {
        if (!is_busy) return;
        
        timeLeft -= clock_cycles;
        if (timeLeft <= 0) {
            is_busy = false;
            timeLeft = 0;
            ip_in = "";
            ip_out = "";
        }
    }
    
};

#endif // WEBSERVER_H