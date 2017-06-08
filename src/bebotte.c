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
#include "bebotte.h"
#include "cJSON.h"

#define PARTIE "partie1"
#define TOKENPARTIE "1494793564147_KNl54g97mG89kQSZ"



int sock;
void PostData(char host[], int port, char file[], char data[]);
void PostBeebotte(char* message);
void GetData(char host[], int port, char file[], char fichier[]);


char* parsage(char *fichier, long long * wts, char * expr){
    FILE *file;
    char *buffer;
    long lSize;
    int i;

    file = fopen(fichier, "r");



    if (!file) {
        perror(fichier), exit(1);
    }

    fseek(file, 0L, SEEK_END);
    lSize = ftell(file);
    rewind(file);

    /* allocate memory for entire content */
    buffer = calloc(1, lSize + 1);
    if (!buffer) fclose(file), fputs("memory alloc fails", stderr), exit(1);

    /* copy the file into the buffer */
    if (1 != fread(buffer, lSize, 1, file))
        fclose(file), free(buffer), fputs("entire read fails", stderr), exit(1);

    /* do your work here, buffer is a string contains the whole text */












    cJSON * root = cJSON_Parse(buffer);
    int tailleArray = cJSON_GetArraySize(root);
    //printf("%i \n", tailleArray);
    //cJSON * elem = cJSON_GetArrayItem(root, 0);
    i = 0;
    while (i < tailleArray) {
        cJSON * elem = cJSON_GetArrayItem(root, i);
        cJSON * data = cJSON_GetObjectItemCaseSensitive(elem, "wts");
        char* rendered = cJSON_Print(data);
        if (*rendered < *wts) {
            break;
        }

        //printf("%s\n", rendered);
        ++i;
    }
    char * retour = malloc(128);


    for (--i; i >= 0; --i) {
        char * s;
        cJSON * elem = cJSON_GetArrayItem(root, i);
        cJSON * data = cJSON_GetObjectItemCaseSensitive(elem, "data");
        char *rendered = cJSON_Print(data);
        if ((s = strstr(rendered, expr))) {
            s = strstr(rendered, "data=");
            s += 5;
            strtok(s, "\"");
            //printf("%s\n",s);
            strcat(retour, s);
            strcat(retour, "/");
        }

        //printf("%s\n", rendered);
    }
    /*//printf("%s", *data);
     *
     */
    cJSON * elem = cJSON_GetArrayItem(root, ++i);
    cJSON * data = cJSON_GetObjectItemCaseSensitive(elem, "wts");

    fclose(file);
    free(buffer);
    //int retour;

    sscanf(cJSON_Print(data), "%lld", wts);
    printf("%lld\n", *wts);
    if (strlen(retour) > 0) {
        retour [strlen(retour) - 1] = 0;
    }
    //printf("%s\n",retour);
    return retour;
}






int parsageAllRobots(char *fichier, int wts, int nbRobot){
    FILE *file;
    char *buffer;
    long lSize;
    int i;

    file = fopen(fichier, "r");



    if (!file) {
        perror(fichier), exit(1);
    }

    fseek(file, 0L, SEEK_END);
    lSize = ftell(file);
    rewind(file);

    /* allocate memory for entire content */
    buffer = calloc(1, lSize + 1);
    if (!buffer) fclose(file), fputs("memory alloc fails", stderr), exit(1);

    /* copy the file into the buffer */
    if (1 != fread(buffer, lSize, 1, file))
        fclose(file), free(buffer), fputs("entire read fails", stderr), exit(1);

    /* do your work here, buffer is a string contains the whole text */












    cJSON * root = cJSON_Parse(buffer);
    int tailleArray = cJSON_GetArraySize(root);
    //printf("%i \n", tailleArray);
    //cJSON * elem = cJSON_GetArrayItem(root, 0);
    i = 0;
    while (i < tailleArray) {
        cJSON * elem = cJSON_GetArrayItem(root, i);
        cJSON * data = cJSON_GetObjectItemCaseSensitive(elem, "wts");
        char* rendered = cJSON_Print(data);
        if (*rendered < wts) {
            break;
        }

        //printf("%s\n", rendered);
        ++i;
    }
    int retour = 0;


    for (--i; i >= 0; --i) {
        char * s;
        cJSON * elem = cJSON_GetArrayItem(root, i);
        cJSON * data = cJSON_GetObjectItemCaseSensitive(elem, "data");
        char *rendered = cJSON_Print(data);
        if ((s = strstr(rendered, "type_ent=RJ"))) {
            ++retour;
        }

        //printf("%s\n", rendered);
    }
    /*//printf("%s", *data);
     *
     */
    cJSON * elem = cJSON_GetArrayItem(root, i);
    cJSON * data = cJSON_GetObjectItemCaseSensitive(elem, "wts");

    fclose(file);
    free(buffer);
    //int retour;
    //sscanf(cJSON_Print(data),"%i",&retour);
    if (retour == nbRobot) {
        return 1;
    }
    return 0;
}


void getBeebotte(char * ress, char * fich){
    char ressource [128] = "/v1/public/data/read/vberry/";

    strcat(ressource, ress);
    strcat(ressource, "/msg");
    GetData("api.beebotte.com", 80, ressource, fich);
}

char * getRedTeam(){
    getBeebotte(PARTIE, "rouge.txt");
    long long i = 0;
    char * retour = parsage("rouge.txt", &i, "couleur=rouge");
    //remove("rouge.txt");
    //printf("%s\n",retour);
    return retour;
}

char * getBlueTeam(){
    getBeebotte(PARTIE, "bleu.txt");
    long long i = 0;
    char * retour = parsage("bleu.txt", 0, "couleur=bleu");
    remove("bleu.txt");
    return retour;
}

char * getGoal(){
    char * ress = "VB";

    strcat(ress, PARTIE);
    getBeebotte(ress, "but.txt");
    long long i = 0;
    char * retour = parsage("but.txt", &i, "type_msg=BUT");
    remove("but.txt");
    return retour;
}

char * getGP(long long *i){
    char * ress = "GP";

    strcat(ress, PARTIE);
    getBeebotte(ress, "GP.txt");
    char * retour = parsage("GP.txt", i, "type_ent=GP");
    remove("GP.txt");
    return retour;
}

char * getDB(long long *i){
    char * ress = "DB";

    strcat(ress, PARTIE);
    getBeebotte(ress, "DB.txt");
    char * retour = parsage("DB.txt", i, "type_ent=DB");
    remove("DB.txt");
    return retour;
}


int isThereAllRobots(int i){
    getBeebotte(PARTIE, "robot.txt");
    int retour = parsageAllRobots("robot.txt", 0, i);
    remove("robot.txt");
    return retour;
}






char * writeRobotPosition(char * ipRobot, int x, int y, int isVerified, int possdeBallon, char team){
    char *result = malloc(sizeof(char) * 200);

    sprintf(result, "{\"data\":\"type_msg=POS, type_ent=MONITORING,ip=%s,x=%i,y=%i,isVerified=%d,possdeBallon=%d,team=%c\"}", ipRobot, x, y, isVerified, possdeBallon, team);
    return result;
}

void postRobotPosition(char * ipRobot, int x, int y, int isVerified, int possedeBallon, char team){
    PostBeebotte(writeRobotPosition(ipRobot, x, y, isVerified, possedeBallon, team));
}

char * writeCurrentScore(int scoreRouge, int scoreBleu){
    char *result = malloc(sizeof(char) * 200);

    sprintf(result, "{\"data\":\"type_msg=SCORE, type_ent=MONITORING,scoreBleu=%d,scoreRouge=%d\"}", scoreRouge, scoreBleu);
    return result;
}

void postCurrentScore(int scoreRouge, int scoreBleu){
    PostBeebotte(writeCurrentScore(scoreRouge, scoreBleu));
}

char * writeTempsRestant(int temps){
    char *result = malloc(sizeof(char) * 200);

    sprintf(result, "{\"data\":\"type_msg=temps, type_ent=MONITORING,data=%d\"}", temps);
    return result;
}

void postTempsRestant(int tempsRestantEnSeconde){
    PostBeebotte(writeTempsRestant(tempsRestantEnSeconde));
}

char * writePartieLancee(int partieLancee){
    char *result = malloc(sizeof(char) * 200);

    sprintf(result, "{\"data\":\"type_msg=partie, type_ent=MONITORING,data=%d\"}", partieLancee);
    return result;
}

void postIsGameLaunch(int partieLancee){
    PostBeebotte(writePartieLancee(partieLancee));
}

void PostBeebotte(char* message){
    char* hote = "api.beebotte.com";
    char ressource [128] = "/v1/data/write/";

    strcat(ressource, PARTIE);
    strcat(ressource, "/msg");
    PostData(hote, 80, ressource, message);
}

void Error(char *mess){
    fprintf(stderr, "%s\n", mess);
    if (sock) close(sock);
    exit(-1);
}

void GetData(char host[], int port, char file[], char * fichier){
    /* Saisie des infos de connexion */


    //char *host="api.beebotte.com";



    /* Calcul de l'IP de l'hote */
    struct hostent *hostinfo;

    hostinfo = gethostbyname(host);
    if (hostinfo) {
        struct in_addr  **pptr;
        pptr = (struct in_addr **)hostinfo->h_addr_list;
        printf("Adresse IP de l'hote : %s\n", inet_ntoa(**(pptr)));
    }

/*  if (hostinfo) {
 *  struct in_addr  **pptr;
 *  pptr = (struct in_addr **)hostinfo->h_addr;
 *  printf("Adresse IP de l'hote : %s\n",inet_ntoa(**(pptr)));
 * }*/

    /* if ( hostinfo = gethostbyname(host) )
     * memcpy((void*)&sin.sin_addr,(void*)hostinfo->h_addr,hostinfo->h_length);
     * else if( (sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE )
     * Error("unknown host");
     */

    /* Creation de la socket */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        Error("can't create socket");

    /* Configuration de la connexion */

    struct sockaddr_in sin;

    sin.sin_addr = *(struct in_addr *)hostinfo->h_addr;
    sin.sin_family = AF_INET;
    if ((sin.sin_port = htons(port)) == 0)
        Error("unknown service");

    /* Tentative de connexion au serveur */
    if (connect(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0)
        Error("can't connect");
    else printf("Connexion a %s sur le port %d\n", inet_ntoa(sin.sin_addr),
            htons(sin.sin_port));


    //Envoi de donnees au serveur
    char buffer [1024] = "GET ";
    strcat(buffer, file);
    //strcat(buffer,"?limit=2");
    strcat(buffer, " HTTP/1.0\r\n");
    strcat(buffer, "Host: ");
    strcat(buffer, host);
    strcat(buffer, "\r\n\r\n");
    printf("Requete : \n%s", buffer);

    // TO DO : test whether this suceeds or Erorr("write error on socket")
    send(sock, buffer, strlen(buffer), 0);




    /* Reception de donnees du serveur */
    char buffer2 [1024];
    FILE *f = fopen(fichier, "w");
    for (;; ) {
        int res = recv(sock, buffer2, sizeof(buffer2) - 1, 0);
        //printf(" res =%i \n", res);
        char * s;
        if ((s = strstr(buffer2, "\r\n\r\n"))) {
            // memmove(s, s+strlen("\r\n\r\n"),1+strlen(s+strlen("\r\n\r\n")));
            fprintf(f, "%s", s + 4);
        }
        else if (res > 0) {
            buffer2 [res] = '\0';
            printf("%s", buffer2);
            fprintf(f, "%s", buffer2);
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
        printf("Adresse IP de l'hote : %s\n", inet_ntoa(**(pptr)));
    }

/*  if (hostinfo) {
 *  struct in_addr  **pptr;
 *  pptr = (struct in_addr **)hostinfo->h_addr;
 *  printf("Adresse IP de l'hote : %s\n",inet_ntoa(**(pptr)));
 * }*/

    /* if ( hostinfo = gethostbyname(host) )
     * memcpy((void*)&sin.sin_addr,(void*)hostinfo->h_addr,hostinfo->h_length);
     * else if( (sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE )
     * Error("unknown host");
     */

    /* Creation de la socket */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        Error("can't create socket");

    /* Configuration de la connexion */

    struct sockaddr_in sin;

    sin.sin_addr = *(struct in_addr *)hostinfo->h_addr;
    sin.sin_family = AF_INET;
    if ((sin.sin_port = htons(port)) == 0)
        Error("unknown service");

    /* Tentative de connexion au serveur */
    if (connect(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0)
        Error("can't connect");
    else printf("Connexion a %s sur le port %d\n", inet_ntoa(sin.sin_addr),
            htons(sin.sin_port));


    //Envoi de donnees au serveur
    char buffer [1024] = "POST ";
    strcat(buffer, file);
    strcat(buffer, " HTTP/1.0\r\n");
    strcat(buffer, "Host: ");
    strcat(buffer, host);
    strcat(buffer, "\r\nContent-Type: application/json\r\nX-Auth-Token: ");
    // 1494771555601_5SGQdxJaJ8O1HBj4
    strcat(buffer, TOKENPARTIE);
    strcat(buffer, "\r\nContent-Length:");

    int taille = strlen(data);
    char tailleData [16];
    sprintf(tailleData, "%d", taille);
    strcat(buffer, tailleData);
    strcat(buffer, "\r\n\r\n");
    strcat(buffer, data);
    printf("Requete : \n%s", buffer);

    // TO DO : test whether this suceeds or Erorr("write error on socket")
    send(sock, buffer, strlen(buffer), 0);




    /* Reception de donnees du serveur */
    char buffer2 [1024];
    for (;; ) {
        int res = recv(sock, buffer2, sizeof(buffer2) - 1, 0);
        //printf(" res =%i \n", res);
        if (res > 0) {
            buffer2 [res] = '\0';
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
     * char host[100];
     * printf("Hote : ");
     * fgets(host, 100, stdin);
     * char *pos = strchr(host, '\n');
     * pos = '\0';
     * char file[100];
     * printf("Fichier : ");
     * fgets(file, 100, stdin);
     * pos = strchr(file, '\n');
     * pos = '\0';
     * printf("Port : ");
     * int port;
     * scanf("%d", &port);
     *
     * //GetData(host,port,file);
     * char data[] = "{\"data\":\"onche\"}";
     * PostData(host,port,file,data);
     */

    //printf("%s\n",getRedTeam());
    //printf("%i",IsThereAllRobots(2));


    postIsGameLaunch(1);
    sleep(300);
    postIsGameLaunch(0);
    //getBeebotte("testVB");

    return EXIT_SUCCESS;
}//main
