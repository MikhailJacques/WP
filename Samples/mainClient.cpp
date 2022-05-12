/*
 * mainClient.cpp
 *
 *  Created on: Nov 15, 2021
 *      Author: Eran Geva
 */

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>

#define PORT 5678

int main(int argc, char const *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    std::string reqJson = (std::string) "{" +
                          "\"obs\": \"../../../flights/viewpoint-dji/DJI_20201112190112_0001_S.MP4\"," +
                          "\"ref\": \"../../../flights/viewpoint_ply/lashabya_40m_w/ref_cropped.ply\"," +
                          "\"frames\": 50," +
                          "\"image-side\": 400," +
                          "\"max-features\": 1200" +
                          "}";
    send(sock, reqJson.c_str(), reqJson.size(), 0);
    printf("Json request sent\n");

    bool done = false;
    while (!done) {
        int valread = read(sock, buffer, 1024);
        if (valread == 0) break;
        if (valread < 0) {
            std::cout << "Socket error" << std::endl;
            break;
        }

        std::string got(buffer, valread);
        while (!done && got.size() > 0) {
            int pos = got.find('\n');
            std::string line = got.substr(0, pos);
            got = pos == -1 ? "" : got.substr(pos + 1);

            if (line.size() > 0) {
                std::cout << "Got: " << line << std::endl;
                done = (line == "Done.");
            }
        }
    }
    return 0;
}
