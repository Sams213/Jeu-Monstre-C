#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct player
{
    char pseudo[32];
    int hp, score, ngame;
    char weapons[3];
    int degats;
    struct player *suiv;
} Player;

typedef struct monster
{
    char name[16];
    int hp, damage;
    char weapons[5];
    int level;
    struct monster *next;
} Monster;

int generate_random_number(int x);
Monster monsterlvl1(char *c);
Monster monsterlvl2(char *c);
Monster monsterlvl3(char *c);
void affichageMonstre(Monster m);
int ResultatDuel(char c1, char c2);
int NouvelleHPmonster1(int hp);
void NouvelleHPmonster3(Player p);
int ExperienceRound1(Monster m, Player p);
void AttaqueGagnee(Player p);
int ExperienceRound2(Monster m, Player p);
void Contexte(int phase);
void Menu(void);
