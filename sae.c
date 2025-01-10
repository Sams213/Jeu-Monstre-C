#include "sae.h"

void clear(void)
{
#ifdef _WIN32
    system("cls"); // Pour Windows
#else
    system("clear"); // Pour Linux/macOS
#endif
}

void simulateTyping(char *str, int delay)
{
    while (*str)
    {
        printf("%c", *str);
        fflush(stdout);
        usleep(delay);
        str++;
    }
}

int generate_random_number(int x)
{
    static int initialized = 0;
    if (!initialized)
    {
        srand(time(NULL));
        initialized = 1;
    }
    int random_number = rand() % (x + 1);
    return random_number;
}

Player *createPlayer(char pseudo[])
{
    Player *p = (Player *)malloc(sizeof(Player));
    strcpy(p->pseudo, pseudo);
    p->hp = 20;
    p->score = 0;
    p->ngame = 0;
    strcpy(p->weapons, "PFC");
    p->degats = 1;
    p->suiv = NULL;
    return p;
}

ListePlayer *createListePlayer(void)
{
    ListePlayer *l = (ListePlayer *)malloc(sizeof(ListePlayer));
    if (l == NULL)
    {
        exit(1);
    }
    l->first = NULL;
    l->last = NULL;
    return l;
}

void addPlayerEnTete(ListePlayer *l, Player *p)
{
    if (l->first == NULL)
    {
        l->first = p;
        l->last = p;
        return;
    }
    p->suiv = l->first;
    l->first = p;
}

void addPlayerEnQueue(ListePlayer *l, Player *p)
{
    if (l->last == NULL)
    {
        l->first = p;
        l->last = p;
        return;
    }
    l->last->suiv = p;
    l->last = p;
}

void addPlayer(ListePlayer *lp, Player *p)
{
    if (lp->first == NULL)
    {
        printf("Debut\n");
        addPlayerEnTete(lp, p);
        return;
    }
    Player *tmp = lp->first;
    if (strcmp(lp->first->pseudo, p->pseudo) > 0)
    {
        printf("Avant %s\t%d\n", tmp->pseudo, strcmp(tmp->pseudo, p->pseudo));
        addPlayerEnTete(lp, p);
        return;
    }
    while (true)
    {
        if (tmp->suiv == NULL)
        {
            printf("Fin\n");
            addPlayerEnQueue(lp, p);
            break;
        }

        if (strcmp(tmp->suiv->pseudo, p->pseudo) == 0)
        {
            printf("Same\n");
            break;
        }

        if (strcmp(tmp->suiv->pseudo, p->pseudo) > 0)
        {
            printf("Avant %s\t%d\n", tmp->suiv->pseudo, strcmp(tmp->suiv->pseudo, p->pseudo));
            inserer(tmp, p);
            break;
        }

        tmp = tmp->suiv;
    }
}

void inserer(Player *lp, Player *p)
{
    p->suiv = lp->suiv;
    lp->suiv = p;
}

void removeHeadPlayer(ListePlayer *l)
{
    if (l->first == NULL)
    {
        printf("Liste vide\n");
        return;
    }
    Player *tmp = l->first;
    l->first = l->first->suiv;
    if (l->first == NULL)
    {
        l->last = NULL;
    }
    free(tmp);
}

bool estVidePlayer(ListePlayer l)
{
    return l.first == NULL;
}

Player getHeadPlayer(ListePlayer l)
{
    if (l.first == NULL)
    {
        printf("Liste vide\n");
        exit(1);
    }
    return *(l.first);
}

ListeMonstre createListeMonstre(void)
{
    return NULL;
}

ListeMonstre addMonster(ListeMonstre l, Monster m)
{
    Monster *new = (Monster *)malloc(sizeof(Monster));
    if (new == NULL)
    {
        exit(1);
    }
    *new = m;
    new->next = l;
    return new;
}

// DONE
ListeMonstre removeHeadMonster(ListeMonstre l)
{
    if (l == NULL)
    {
        return NULL;
    }
    Monster *tmp = l->next;
    free(l);
    return tmp;
}

// DONE
bool estVide(ListeMonstre l)
{
    return l == NULL;
}

// DONE
Monster getHeadMonster(ListeMonstre l)
{
    return *l;
}

Monster monsterlvl1(char *c)
{
    Monster *m = (Monster *)malloc(sizeof(Monster));
    strcpy(m->name, c);
    m->hp = 4;
    m->damage = 1;
    strcpy(m->weapons, "PFCO");
    m->level = 1;
    m->next = NULL;
    return *m;
}

Monster monsterlvl2(char *c)
{
    Monster *m = (Monster *)malloc(sizeof(Monster));
    strcpy(m->name, c);
    m->hp = 6;
    m->damage = 2;
    strcpy(m->weapons, "PFC");
    m->level = 2;
    m->next = NULL;
    return *m;
}

/**
 * @brief create a monster level 2 as it is specify in the subject
 *
 * @param c
 * @return Monster
 */
Monster monsterlvl3(char *c)
{
    Monster *m = (Monster *)malloc(sizeof(Monster));
    strcpy(m->name, c);
    m->hp = 8;
    m->damage = 3;
    strcpy(m->weapons, "PFCO#");
    m->level = 3;
    m->next = NULL;
    return *m;
}

void affichagePlayer(Player p)
{
    printf("\n%-15s  hp: %-5d  score: %-5d  nombre de parties: %-5d\n", p.pseudo, p.hp, p.score, p.ngame);
    printf("Ses armes sont: \n- %-10s\n- %-10s\n- %-10s\n", "Pierre", "Feuille", "Ciseaux");
}

void affichageListePlayer(ListePlayer l)
{
    Player *tmp = l.first;
    while (tmp->suiv != NULL)
    {
        affichagePlayer(*tmp);
        tmp = tmp->suiv;
    }
    affichagePlayer(*tmp);
}

void affichageMonstre(Monster m)
{
    printf("\n%-15s  hp: %-5d  degats: %-5d  niveau de monstre: %-5d\n", m.name, m.hp, m.damage, m.level);
    printf("Ses armes sont: \n- %-10s\n- %-10s\n- %-10s\n", "Pierre", "Feuille", "Ciseaux");
    if (m.level == 1)
        printf("- %-10s\n", "BonneARien");
    if (m.level == 3)
        printf("- %-10s\n- %-10s\n", "BonneARien", "BonneATout");
}

// DONE
void afficherListeMonstre(ListeMonstre l)
{
    int i = 1;
    Monster *tmp = l;
    while (tmp != NULL)
    {
        affichageMonstre(*tmp);
        tmp = tmp->next;
    }
}

int hauteurListeMonstre(ListeMonstre l)
{
    int hauteur = 0;
    Monster *tmp = l;
    while (tmp != NULL)
    {
        hauteur++;
        tmp = tmp->next;
    }
    return hauteur;
}

int ResultatDuel(Player *p, Monster *m) // playerWeapon = joueur, return 0 for a draw,-1 for a lose, 1 for a win
{
    int result = 0;
    char playerWeapon = choixArme();
    char monsterWeapon = m->weapons[generate_random_number(4)];
    if (playerWeapon == monsterWeapon) // compares two char, returns 0 if equal
        result = 0;
    else if (playerWeapon == 'P' && monsterWeapon == 'F')
        result = -1;
    else if (playerWeapon == 'P' && monsterWeapon == 'C')
        result = 1;
    else if (playerWeapon == 'F' && monsterWeapon == 'C')
        result = -1;
    else if (playerWeapon == 'F' && monsterWeapon == 'P')
        result = 1;
    else if (playerWeapon == 'C' && monsterWeapon == 'F')
        result = 1;
    else if (playerWeapon == 'C' && monsterWeapon == 'P')
        result = -1;
    else if (monsterWeapon == '#')
        result = -1;
    else
        result = 1;
    clear();
    if (result == 0)
    {
        printf("Egalité, recommencez\n");
    }
    if (result == -1)
    {
        p->hp -= m->damage;
        if (p->hp < 0)
            p->hp = 0;
        printf("Vous avez perdu, il vous reste %d hp\n", p->hp);
    }
    if (result == 1)
    {
        m->hp -= p->degats;
        p->score = p->score + 10;
        printf("Vous avez gagné, il reste %d hp au monstre\n", m->hp);
    }
    return result;
}

// DONE
char choixArme(void)
{
    char c;
    printf("Choisissez votre arme parmis P (pierre), F (Feuille) ou C (Ciseaux) : ");
    scanf("%c%*c", &c);
    while (c != 'P' && c != 'F' && c != 'C' && c != 'p' && c != 'f' && c != 'c')
    {
        printf("Choisissez votre arme parmis P (pierre), F (Feuille) ou C (Ciseaux) : ");

        scanf("%c%*c", &c);
    }
    if (c == 'c')
        c = 'C';
    if (c == 'f')
        c = 'F';
    if (c == 'p')
        c = 'P';

    return c;
}

// DONE
bool estMortPlayer(Player p)
{
    return p.hp <= 0;
}

// DONE
bool estMortMonster(Monster m)
{
    return m.hp <= 0;
}

int combat1(Player *p, ListeMonstre l)
{
    while (!estVide(l))
    {
        int result;
        Monster *m = l;
        printf("\nVotre score est de %d\n", p->score);
        while (!estMortPlayer(*p) && !estMortMonster(*m))
        {
            afficherListeMonstre(l);
            printf("\n\n\n\n\n");
            result = ResultatDuel(p, m);
        }

        if (estMortPlayer(*p))
        {
            Contexte(-1);
            affichagePlayer(*p);
            afficherListeMonstre(l);
            return -1;
        }
        if (estMortMonster(*m))
        {
            l = removeHeadMonster(l);
            printf("Vous avez battu %s\nIl vous reste %d hp\nIl reste %d monstres à affronter.", m->name, p->hp, hauteurListeMonstre(l));
            p->score += m->level * 50;
        }
    }
    return 1;
}

int combat2(Player *p, ListeMonstre l)
{
    Monster *tmp = l;
    while (!estVide(l))
    {
        afficherListeMonstre(l);
        printf("\n\n\n\n\n");
        printf("\nVous affrontez %s\n\n", tmp->name);
        ResultatDuel(p, tmp);
        if (estMortPlayer(*p))
        {
            Contexte(-1);
            affichagePlayer(*p);
            afficherListeMonstre(l);
            return -1;
        }
        if (estMortMonster(*tmp))
        {
            l = removeHeadMonster(l);
            printf("Vous avez battu %s\nIl vous reste %d hp\nIl reste %d monstres à affronter.", tmp->name, p->hp, hauteurListeMonstre(l));
            p->score += tmp->level * 100;
        }
        if (tmp->next == NULL)
            tmp = l;
        else
            tmp = tmp->next;
    }
}

void load(void)
{
}

void save(ListePlayer lp)
{
}

int ExperienceRound1(Monster m, Player p) // state = 1 pour une attaque gagnée, 2 pour un monstre vaincu m.level pour le niveau du monstre;
{
    p.score = p.score + m.level * 50;
}

void AttaqueGagnee(Player p)
{
    p.score = p.score + 10;
}

int ExperienceRound2(Monster m, Player p) // state = 1 pour une attaque gagnée, 2 pour un monstre vaincu
// m.level pour le niveau du monstre;
{
    p.score = p.score + m.level * 100;
}

// DONE
int NouvelleHPmonster1(int hp) // nouveeau HP apres la bataille avec monstre lvl 1 et lvl 2
{
    hp--;
    return hp;
}

// DONE
void NouvelleHPmonster3(Player p) // nouveeau HP apres la bataille avec monstre lvl 3
{
    p.hp = p.hp - 3;
}

void Contexte(int phase)
{
    printf("\nContexte: \n");
    if (phase == 1)
        printf("vous arrivez dans un corridor, bordé par deux falaises des monstres arrivent les uns après les autres");
    if (phase == 2)
        printf("vous arrivez au bout du corridor, une plaine herbeuse apparaît. Malheureusement des monstres sortent de partout pour tous vous attaquer en même temps ou presque...");
    if (phase == -1)
        printf("Vous êtes mort, vous avez perdu la partie\n\n");
    if (phase == 0)
    {
        simulateTyping("Vous avez triomphé contre la 1ere horde de monstre, en allant chercher de quoi manger, vous trouvez une baie magique qui vous rend +5hp supplémentaire, avant de tomber sur un groupe de monstre qui ont l'air un peu plus fort que le 1er groupe, vous allez devoir les affronter.", 1000);
        printf("\n\nAppuyez sur entrée pour continuer...\n");
        getchar();
    }
}

void Menu(void)
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
    scanf("%d", &choix);
    printf("%d\n", choix);

    switch (choix)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 9:
        exit(0);
    default:
        clear();
        Menu();
    }
}
