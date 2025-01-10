/**
 * @file main.c
 * @author Sami, Ghassan et Antonin
 * @brief ce fichier est utiliser pour tester les fonctions
 * @date 2025-01-10
 * 
 * 
 */

#include "sae.h"

void test(void)
{
    clear();
    Score *tScore = NULL;
    Monster m1, m2, m3, *l;
    l = createListeMonstre();
    char c1 = 'P', c2 = 'F', c3 = 'C', c4 = '#', c5 = 'O';
    int r, nb = 0;
    m1 = monsterlvl1("Hasbani");
    m2 = monsterlvl1("sami");
    // m3 = monsterlvl1("ghassan");
    // l = addMonster(l, m3);
    // l = addMonster(l, m2);
    l = addMonster(l, m1);
    // afficherListeMonstre(l);
    // printf("\n\n\n\n\n");
    // affichageMonstre(getHeadMonster(l));
    // l = removeHeadMonster(l);
    // l = removeHeadMonster(l);
    // afficherListeMonstre(l);
    // affichageMonstre(m1);
    // affichageMonstre(m2);
    // affichageMonstre(m3);
    // printf("%c", choixArme());
    // Player *p1, *p2;
    // Player *p1, *p2, *p3, *p4, *p5;
    ListePlayer *lp = createListePlayer();
    // p1 = createPlayer("Antonin");
    // p2 = createPlayer("George");
    // p2 = createPlayer("Pouclet");
    // p3 = createPlayer("Delobel");
    // p4 = createPlayer("Delage");
    // p5 = createPlayer("Zarzour");
    // addPlayer(lp, p2);
    // addPlayer(lp, p5);
    // addPlayer(lp, p1);
    // addPlayer(lp, p3);
    // addPlayer(lp, p4);
    // printf("\n\n\n\n\n");
    // affichageListePlayer(*lp);
    // addPlayer(lp, p2);
    // addPlayer(lp, p3);
    // addPlayer(lp, p4);
    // affichageListePlayer(*lp);
    // printf("\n\n\n\n\n");
    // affichagePlayer(getHeadPlayer(*lp));
    // removeHeadPlayer(lp);
    // printf("\n\n\n\n\n");
    // affichageListePlayer(*lp);
    // printf("\n\n\n\n\n");
    // affichagePlayer(getHeadPlayer(*lp));

    // affichagePlayer(p1);
    // combat1(p1, &l);
    // affichagePlayer(*p1);
    // getchar();
    // l = addMonster(l, m2);
    // combat1(p2, &l);
    // affichagePlayer(*p2);
    // printf("Joueur 1");
    // p1->score += 5;
    printf("\nBefore\n\n\n");
    tScore = load(lp, tScore, &nb);
    printf("\n\nAfter\n");
    // printf("\n\nJoueur 2");
    // tScore = saveScore(*p2, tScore, &nb);
    // printf("\n\n\n\n\n");
    // affichageScore(tScore[0]);
    printf("Test\n");
    affichageListeScore(tScore, nb);
    printf("\n\n\n\n\n");
    affichageListePlayer(*lp);
    // save(lp, tScore, nb);
    // printf("test\n");
    // affichagePlayer(*lp);
    // Contexte(0);
    // printf("\n\n\n");
    // m1 = monsterlvl1("Goblin");
    // m2 = monsterlvl1("Orc");
    // m3 = monsterlvl1("Troll");
    // l = createListeMonstre();
    // l = addMonster(l, m1);
    // l = addMonster(l, m2);
    // l = addMonster(l, m3);
    // p1->hp += 5;
    // clear();

    // combat2(p1, l);
    // simulateTyping("Bienvenue dans le jeu.     ", 20000);
}

int main(void)
{
    test();
    return 0;
}

// typedef enum
// {
//     playerMort,
//     monstreMort
// } Resultat;
