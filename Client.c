//
// Created by dydrey on 27/11/21.
//

#include "Client.h"

#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

char * request(struct Client *client, char *server_ip, char *request);

struct Client client_constructor(int domain, int service, int portocol, int port, ulong interface)
{
    //se instancia el objeto cliente
    struct Client client;
    client.domain = domain;
    client.port = port;
    client.interface = interface;
    //se establece la conexion con el socket
    client.socket = socket(domain, service, protocol);
    client.request = request;
    //return del socket construido
    return client;
}

char * request(struct Client *client, chat *server_ip, char *request)
{
    //se crea struct del server
    struct sockaddr_in server_address;
    //se copian los parametros del cliente al address
    server_address.sin_family = client->domain;
    server_address.sin_port = htons(client->port);
    server_address.sin_addr.s_addr = (int)client->interface;
    //se hace la conexion
    inet_pton(client->domain, server_ip, &server_address.sin_addr);
    connect(client->socket, (struct sockaddr*)&server_address, sizeof(server_address));
    //se envia el request
    send(client->socket, request, strlen(request), 0);
    //se lee la respuesta
    char *response = malloc(30000);
    read(client->socket, response, 30000);
    return response;
}
