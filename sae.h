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

/**
 * @brief clears the screen based on the OS
 * 
 */
void clear(void);

/**
 * @brief simulate the typing effect
 * 
 * @param str what to print
 * @param speed at which speed
 */
void simulateTyping(char *str, int speed);

/**
 * @brief generate a random number
 * 
 * @param x upper limit of the random number
 * @return int 
 */
int generate_random_number(int x);

/**
 * @brief creates a player object
 * 
 * @param pseudo name of the player
 * @return Player* 
 */
Player *createPlayer(char pseudo[]);

/**
 * @brief createz a list player object
 * 
 * @return ListePlayer* 
 */
ListePlayer *createListePlayer(void);

/**
 * @brief adds player to the list
 * 
 * @param l list
 * @param p player
 */
void addPlayer(ListePlayer *l, Player *p);

/**
 * @brief removes the first player in the list
 * 
 * @param l list
 */
void removeHeadPlayer(ListePlayer *l);

/**
 * @brief TODO
 * 
 * @param l 
 * @return true 
 * @return false 
 */
bool estVidePlayer(ListePlayer l);

/**
 * @brief get the first player of the list
 * 
 * @param l list of players
 * @return Player 
 */
Player getHeadPlayer(ListePlayer l);

/**
 * @brief creates the list of monsters
 * 
 * @return ListeMonstre
 */
ListeMonstre createListeMonstre(void);

/**
 * @brief adds monster to the list
 * 
 * @param l list of monster
 * @param m monster
 * @return ListeMonstre 
 */
ListeMonstre addMonster(ListeMonstre l, Monster m);

/**
 * @brief removes the first mosnter of the list
 * 
 * @param l 
 * @return ListeMonstre 
 */
ListeMonstre removeHeadMonster(ListeMonstre l);

/**
 * @brief todo
 * 
 * @param l 
 * @return true 
 * @return false 
 */
bool estVide(ListeMonstre l);

/**
 * @brief gets the first monster of the list
 * 
 * @param l 
 * @return Monster 
 */
Monster getHeadMonster(ListeMonstre l);


/**
 * @brief create monster level 1, 2 or 3 according to the subject
 * 
 * @param c 
 * @return Monster 
 */
Monster monsterlvl1(char *c);
Monster monsterlvl2(char *c);
Monster monsterlvl3(char *c);

/**
 * @brief displays the list of players
 * 
 * @param l list of players
 */
void affichageListePlayer(ListePlayer l);

void affichageMonstre(Monster m);
int ResultatDuel(Player *p, Monster *m);
int NouvelleHPmonster1(int hp);
void NouvelleHPmonster3(Player p);
int ExperienceRound1(Monster m, Player p);
void AttaqueGagnee(Player p);
int ExperienceRound2(Monster m, Player p);
void Contexte(int phase);
void Menu(void);
void afficherListeMonstre(ListeMonstre l);
char choixArme(void);
void affichagePlayer(Player p);
bool estMortPlayer(Player p);
bool estMortMonster(Monster m);
int combat1(Player *p, ListeMonstre l);
int hauteurListeMonstre(ListeMonstre l);
int combat2(Player *p, ListeMonstre l);
void inserer(Player *lp, Player *p);
void addPlayer(Player *lpFirst, Player *p);