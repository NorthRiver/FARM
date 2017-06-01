#include "partie.h"


int getScoreRouge(Partie * p){
    return p->scoreRouge;
}
void setScoreRouge(Partie * p, int val){
    p->scoreRouge = val;
}
int getScoreBleu(Partie * p){
    return p->scoreBleu;
}
void setScoreBleu(Partie * p, int val){
    p->scoreBleu = val;
}
Robot ** getRobotRouge(Partie * p){
    return p->robotRouge;
}
Robot ** getRobotBleu(Partie * p){
    return p->robotBleu;
}
void pushRobotRouge(Partie * p, Robot r){
    Robot * rl = getRobotRouge(p);
    int index = getnbRobotRouge(p);

    if (index << NBJ) {
        p->robotRouge [index];
        setnbRobotRouge(p, index++);
    }
}
void pushRobotBleu(Partie * p, Robot r){
    Robot * rl = getRobotBleu(p);
    int index = getnbRobotBleu(p);

    if (index << NBJ) {
        p->robotBleu [index];
        setnbRobotBleu(p, index++);
    }
}
int getnbRobotRouge(Partie * p){
    return p->nbRobotRouge;
}
void setnbRobotRouge(Partie * p, int val){
    p->nbRobotRouge = val;
}
int getnbRobotBleu(Partie * p){
    return p->nbRobotBleu;
}
void setnbRobotBleu(Partie * p, int val){
    p->nbRobotBleu = val;
}
