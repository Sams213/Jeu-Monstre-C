#include "sae.h"

void test(void)
{
    Monster m1, m2, m3;
    char c1 = 'P', c2 = 'F', c3 = 'C', c4 = '#', c5 = 'O';
    int r, N = 10;
    m1 = monsterlvl1("Hasbani");
    m2 = monsterlvl2("sami");
    m3 = monsterlvl3("ghassan");
    affichageMonstre(m1);
    affichageMonstre(m2);
    affichageMonstre(m3);
    // r=ResultatDuel(c1,c2);
}

int main(void)
{
    // test();
    return 0;
}

typedef enum
{
    playerMort,
    monstreMort
} Resultat;