#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



int sock;

void Error(char *mess)
{
  fprintf(stderr,"%s\n",mess);
  if (sock) close(sock);
  exit(-1);
}

void GetData(char host[], int port, char file[]){
  /* Calcul de l'IP de l'hote */
  struct hostent *hostinfo;
  hostinfo = gethostbyname(host);
  if (hostinfo) {
    struct in_addr  **pptr;
    pptr = (struct in_addr **)hostinfo->h_addr_list;
    printf("Adresse IP de l'hote : %s\n",inet_ntoa(**(pptr)));
  }

  /* Creation de la socket */
  if ( (sock = socket(AF_INET, SOCK_STREAM, 0)) <0 )
    Error("can't create socket");

  /* Configuration de la connexion */

  struct sockaddr_in sin;

  sin.sin_addr = *(struct in_addr *) hostinfo->h_addr;
  sin.sin_family = AF_INET;
  if ( (sin.sin_port = htons(port)) == 0)
    Error("unknown service");

  /* Tentative de connexion au serveur */
  if (connect(sock, (struct sockaddr*)&sin,sizeof(sin))<0)
    Error("can't connect");
  else printf("Connexion a %s sur le port %d\n", inet_ntoa(sin.sin_addr),
         htons(sin.sin_port));


    //Envoi de donnees au serveur
  char buffer[1024] = "GET ";
  strcat(buffer, file);
  strcat(buffer, " HTTP/1.0\r\n");
  strcat(buffer, "Host: ");
  strcat(buffer, host);
  strcat(buffer, "\r\n\r\n");
  printf("Requete : \n%s", buffer);

  // TO DO : test whether this suceeds or Erorr("write error on socket")
   send(sock, buffer, strlen(buffer), 0);




  /* Reception de donnees du serveur */
  char buffer2[1024];
  for(;;) {

    int res = recv(sock, buffer2, sizeof(buffer2)-1, 0);
    //printf(" res =%i \n", res);
    if (res > 0) {
      buffer2[res] = '\0';
      printf("%s", buffer2);
      fflush(stdout);
    }//if
    else
      break;
  }//for

  /* Fermeture de la socket client */
  close(sock);


}

void PostData(char host[], int port, char file[], char data[]){
  /* Calcul de l'IP de l'hote */
  struct hostent *hostinfo;
  hostinfo = gethostbyname(host);
  if (hostinfo) {
    struct in_addr  **pptr;
    pptr = (struct in_addr **)hostinfo->h_addr_list;
    printf("Adresse IP de l'hote : %s\n",inet_ntoa(**(pptr)));
  }

  /* Creation de la socket */
  if ( (sock = socket(AF_INET, SOCK_STREAM, 0)) <0 )
    Error("can't create socket");

  /* Configuration de la connexion */

  struct sockaddr_in sin;

  sin.sin_addr = *(struct in_addr *) hostinfo->h_addr;
  sin.sin_family = AF_INET;
  if ( (sin.sin_port = htons(port)) == 0)
    Error("unknown service");

  /* Tentative de connexion au serveur */
  if (connect(sock, (struct sockaddr*)&sin,sizeof(sin))<0)
    Error("can't connect");
  else printf("Connexion a %s sur le port %d\n", inet_ntoa(sin.sin_addr),
         htons(sin.sin_port));


    //Envoi de donnees au serveur
  char buffer[1024] = "POST ";
  strcat(buffer, file);
  strcat(buffer, " HTTP/1.0\r\n");
  strcat(buffer, "Host: ");
  strcat(buffer, host);
  strcat(buffer, "\r\nContent-Type: application/json\r\nX-Auth-Token: 1494771555601_5SGQdxJaJ8O1HBj4\r\nContent-Length: 16\r\n");
  //strcat(buffer, (char*)strlen(data));
  strcat(buffer, "\r\n");
  strcat(buffer, data);
  printf("Requete : \n%s", buffer);

  // TO DO : test whether this suceeds or Erorr("write error on socket")
   send(sock, buffer, strlen(buffer), 0);




  /* Reception de donnees du serveur */
  char buffer2[1024];
  for(;;) {

    int res = recv(sock, buffer2, sizeof(buffer2)-1, 0);
    //printf(" res =%i \n", res);
    if (res > 0) {
      buffer2[res] = '\0';
      printf("%s", buffer2);
      fflush(stdout);
    }//if
    else{
      break;
    }
  }

  /* Fermeture de la socket client */
  close(sock);


}


int main(void) {

  char host[100];
  printf("Hote : ");
  fgets(host, 100, stdin);
  char *pos = strchr(host, '\n');
  *pos = '\0';
  char file[100];
  printf("Ressource a chercher: ");
  fgets(file, 100, stdin);
  pos = strchr(file, '\n');
  *pos = '\0';
  printf("Port : ");
  int port;
  scanf("%d", &port);

  GetData(host,port,file);



  char fich[100];
  printf("Endroit ou poster : ");
  scanf("%*[^\n]");
  scanf("%*c");
  fgets(fich, 100, stdin);
  pos = strchr(fich, '\n');
  *pos = '\0';
  char data[] = "{\"data\":\"onche\"}";
  PostData(host,port,fich,data);

  return EXIT_SUCCESS;
}
