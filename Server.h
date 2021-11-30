//
// Created by dydrey on 27/11/21.
//

#ifndef PROYECTO3SO_SERVER_H
#define PROYECTO3SO_SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>

struct Server
{
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;
    int backlog;
    struct sockaddr_in address;
    int socket;
};

struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog);

#endif //PROYECTO3SO_SERVER_H
