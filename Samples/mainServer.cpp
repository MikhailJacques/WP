/*
 * mainServer.cpp
 *
 *  Created on: Nov 15, 2021
 *      Author: Eran Geva
 */

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <chrono>
#include <iostream>
#include <thread>

#include "Viewpoint.h"

#define PORT 5678

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    std::cout << "Awake." << std::endl;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (true) {
        std::cout << "Waiting for connection." << std::endl;
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        std::cout << "Waiting for requests." << std::endl;
        valread = read(new_socket, buffer, 1024);
        if (valread < 0) {
            perror("socket read");
            exit(EXIT_FAILURE);
        }
        if (valread == 0) {
            sleep(1);
            continue;
        }
        std::string got(buffer, valread);
        printf("Got: %s\n", buffer);

        Viewpoint::Viewpoint viewpoint([&](const std::string &dataRaw) {
            auto data = dataRaw + "\n";
            send(new_socket, data.c_str(), data.length(), 0);
        });

        Viewpoint::Args args;
        args.parseJson(buffer);
        viewpoint.go(args);

        std::string done = "Done.";
        send(new_socket, done.c_str(), done.length(), 0);

        close(new_socket);
    }

    return 0;
}
