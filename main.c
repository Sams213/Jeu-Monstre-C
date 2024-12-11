#include "sae.h"

void test(void)
{
    Monster m1, m2, m3;
    m1 = monsterlvl1("Hasbani");
    m2 = monsterlvl2("sami");
    m3 = monsterlvl3("ghassan");
    affichageMonstre(m1);
    affichageMonstre(m2);
    affichageMonstre(m3);
}


int main(void)
{
    test();
    return 0;
}