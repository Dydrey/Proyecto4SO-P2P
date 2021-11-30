//
// Created by dydrey on 27/11/21.
//

#ifndef PROYECTO3SO_CLIENT_H
#define PROYECTO3SO_CLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>

struct Client
{
    //socket de red encargado de hacer la conexion
    int socket;
    //variables encargadas con las especificaciones de una conexion
    int domain;
    int protocol;
    int port;
    u_long interface;

    char * (*request)(struct Client *client, char *server_ip, char *request);
};

struct Client client_constructor(int domain, int service, int protocol, int port, u_long interface);
#endif //PROYECTO3SO_CLIENT_H
