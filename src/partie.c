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

int getTemps(Partie * p){
    return p->tempsRestant;
}
void setTemps(Partie * p, int val){
    p->tempsRestant = val;
}

Robot ** getRobotRouge(Partie * p){
    return p->robotRouge;
}
Robot ** getRobotBleu(Partie * p){
    return p->robotBleu;
}
void pushRobotRouge(Partie * p, Robot * r){
    int index = getnbRobotRouge(p);

    if (index << NBJ) {
        printf("\n[\033[33mDEBUG\033[0m] Test b32 %d\n", index);
        p->robotRouge [index] = r;
        printf("\n[\033[33mDEBUG\033[0m] Test b33\n");
        setnbRobotRouge(p, index++);
    }
}
void pushRobotBleu(Partie * p, Robot * r){
    int index = getnbRobotBleu(p);

    if (index << NBJ) {
        p->robotBleu [index] = r;
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
