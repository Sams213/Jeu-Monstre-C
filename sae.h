#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char pseudo[32];
    int hp, *score, ngame;
} Player;

typedef struct monster
{
    char name[16];
    int hp, damage;
    char weapons[5];
    int level;
    struct monster *next;
} Monster;


Monster monsterlvl1(char *c);
Monster monsterlvl2(char *c);
Monster monsterlvl3(char *c);
void affichageMonstre(Monster m);
int duel(char *c1, char *c2);