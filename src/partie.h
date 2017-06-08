#include "robot.h"

#define NBJ 3
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
  Robot robotRouge[NBJ];
  int nbRobotRouge;
  Robot robotBleu[NBJ];
  int nbRobotBleu;

} Partie;

int getScoreRouge(Partie * p);
void setScoreRouge(Partie * p, int val);
int getTemps(Partie * p);
void setTemps(Partie * p, int val);
int getScoreBleu(Partie * p);
void setScoreBleu(Partie * p, int val);
Robot ** getRobotRouge(Partie * p);
Robot ** getRobotBleu(Partie * p);
void pushRobotRouge(Partie * p, Robot * r);
void pushRobotBleu(Partie * p, Robot * r);
int getnbRobotRouge(Partie * p);
void setnbRobotRouge(Partie * p, int val);
int getnbRobotBleu(Partie * p);
void setnbRobotBleu(Partie * p, int val);
