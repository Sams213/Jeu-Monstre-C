/**
 * @file sae.h
 * @author Sami, Ghassan et Antonin
 * @brief ce fichir contient le prototype de chaque fonction
 * 
 */

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

typedef struct
{
    char name[16];
    int score;
    int nbParties;
} Score;

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
 * @brief inserts data in a list
 *
 * @param lp
 * @param p
 */
void inserer(Player *lp, Player *p);

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

/**
 * @brief output player's stats
 *
 * @param p player object
 */
void affichagePlayer(Player p);

/**
 * @brief displays monster
 *
 * @param m list of monsters
 */
void affichageMonstre(Monster m);

/**
 * @brief displays list of monster with their details
 *
 * @param l list of monsters
 */
void afficherListeMonstre(ListeMonstre l);

/**
 * @brief calculate depth of list
 *
 * @param l
 * @return int
 */
int hauteurListeMonstre(ListeMonstre l);

/**
 * @brief return the output of a match
 *
 * @param p weapon of the player
 * @param m random weapon of the monster
 * @return int -1 lose, 0 draw, 1 win
 */
int ResultatDuel(Player *p, Monster *m);

/**
 * @brief let the player coose their weapon
 *
 * @return char
 */
char choixArme(void);

/**
 * @brief kills the player
 *
 * @param p player's hp
 */
bool estMortPlayer(Player p);

/**
 * @brief kills the monster
 *
 * @param m
 */
bool estMortMonster(Monster m);

/**
 * @brief function for any fight of the first phase
 *
 * @param p player
 * @param l list of monsters
 * @return int victory or defeat
 */
int combat1(Player *p, ListeMonstre *l);

/**
 * @brief function for any fight of the second phase
 *
 * @param p player
 * @param l list of monsters
 * @return int victory or defeat
 */
int combat2(Player *p, ListeMonstre l);

/**
 * @brief give player experience when he kills a monster
 *
 * @author Antonin
 *
 * @param m use to retreive monster's level
 * @param p use to increase player's level
 */
int ExperienceRound1(Monster m, Player p);

/**
 * @brief gives player experience when he wins an attack
 *
 * @author Antonin
 *
 * @param p use to increase player's level
 */
void AttaqueGagnee(Player p);

/**
 * @brief gives player experience when he kills a monster in the second phase
 *
 * @author Antonin
 *
 * @param m use to retreive monster's level
 * @param p use to retreive player's level
 */
int ExperienceRound2(Monster m, Player p);

/**
 * @brief calculate new hp of player
 *
 * @param hp
 * @return int
 */
int NouvelleHPmonster1(int hp);
void NouvelleHPmonster3(Player p);

/**
 * @brief prints peices of contexte to improve gameplay
 *
 * @author Antonin
 *
 * @param whatToPrint use to print the right piece of information
 */
void Contexte(int phase);

/**
 * @brief printf a menu and reacts adequately
 *
 * @author Antonin
 */
void Menu(void);

void affichageScore(Score s);

Score *saveScore(Player p, Score tScore[], int nb);

void affichageListeScore(Score tScore[], int nb);

void save(ListePlayer *lp, Score tScore[], int nb);

Score *load(ListePlayer *lp, Score tScore[], int *nb);