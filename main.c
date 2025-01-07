#include "sae.h"

void test(void)
{
    Monster m1, m2, m3, *l;
    Player p1;
    l = createListeMonstre();
    char c1 = 'P', c2 = 'F', c3 = 'C', c4 = '#', c5 = 'O';
    int r, N = 10;
    m1 = monsterlvl1("Hasbani");
    m2 = monsterlvl2("sami");
    m3 = monsterlvl3("ghassan");
    l = addMonster(l, m2);
    l = addMonster(l, m3);
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
    p1 = createPlayer("Antonin");
    // affichagePlayer(p1);
    combat1(p1, l);
    printf("\n\n\n");
    affichagePlayer(p1);
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
