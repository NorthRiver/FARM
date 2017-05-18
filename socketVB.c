// tcp_client.c

#include <unistd.h> /* read, write, close */
#include <netdb.h> /* struct hostent, gethostbyname */
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


int sock;


void error(const char *msg) { perror(msg); exit(0); }


void close_exit (int n) {
  /* Fermeture de la socket client */
  shutdown(sock, 2);
  close(sock);
  exit(0);
}

int main(void) {



	
    // COMMUNICATION SOCKET
    struct sockaddr_in sin;

    /* Rattraper le Ctrl-C */
    signal(SIGINT, close_exit);

    /* Creation de la socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);
   
    /* Configuration de la connexion */
    sin.sin_addr.s_addr = inet_addr("127.0.0.1"); // test avec le poste igtp5_pc09 / robot : 162.38.111.103
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
   
    /* Tentative de connexion au serveur */
    connect(sock, (struct sockaddr*)&sin, sizeof(sin));
    printf("\nConnexion a %s sur le port %d\n", inet_ntoa(sin.sin_addr),
           htons(sin.sin_port));
     printf("Récupération de l'identifiant du Robot et de l'identifiant du Ballon\n");


    /* Reception de donnees du serveur */
    char buffer[50] = "";
    recv(sock, buffer, 32, 0);
    printf("Reçu : %s\n", buffer);

    //décomposer les données en tokens
    char *tok = strtok(buffer, "/");
    printf("IDROBOT = %s\n", tok);
    char *idbut = tok;
    tok = strtok(NULL, "/");
    printf("IDBALLON = %s\n", tok);
    tok = strtok(NULL, "/");
    printf("COULBALLON = %s\n", tok);

    //imaginons qu'on a envoyé les ids au distributeur de ballon. 
    // Premier cas : les ids correspondent

    for(;;) {
      // Envoi de donnees au serveur 
      printf("Donnees a envoyer au serveur : ");
      fgets(buffer, 32, stdin);
      char *pos = strchr(buffer, '\n');
      *pos = '\0';
      send(sock, buffer, 32, 0);
      break;
    }//for
	
	// sendToBebotte
    
	
	char str[15];
  sprintf(str, "%d", cptmess);

  char mess3[40];
  mess3 = strcat("num=",str);
  char mess4[40];
  mess4 = strcat("data=",idbut);

	char *infoApublier[4]; // exemple de 4 infos a publier
    infoApublier[0] = "type_msg=IP";
    infoApublier[1] = "type_ent=VB";
    infoApublier[2] = "num=1";
    infoApublier[3] = "data=163.11.111.11";
    // (attention : strcpy(infoApublier[3],"data=163.11.111.11") 
    //    ne marche pas car pas d'espace memoire alloue encore a infoApublier[3] ) 

    
    // !! TO DO : mettre ici le nom du "channel" ou on veut envoyer des donneees
    char *channel = "testVB";
    /* Par convention dans FAR on parle sur ressource "msg"
      sur laquelle on envoie une chaine contenant les couples clef:valeur separes par des 			virgules */
    char *ressource = "msg"; 
    // !! TO DO : mettre ci-dessous le token du canal !!
    // canal partie0 : 1494793564147_KNl54g97mG89kQSZ
    // canal testVB : 1494771555601_5SGQdxJaJ8O1HBj4
    char *channelKey = "1494771555601_5SGQdxJaJ8O1HBj4";

    /* Envoie a BeeBotte en methode POST */
    sendToBeBotte(channel,channelKey,ressource,infoApublier);

	return EXIT_SUCCESS;
  }
  else {
    printf("Le Joueur n'existe pas pour cette partie.\n");
    return 0;
  }
}//main
