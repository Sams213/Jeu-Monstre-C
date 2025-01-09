#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct player
{
    char pseudo[32];
    int hp, score, ngame;
    char weapons[3];
    int degats;
    struct player *suiv;
} Player;

typedef struct
{
    Player *first;
    Player *last;
} ListePlayer;

typedef struct monster
{
    char name[16];
    int hp, damage;
    char weapons[5];
    int level;
    struct monster *next;
} Monster, *ListeMonstre;

void clear(void);
int generate_random_number(int x);
Monster monsterlvl1(char *c);
Monster monsterlvl2(char *c);
Monster monsterlvl3(char c[]);
void affichageMonstre(Monster m);
int ResultatDuel(Player *p, Monster *m);
int NouvelleHPmonster1(int hp);
void NouvelleHPmonster3(Player p);
int ExperienceRound1(Monster m, Player p);
void AttaqueGagnee(Player p);
int ExperienceRound2(Monster m, Player p);
void Contexte(int phase);
void Menu(void);
ListeMonstre createListeMonstre(void);
ListeMonstre addMonster(ListeMonstre l, Monster m);
void afficherListeMonstre(ListeMonstre l);
ListeMonstre removeHeadMonster(ListeMonstre l);
Monster getHeadMonster(ListeMonstre l);
Player *createPlayer(char pseudo[]);
char choixArme(void);
void affichagePlayer(Player p);
bool estMortPlayer(Player p);
bool estMortMonster(Monster m);
int combat1(Player *p, ListeMonstre l);
bool estVide(ListeMonstre l);
int hauteurListeMonstre(ListeMonstre l);
ListePlayer *createListePlayer(void);
void addPlayer(ListePlayer *l, Player *p);
void removeHeadPlayer(ListePlayer *l);
bool estVidePlayer(ListePlayer l);
void affichageListePlayer(ListePlayer l);
Player getHeadPlayer(ListePlayer l);
int combat2(Player *p, ListeMonstre l);
void simulateTyping(char *str, int speed);
void insererEnTete(Player *lp, Player *p);