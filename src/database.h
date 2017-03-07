#include <stdio.h>
#include <stdlib.h>

#include <winsock.h>
#include <MYSQL/mysql.h>

/*
	@brief Ouvre une connection a la base de donnees a traver la structure mysql en parametre
	@param mysql Une structure de connection mysql
*/
void connectBD(MYSQL mysql);
/*
	@brief Ouvre une connection a la base de donnees a traver la structure mysql en parametre
	@param mysql Une structure de connection mysql
*/
void closeBD(MYSQL mysql);