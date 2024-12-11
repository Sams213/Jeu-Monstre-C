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
    - Écrire DONE avant une fonction qui est terminée
    
    
    TODO:
    - Fonction qui défini le niveau d'un monstre
        - Attribuer nb hp, nb weapon, et damage
    
    - Fonctions de matchs différentes pour chaque phase du jeux:
        - Gestion des tours
            - Quelle arme est choisie
            - Quelle arme gagne
            - Distribution XP gerée par une fonction
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
               {'P', 'F', 'C'},
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

// DONE
void affichageMonstre(Monster m)
{
    printf("%s%d%d%d%d", m.name, m.hp, m.damage, m.level);
    printf("Ses armes sont: \n- Pierre\n- Feuille\n- Ciseaux\n"); 
}

// DONE
int duel(char *c1, char *c2)//C1 = joueur, return 0 for a draw,-1 for a lose, 1 for a win
{
    if(strcmp(c1,c2)==0) //compares two strings, returns 0 if equal
        return 0;
    if(c1=='P' && c2=='F')
        return 1;
    if(c1=='P' && c2=='C')
        return -1;
    if(c1=='F' && c2=='C')
        return -1;
    if(c1=='F' && c2=='P')
        return 1;
    if(c1=='C' && c2=='F')
        return 1;
    if(c1=='C' && c2=='P')
        return -1;
    if(c2=='#')
        return -1;
    if(c2=='O')
        return 1;
}
int 
