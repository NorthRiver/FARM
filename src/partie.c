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

    printf("mon index avant : %d\n", index);
    if (index < NBJ) {
        setnbRobotRouge(p, getnbRobotRouge(p) + 1);
        int index2 = getnbRobotBleu(p);

        printf("mon index apres : %d\n", index2);
        p->robotRouge [index] = r;
        setnbRobotRouge(p, index++);
    }
}
void pushRobotBleu(Partie * p, Robot * r){
    int index = getnbRobotBleu(p);

    printf("mon index avant : %d\n", index);
    if (index < NBJ) {
        setnbRobotBleu(p, getnbRobotBleu(p) + 1);
        int index2 = getnbRobotBleu(p);

        printf("mon index apres : %d\n", index2);
        p->robotBleu [index] = r;
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
