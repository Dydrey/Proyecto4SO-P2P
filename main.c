//
// Created by dydrey on 27/11/21.
//
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "Server.h"
#include "Client.h"
#include <pthread.h>

void * server_function(void *arg)
{
    printf("El servidor esta corriendo... \n");
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 1248, 20);
    struct sockaddr * address = (struct sockaddr *)&server.address;
    socklen_t address_lenght = (socklen_t)sizeof(server.address);
    while(1)
    {
        int client = accept(server.socket, address, &address_lenght);
        char request[255];
        memset(request, 0, 255);
        read(client, request, 255);
        printf("%s\n", request);
        close(client);
    }
    return NULL;
}

void client_function(char *request)
{
    struct Client client = client_constructor(AF_INET, SOCK_STREAM, 0, 1248, INADDR_ANY);
    client.request(&client, "127.0.0.1", request);
}

int main()
{
    printf("Iniciando servidor...");
    pthread_t server_thread;
    pthread_create(&server_thread,  NULL, server_function, NULL);

    while(1)
    {
        char request[255];
        memset(request, 0, 255);
        fgets(request, 255, stdin);
        client_function(request);
    }
}