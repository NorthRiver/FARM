#include "socket.h"

#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PORT 10000



char * socketRecupRobot(char * ip) {
	int sock;
	
    // COMMUNICATION SOCKET
    struct sockaddr_in sin;

    /* Creation de la socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);
   
    /* Configuration de la connexion */
    sin.sin_addr.s_addr = inet_addr(ip);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
   	printf("Tentative de connexion\n");
    /* Tentative de connexion au serveur */
    connect(sock, (struct sockaddr*)&sin, sizeof(sin));
    printf("\nConnexion a %s sur le port %d\n", inet_ntoa(sin.sin_addr),htons(sin.sin_port));
     printf("Get informations du robot\n");


    /* Reception de donnees du serveur */
    char buffer[50] = "";
    recv(sock, buffer, 32, 0);
    printf("Reçu : %s\n", buffer);
    char * res = malloc(50*sizeof(char));
    strcpy(res, buffer);
    return res;
}