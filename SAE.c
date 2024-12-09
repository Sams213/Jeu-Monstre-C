#include "SAE.h"

/*
    A RENDRE AVANT LE 10 JANVIER

    
    Règles:
    - Accolades à la lignes
    - Nom des variables en english please
    - Les fonctions sont les plus simples possibles
    - La doc est écrite au fur et à mesure
    
    
    TODO:
    - Fonction qui défini le niveau d'un monstre
        - Attribuer nb hp, nb weapon, et damage
    
    - Fonctions de matchs différentes pour chaque phase du jeux:
        - Gestion des tours
            - Quelle arme est choisie
            - Quelle arme gagne
            - Distribution XP gerer par une fonction
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

Monster monsterlvl1(char *c)
{
    Monster m = {
               c,
               4,
               1,
               4,
               1
           };
    return m;
}

Monster monsterlvl2(char *c)
{
    Monster m = {
               c,
               6,
               1,
               3,
               2
           };
    return m;
}

Monster monsterlvl3(char *c)
{
    Monster m = {
               c,
               4,
               2,
               5,
               3
           };
    return m;
}