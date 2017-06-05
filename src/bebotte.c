// http_client.c

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
void PostData(char host[], int port, char file[], char data[]);
void PostBeebotte(char* message);
void GetData(char host[], int port, char file[]);

void getBeebotte(char * ress){
    char ressource[128] = 	"/v1/public/data/read/vberry/";
    strcat(ressource,ress);
    strcat(ressource,"/msg");
    GetData("api.beebotte.com",80,ressource);
}

char * writeRobotPosition(char * ipRobot, int x, int y, int isVerified, int possdeBallon, char team){
    char *result = malloc (sizeof(char) * 200);
    sprintf(result,"{\"data\":\"type_msg=POS, type_ent=MONITORING,ip=%s,x=%i,y=%i,isVerified=%d,possdeBallon=%d,team=%c\"}",ipRobot,x,y,isVerified,possdeBallon,team);
    return result;
}

void PostRobotPosition(char * ipRobot, int x, int y, int isVerified, int possdeBallon, char team){
    PostBeebotte(writeRobotPosition(ipRobot,x,y,isVerified,possdeBallon,team));
}

char * writeCurrentScore(int scoreRouge, int scoreBleu){
    char *result = malloc (sizeof(char) * 200);
    sprintf(result,"{\"data\":\"type_msg=SCORE, type_ent=MONITORING,scoreBleu=%d,scoreRouge=%d\"}",scoreRouge,scoreBleu);
    return result;
}

void PostCurrentScore(int scoreRouge, int scoreBleu){
    PostBeebotte(writeCurrentScore(scoreRouge,scoreBleu));
}

char * writeTempsRestant(int temps){
    char *result = malloc (sizeof(char) * 200);
    sprintf(result,"{\"data\":\"type_msg=temps, type_ent=MONITORING,temps=%d\"}\0",temps);
    return result;
}

void PostTempsRestant(int temps){
    PostBeebotte(writeTempsRestant(temps));
}

char * writePartieLancee(int partieLancee){
    char *result = malloc (sizeof(char) * 200);
    sprintf(result,"{\"data\":\"type_msg=temps, type_ent=MONITORING,partieLancee=%d\"}\0",partieLancee);
    return result;
}

void PostPartieLancee(int partieLancee){
    PostBeebotte(writePartieLancee(partieLancee));
}

void PostBeebotte(char* message){
    char* hote = "api.beebotte.com";
    char* ressource = "/v1/data/write/testVB/msg"; 
    PostData(hote, 80, ressource , message);
}

void Error(char *mess)
{
  fprintf(stderr,"%s\n",mess);
  if (sock) close(sock);
  exit(-1);
}

void GetData(char host[], int port, char file[]){
  /* Saisie des infos de connexion */
  
  
  //char *host="api.beebotte.com";



  /* Calcul de l'IP de l'hote */
  struct hostent *hostinfo;
  hostinfo = gethostbyname(host); 
  if (hostinfo) {
    struct in_addr  **pptr;
    pptr = (struct in_addr **)hostinfo->h_addr_list;
    printf("Adresse IP de l'hote : %s\n",inet_ntoa(**(pptr)));
  } 

/*  if (hostinfo) {
    struct in_addr  **pptr;
    pptr = (struct in_addr **)hostinfo->h_addr;
    printf("Adresse IP de l'hote : %s\n",inet_ntoa(**(pptr)));
  }*/

  /* if ( hostinfo = gethostbyname(host) )
    memcpy((void*)&sin.sin_addr,(void*)hostinfo->h_addr,hostinfo->h_length);
  else if( (sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE )
    Error("unknown host");
  */

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
  FILE *f = fopen("donnees.txt", "w");
  for(;;) {

    int res = recv(sock, buffer2, sizeof(buffer2)-1, 0);
    //printf(" res =%i \n", res);
    char * s;
    if(s = strstr(buffer2,"\r\n\r\n")){
       // memmove(s, s+strlen("\r\n\r\n"),1+strlen(s+strlen("\r\n\r\n")));
       fprintf(f,"%s",s+4 );
    }
    else if (res > 0) {
      buffer2[res] = '\0';
      printf("%s", buffer2);
      fprintf(f,"%s",buffer2 );
      fflush(stdout);
    }//if
    else
      break;
  }//for

  /* Fermeture de la socket client */
  fclose(f);
  close(sock);

  
}

void PostData(char host[], int port, char file[], char data[]){
  /* Saisie des infos de connexion */
  
  
  //char *host="api.beebotte.com";



  /* Calcul de l'IP de l'hote */
  struct hostent *hostinfo;
  hostinfo = gethostbyname(host); 
  if (hostinfo) {
    struct in_addr  **pptr;
    pptr = (struct in_addr **)hostinfo->h_addr_list;
    printf("Adresse IP de l'hote : %s\n",inet_ntoa(**(pptr)));
  } 

/*  if (hostinfo) {
    struct in_addr  **pptr;
    pptr = (struct in_addr **)hostinfo->h_addr;
    printf("Adresse IP de l'hote : %s\n",inet_ntoa(**(pptr)));
  }*/

  /* if ( hostinfo = gethostbyname(host) )
    memcpy((void*)&sin.sin_addr,(void*)hostinfo->h_addr,hostinfo->h_length);
  else if( (sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE )
    Error("unknown host");
  */

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
  strcat(buffer, "\r\nContent-Type: application/json\r\nX-Auth-Token: 1494771555601_5SGQdxJaJ8O1HBj4\r\nContent-Length:");
  int taille = strlen(data);
  char tailleData[16];
  sprintf(tailleData, "%d", taille);
  strcat(buffer,tailleData);
  strcat(buffer, "\r\n\r\n");
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
    else
      break;
  }//for

  /* Fermeture de la socket client */
  close(sock);

  
}


int main(void) {
    /*
    char host[100];
    printf("Hote : ");
    fgets(host, 100, stdin);
    char *pos = strchr(host, '\n');
    *pos = '\0';
    char file[100];
    printf("Fichier : ");
    fgets(file, 100, stdin);
    pos = strchr(file, '\n');
    *pos = '\0';
    printf("Port : ");
    int port;
    scanf("%d", &port);

    //GetData(host,port,file);
    char data[] = "{\"data\":\"onche\"}";
    PostData(host,port,file,data);
    */
    
    getBeebotte("testVB");
    
    return EXIT_SUCCESS;
}//main




