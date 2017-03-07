#include "database.h"

void connectBD(MYSQL mysql){
	mysql_init(&mysql);
	mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    if(mysql_real_connect(&mysql,"teabreak.fr","FARMU","billyboy","FARM",0,NULL,0))
    {
        printf("Connection à la BD succes !\n");
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion à la BDD!\n");
    }
}

void closeBD(MYSQL mysql){
	mysql_close(&mysql);
}