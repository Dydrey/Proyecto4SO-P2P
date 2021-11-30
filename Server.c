//
// Created by dydrey on 27/11/21.
//
#include "Server.h"

#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog){
    struct Server server;
    //parametros del servidor
    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.interface = interface;
    server.port = port;
    server.backlog = backlog;
    //se construye la direccion del server
    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(interface);
    //se crea socket del server
    server.socket = socket(domain, service, protocol);
    if(server.socket == 0)
    {
        perrror("Conexion con socket fallida...\n");
        exit(1);
    }
    if((bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address))) < 0)
    {
        perror("Fallo vinculando el socket...\n");
        exit(1);
    }
    if(listen(server.socket, server.backlog) < 0)
    {
        perror("Fallo para comenzar a escuchar...\n");
        exit(1);
    }
    return server;
}
