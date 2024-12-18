#include "sae.h"

/*
    A RENDRE AVANT LE 10 JANVIER

    
    Règles:
    - Accolades à la lignes
    - Nom des variables en english please
    - Les fonctions sont les plus simples possibles
    - La doc est écrite au fur et à mesure
    - Push de code non finit ok mais à annoter et prévenir sur discord
    - TESTER AVANT DE PUSH!!!
    - Écrire DONE lorsqu'une fonction est terminée avant sa déclaration
    - Écrire WIP suivit de son prénom avant la déclaration d'une fonction en cours de développement
    
    
    TODO:
    - DONE Fonction qui défini le niveau d'un monstre
        - Attribuer nb hp, nb weapon, et damage
    
    - Fonctions de matchs différentes pour chaque phase du jeux:
        - Gestion des tours
            - Quelle arme est choisie
            - DONE Quelle arme gagne
            - WIP Distribution XP gerée par une fonction
            - Distribution damage
            - Gestion de la mort
    
    - Fonction gestion de la mort

    - Fonction de sauvegarde:
        - Est appelée à chaque fin de match et à la mort du joueur

    - Fonction de statistiques:

    
    TODO later:
    - Fonction de difficulté: est appelée au dbut de la partie et hange les dégat infligé aux monstres
    
    - Fonction de narration pour rajouter du contexte au rpg
        - Afficher du texte
        - Effacer le terminal


    Idées:
        - Listes Chainées pour les monstres
*/

// DONE
Monster monsterlvl1(char *c)
{
    Monster m;
        strcpy(m.name,c);
        m.hp = 4;
        m.damage = 1;
        m.level = 1;
        m.next = NULL;
        return m;
}

// DONE
Monster monsterlvl2(char *c)
{
    Monster m = {
               c,
               6,
               1,
               3,
               "PFC",
               2,
               NULL
           };
    return m;
}

// DONE
Monster monsterlvl3(char *c)
{
    Monster m = {
               c,
               4,
               2,
               5,
               {'P', 'F', 'C', 'O', '#'},
               3,
               NULL
           };
    return m;
}

// DONE question
void affichageMonstre(Monster m)
{
    printf("%s%d%d%d%d", m.name, m.hp, m.damage, m.level);
    printf("Ses armes sont: \n- Pierre\n- Feuille\n- Ciseaux\n"); //Comment sait-on que ses armes sont celles ci?
}

// DONE question
int ResultatDuel(char playerWeapon, char monsterWeapon)//playerWeapon = joueur, return 0 for a draw,-1 for a lose, 1 for a win
{
    if(strcmp(playerWeapon,monsterWeapon)==0) //compares two strings, returns 0 if equal
        return 0;
    if(playerWeapon=='P' && monsterWeapon=='F')
        return 1;
    if(playerWeapon=='P' && monsterWeapon=='C')
        return -1;
    if(playerWeapon=='F' && monsterWeapon=='C')
        return -1;
    if(playerWeapon=='F' && monsterWeapon=='P')
        return 1;
    if(playerWeapon=='C' && monsterWeapon=='F')
        return 1;
    if(playerWeapon=='C' && monsterWeapon=='P')
        return -1;
    if(monsterWeapon=='#')
        return -1;
    else
        return 1;
}

// DONE Antonin
int ExperienceRound1(Monster m, Player p) //state = 1 pour une attaque gagnée, 2 pour un monstre vaincu m.level pour le niveau du monstre;
{
    p.xp = p.xp + m.level * 50;
}

// DONE Antonin
void AttaqueGagnee(Player p)
{
    p.xp = p.xp + 10;
}

// DONE
int ExperienceRound2(Monster m, Player p) //state = 1 pour une attaque gagnée, 2 pour un monstre vaincu
//m.level pour le niveau du monstre;
{
    p.xp = p.xp + m.level * 100;
}

// DONE
int NouvelleHPmonster1(int hp) //nouveeau HP apres la bataille avec monstre lvl 1 et lvl 2
{
    hp--;
    return hp;
}

// DONE
void NouvelleHPmonster3(Player p) //nouveeau HP apres la bataille avec monstre lvl 3
{
    p.hp = p.hp - 3;
}

//WIP Antonin
void Contexte(int phase)
{
    printf("Contexte: ");
    if(phase == 1)
        printf("vous arrivez dans un corridor, bordé par deux falaises des monstres arrivent les uns après les autres");
    if(phase == 2)
        printf("vous arrivez au bout du corridor, une plaine herbeuse apparaît. Malheureusement des monstres sortent de partout pour tous vous attaquer en même temps ou presque...");
}

//WIP Antonin
int Menu(void)
{
    int choix;
    printf("------------- Menu -------------\n");
    printf("1. jouer une partie prédéfinie\n");
    printf("2. créer une nouvelle partie\n");
    printf("3. afficher la liste des joueurs triée par nom\n");
    printf("4. afficher la liste des joueurs triée par meilleur score\n");
    printf("5. afficher les statistiques d'un joueur\n");
    printf("9 Quitter\n");
    printf("--------------------------------\n");
    printf("choix: ");
    scanf("%d", "&choix");

    switch(choix){
        case 1: //TODO APPEL FONCTION
            break;
        
    }
}