#include "sae.h"

void test(void)
{
    clear();
    Monster m1, m2, m3, *l;
    Player *p1, *p2, *p3, *p4;
    l = createListeMonstre();
    char c1 = 'P', c2 = 'F', c3 = 'C', c4 = '#', c5 = 'O';
    int r, N = 10;
    m1 = monsterlvl1("Hasbani");
    // m2 = monsterlvl1("sami");
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
    ListePlayer *lp = createListePlayer();
    p1 = createPlayer("Antonin");
    p2 = createPlayer("Pouclet");
    p3 = createPlayer("Delobel");
    p4 = createPlayer("Delage");
    addPlayer(lp->first, p1);
    addPlayer(lp->first, p2);
    affichageListePlayer(*lp);
    addPlayer(lp->first, p3);
    printf("\n\n\n\n\n");
    affichageListePlayer(*lp);
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
    // combat1(p1, l);
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
