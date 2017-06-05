#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON-master/cJSON.h"

int parsage(char *fichier, int wts ){
	FILE *file;
	char *buffer;
	long lSize;
	int i;
	file = fopen(fichier, "r");

	

	if( !file ){ 
		perror(fichier),exit(1);
	}

	fseek( file , 0L , SEEK_END);
	lSize = ftell( file );
	rewind( file );

	/* allocate memory for entire content */
	buffer = calloc( 1, lSize+1 );
	if( !buffer ) fclose(file),fputs("memory alloc fails",stderr),exit(1);

	/* copy the file into the buffer */
	if( 1!=fread( buffer , lSize, 1 , file) )
	  fclose(file),free(buffer),fputs("entire read fails",stderr),exit(1);

	/* do your work here, buffer is a string contains the whole text */

	










	cJSON * root = cJSON_Parse(buffer);
	int tailleArray = cJSON_GetArraySize(root);
	//printf("%i \n", tailleArray);
	//cJSON * elem = cJSON_GetArrayItem(root, 0);
	i =0;
	while ( i < tailleArray) {
    	cJSON * elem = cJSON_GetArrayItem(root, i);
    	cJSON * data = cJSON_GetObjectItemCaseSensitive(elem, "wts");
    	char* rendered = cJSON_Print(data);
    	if (*rendered < wts){
    		break;
    	}
    	
		//printf("%s\n", rendered);
		++i;
	}
	
	for (--i;i >= 0; --i) {
    	cJSON * elem = cJSON_GetArrayItem(root, i);
    	cJSON * data = cJSON_GetObjectItemCaseSensitive(elem, "data");
    	char *rendered = cJSON_Print(data);
		printf("%s\n", rendered);
	}
	/*//printf("%s", *data);
	
	*/
	cJSON * elem = cJSON_GetArrayItem(root, i);
    cJSON * data = cJSON_GetObjectItemCaseSensitive(elem, "wts");
    	
	fclose(file);
	free(buffer);
	int retour;
	sscanf(cJSON_Print(data),"%i",&retour);
	return retour;
}


int main(void){

	//char *  nik = "{\"data\": \"type_msg=3,type_ent=SP,num=1,data=1,1,123.5.5.5\",\"wts\": 1495441879587,\"ts\": 1495441879587,\"_id\": \"5922a1d78fd6cc4e76031498\"}";

	parsage("curly.txt", 14);
	
	return 0;
	

	
}
