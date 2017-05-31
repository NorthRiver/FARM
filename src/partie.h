#include "robot.h"
/**
* @struct Partie Contient toutes les infos des partie
* @param scoreRouge Le score des rouges
* @param scoreBleu Le score des bleu
* @param tempsRestant Temps en seconde avant la fin de la partie
* @param robotRouge tableau des trois robots rouges
* @param robotBleu tableau des trois robots bleu
*/
typedef struct PartieR
{
  int scoreRouge;
  int scoreBleu;
  int tempsRestant;
  Robot robotRouge[3];
  Robot robotBleu[3];

} Partie;

int getScoreRouge(Partie * p);
void setScoreRouge(Partie * p);
int getScoreBleu(Partie * p);
void setScoreBleu(Partie * p);
Robot ** getRobotRouge(Partie * p);
Robot ** getRobotBleu(Partie * p);
void pushRobotRouge(Partie * p);
void pushRobotBleu(Partie * p);
