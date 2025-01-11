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

Player *recherchePlayer(char *c, ListePlayer *lp)
{
    Player *p = lp->first;
    while (p != NULL)
    {
        if (strcmp(p->pseudo, c) == 0)
        {
            p->score = 0;
            return p;
        }
        p = p->suiv;
    }
    printf("Nouveau Joueur\n");
    p = createPlayer(c);
    addPlayer(lp, p);
    return p;
}

int longueur(ListePlayer lp)
{
    int l = 0;
    while (lp.first != NULL)
    {
        l++;
        lp.first = lp.first->suiv;
    }
    return l;
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

// Score *saveScore(Player p, Score tScore[], int *nb)
// {
//     Score *temp;
//     Score s;
//     printf("Pseudo: %s\n", p.pseudo);
//     strcpy(s.name, p.pseudo);
//     s.score = p.score;
//     s.nbParties = p.ngame;
//     printf("Debut\n");
//     if (tScore == NULL)
//     {
//         printf("\nInsertion au debut\n");
//         tScore = (Score *)malloc(sizeof(Score));
//         if (tScore == NULL)
//         {
//             printf("Erreur d'allocation memoire\n");
//         }
//         tScore[0] = s;
//         *nb += 1;
//         return tScore;
//     }
//     printf("reallocA\n");
//     temp = realloc(tScore, ((*nb) + 1) * sizeof(Score));
//     printf("reallocB\n");
//     if (temp == NULL)
//     {
//         printf("Erreur d'allocation memoire\n");
//     }
//     tScore = temp;
//     for (int i = 0; i < *nb; i++)
//     {
//         if (tScore[i].score <= s.score)
//         {
//             for (int j = *nb; j > i; j--)
//             {
//                 tScore[j] = tScore[j - 1];
//             }
//             // printf("\n1) Insertion a l'index %d\n", i);
//             // printf("Test333\n");
//             tScore[i] = s;
//             // printf("Test444\n");
//             *nb += 1;
//             // printf("Test555\n");
//             break;
//         }
//         // printf("\n2)Insertion a l'index %d\n", *nb - 1);
//         *nb += 1;
//         tScore[*nb] = s;
//         break;
//     }
//     // printf("Test666\n");
//     return tScore;
// }

Score *saveScore(Player p, Score tScore[], int *nb)
{
    Score *temp;
    Score s;
    // printf("Pseudo: %s\n", p.pseudo);

    // Initialisation du nouveau score
    strcpy(s.name, p.pseudo);
    s.score = p.score;
    s.nbParties = p.ngame;

    if (tScore == NULL) // Si le tableau est vide
    {
        // printf("\nInsertion au debut\n");
        tScore = (Score *)malloc(sizeof(Score)); // Allouer un tableau d'un element
        if (tScore == NULL)                      // Verifier l'allocation
        {
            printf("Erreur d'allocation memoire\n");
            return NULL; // echec de l'allocation
        }
        tScore[0] = s; // Inserer le premier element
        *nb = 1;       // Initialiser le nombre d'elements
        return tScore;
    }
    // printf("Test\n");

    for (int i = 0; i < *nb; i++)
    {
        if (strcmp(tScore[i].name, s.name) == 0)
        {
            // printf("Test1234\n");
            // printf("score: %d\tScore[0]: %d\n\n", s.score, tScore[0].score);
            if (s.score > tScore[i].score)
            {
                // printf("score: %d\tScore[0]: %d\n\n", s.score, tScore[i].score);
                tScore[i].score = s.score;
                return tScore;
            }
            else
            {
                // printf("return tScore\n");
                return tScore;
            }
        }
    }
    // etendre le tableau avec realloc
    // printf("Realloc : etendre la memoire\n");
    temp = realloc(tScore, ((*nb) + 1) * sizeof(Score));
    if (temp == NULL) // Verifier si realloc a echoue
    {
        // printf("Erreur d'allocation memoire\n");
        return tScore; // Retourner l'ancien tableau inchange
    }
    tScore = temp; // Mise a jour du pointeur avec le nouveau tableau alloue

    // Trouver la position d'insertion
    int insertIndex = *nb; // Par defaut, inserer a la fin
    for (int i = 0; i < *nb; i++)
    {
        if (tScore[i].score <= s.score) // Si un score inferieur est trouve
        {
            insertIndex = i; // Memoriser l'index d'insertion
            break;
        }
    }

    // Decaler les elements pour inserer au bon endroit
    for (int j = *nb; j > insertIndex; j--)
    {
        tScore[j] = tScore[j - 1];
    }

    // Inserer le nouvel element
    tScore[insertIndex] = s;
    (*nb)++; // Incrementer le nombre d'elements

    // printf("Insertion reussie a l'index %d\n", insertIndex);
    return tScore;
}

Score *load(ListePlayer *lp, Score tScore[], int *nb)
{
    int z = 0;
    int score, ngame;
    char pseudo[16];
    FILE *f = fopen("score.txt", "r");
    if (f == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(1);
    }
    fscanf(f, "%d", nb);
    printf("Nombre de joueurs: %d\n", *nb);
    for (int i = 0; i < *nb; i++)
    {
        // printf("\n\n%d\n", i);
        fscanf(f, "%s %d %d", pseudo, &score, &ngame);
        Player *p = createPlayer(pseudo);
        p->score = score;
        p->ngame = ngame;
        // printf("nom: %s\tscore: %d\tngame: %d\n", p->pseudo, p->score, p->ngame);
        addPlayer(lp, p);
        // printf("---------\nz:\t%d\n", z);
        tScore = saveScore(*p, tScore, &z);
        // printf("Test\n");
        // printf("\n%d", i);
        // affichageScore(tScore[i]);
        // printf("\n");
    }
    fclose(f);
    return tScore;
}

void affichageScore(Score s)
{
    printf("%-20s|\t%d\t\t|\t%d\n", s.name, s.nbParties, s.score);
}

void affichageListeScoreRecursive(Score tScore[], int index, int nb)
{
    if (index >= nb) // Condition d'arrêt : tous les scores ont été affichés
        return;

    affichageScore(tScore[index]); // Affiche le score courant

    // Appel récursif pour l'élément suivant
    affichageListeScoreRecursive(tScore, index + 1, nb);
}

void affichageListeScore(Score tScore[], int nb)
{
    printf("%-20s|\t%s\t|\t%s\n", "Pseudo", "NbParties", "Score");
    printf("-------------------------------------------------------------\n");

    affichageListeScoreRecursive(tScore, 0, nb); // Appel de la fonction récursive
}

void addPlayer(ListePlayer *lp, Player *p)
{
    if (lp->first == NULL)
    {
        // printf("Debut\n");
        addPlayerEnTete(lp, p);
        return;
    }
    Player *tmp = lp->first;
    if (strcmp(lp->first->pseudo, p->pseudo) > 0)
    {
        // printf("Avant %s\t%d\n", tmp->pseudo, strcmp(tmp->pseudo, p->pseudo));
        addPlayerEnTete(lp, p);
        return;
    }
    while (true)
    {
        if (tmp->suiv == NULL)
        {
            // printf("Fin\n");
            addPlayerEnQueue(lp, p);
            break;
        }

        if (strcmp(tmp->suiv->pseudo, p->pseudo) == 0)
        {
            // printf("Same\n");
            break;
        }

        if (strcmp(tmp->suiv->pseudo, p->pseudo) > 0)
        {
            // printf("Avant %s\t%d\n", tmp->suiv->pseudo, strcmp(tmp->suiv->pseudo, p->pseudo));
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

Monster monsterlvl7(char *c)
{
    Monster *m = (Monster *)malloc(sizeof(Monster));
    strcpy(m->name, c);
    m->hp = 10;
    m->damage = 3;
    strcpy(m->weapons, "PFC##");
    m->level = 8;
    m->next = NULL;
    return *m;
}

void affichagePlayer(Player p)
{
    printf("%-20s | %-8d | %-8d | %-8d\n", p.pseudo, p.hp, p.score, p.ngame);
}

void affichageListePlayer(ListePlayer l)
{
    printf("%-20s | %-8s | %-8s | %-8s\n", "Pseudo", "HP", "Score", "Ngame");
    printf("---------------------|----------|----------|----------\n");
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
        printf("Egalite, recommencez\n");
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
        printf("Vous avez gagne, il reste %d hp au monstre\n", m->hp);
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
        while (getchar() != '\n')
            ;
        printf("Arme non reconnue, choisissez bien parmis P (pierre), F (Feuille) ou C (Ciseaux) : ");

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

int combat1(Player *p, ListeMonstre *l)
{
    clear();
    while (!estVide(*l))
    {
        int result;
        Monster *m = *l;

        while (!estMortPlayer(*p) && !estMortMonster(*m))
        {
            printf("\nVotre score est de %d\n", p->score);
            afficherListeMonstre(*l);
            printf("\n\n\n\n\n");
            result = ResultatDuel(p, m);
        }

        if (estMortPlayer(*p))
        {
            Contexte(-1);
            affichagePlayer(*p);
            afficherListeMonstre(*l);
            return -1;
        }
        if (estMortMonster(*m))
        {
            *l = removeHeadMonster(*l);
            printf("Vous avez battu %s\nIl vous reste %d hp\nIl reste %d monstres a affronter.", m->name, p->hp, hauteurListeMonstre(*l));
            p->score += m->level * 50;
        }
    }
    printf("\nVotre score est de %d\n", p->score);
    p->ngame += 1;
    return 1;
}

int combat2(Player *p, ListeMonstre *l)
{
    Monster *tmp = *l;
    while (!estVide(*l))
    {
        afficherListeMonstre(*l);
        printf("\n\n\n");
        printf("\nVous affrontez %s\n\n", tmp->name);
        ResultatDuel(p, tmp);
        if (estMortPlayer(*p))
        {
            Contexte(-1);
            affichagePlayer(*p);
            afficherListeMonstre(*l);
            return -1;
        }
        if (estMortMonster(*tmp))
        {
            *l = removeHeadMonster(*l);
            printf("Vous avez battu %s\nIl vous reste %d hp\nIl reste %d monstres a affronter.", tmp->name, p->hp, hauteurListeMonstre(*l));
            p->score += tmp->level * 100;
        }
        if (tmp->next == NULL)
            tmp = *l;
        else
            tmp = tmp->next;
    }
}

Player *lirePlayer(FILE *f)
{
    char pseudo[16];
    int score, ngame;
    Player *p = (Player *)malloc(sizeof(Player));
    if (p == NULL)
    {
        printf("Erreur d'allocation memoire\n");
        exit(1);
    }
    // printf("TestLirePlayer\n");
    fscanf(f, "%s %d %d", pseudo, &score, &ngame);
    // printf("TestLirePlayer1\n");
    printf("nom: %s\tscore: %d\tngame: %d\n", pseudo, &score, &ngame);
    // printf("TestLirePlayer2\n");
    return p;
}

void save(ListePlayer *lp, Score tScore[], int nb)
{
    FILE *f = fopen("score.txt", "w");
    if (f == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit(1);
    }
    fprintf(f, "%d\n", nb);
    for (int i = 0; i < nb; i++)
    {
        fprintf(f, "%s %d %d\n", tScore[i].name, tScore[i].score, tScore[i].nbParties);
    }
    fclose(f);
}

void statistiques(Score tscore[], int n)
{
    printf("Quelle recherche voulez-vous effectuer ?\n");
    printf("1. Recherche par pseudo\n");
    printf("2. Recherche par score\n");
    int choix;
    scanf("%d", &choix);
    while (getchar() != '\n')
        ;
    if (choix == 1)
    {
        printf("Entrez le pseudo du joueur dont vous voulez afficher les statistiques: ");
        char pseudo[16];
        scanf("%s", pseudo);
        int i;
        for (i = 0; i < n; i++)
        {
            if (strcmp(tscore[i].name, pseudo) == 0)
            {
                printf("Statistiques du joueur %s:\n", pseudo);
                printf(" - Score total: %d\n", tscore[i].score);
                printf(" - Nombre de parties: %d\n", tscore[i].nbParties);
                return;
            }
        }
        printf("Aucun joueur avec le pseudo %s n'a ete trouve\n", pseudo);
    }
    if (choix == 2)
    {
        printf("Entrez le score minimal que vous voulez afficher: ");
        int score;
        scanf("%d", &score);
        rechercheDichotomiqueScore(tscore, n, score);
    }
}

void rechercheDichotomiqueScore(Score tScore[], int nb, int n)
{
    if (nb == 0)
    {
        printf("Aucun joueur n'a un score superieur a %d\n", n);
        return;
    }

    printf("%-20s|\t%s\t|\t%s\n", "Pseudo", "NbParties", "Score");
    printf("-------------------------------------------------------------\n");

    bool found = false;
    for (int i = 0; i < nb; i++)
    {
        if (tScore[i].score > n)
        {
            affichageScore(tScore[i]);
            found = true;
        }
    }

    if (!found)
    {
        printf("Aucun joueur n'a un score superieur a %d\n", n);
    }
}

void Contexte(int phase)
{
    clear();
    if (phase == 1)
    {
        simulateTyping("vous arrivez dans un corridor, borde par deux falaises des monstres arrivent les uns apres les autres", DELAY);
        printf("\n\nAppuyez sur entree pour continuer...\n");
        getchar();
    }
    if (phase == 2)
    {
        simulateTyping("vous arrivez au bout du corridor, une plaine herbeuse apparaît. Malheureusement des monstres sortent de partout pour tous vous attaquer en meme temps ou presque...", DELAY);
        printf("\n\nAppuyez sur entree pour continuer...\n");
        getchar();
        clear();
    }
    if (phase == -1)
    {
        printf("Vous etes mort, vous avez perdu la partie\n\n");
        printf("\n\nAppuyez sur entree pour continuer...\n");
        getchar();
        clear();
    }
    if (phase == 0)
    {
        simulateTyping("Vous avez triomphe contre la 1ere horde de monstre, en allant chercher de quoi manger, vous trouvez une baie magique qui vous rend +5hp supplementaire, avant de tomber sur un groupe de monstre qui ont l'air un peu plus fort que le 1er groupe, vous allez devoir les affronter.", DELAY);
        printf("\n\nAppuyez sur entree pour continuer...\n");
        getchar();
        clear();
    }
    if (phase == 3)
    {
        simulateTyping("Vous avez triomphe contre la 2eme horde de monstre, en allant chercher de quoi manger, vous trouvez une baie magique qui vous rend +2hp supplementaire, avant de tomber sur un groupe de monstre qui ont l'air beaucoup plus fort que le 1er groupe, vous allez devoir les affronter.", DELAY);
        printf("\n\nAppuyez sur entree pour continuer...\n");
        getchar();
        clear();
    }
}

void Menu(Player *p, Score *tScore[], int *nb, ListePlayer *lp)
{
    while (true)
    {
        int choix;
        printf("------------- Menu -------------\n");
        printf("1. jouer une partie predefinie\n");
        printf("2. creer une nouvelle partie\n");
        printf("3. afficher la liste des joueurs triee par nom\n");
        printf("4. afficher la liste des joueurs triee par meilleur score\n");
        printf("5. afficher les statistiques d'un joueur\n");
        printf("9. Quitter\n");
        printf("--------------------------------\n");

        printf("choix: ");
        scanf("%d", &choix);
        printf("%d\n", choix);

        while (getchar() != '\n')
            ;

        switch (choix)
        {
        case 1:
            int choix2;
            clear();
            simulateTyping("Vous avez choisi de jouer une partie predefinie\n", DELAY);
            simulateTyping("Quelle nom de fichier voulez vous prendre pour la partie predefinie", DELAY);
            printf("1. facile.txt\n");
            printf("2. moyen.txt\n");
            printf("3. difficile.txt\n");
            printf("4. Final Boss\n");
            printf("5. Retour\n");
            scanf("%d", &choix2);
            while (getchar() != '\n')
                ;
            switch (choix2)
            {
            case 1:
                p->score = 0;
                p->hp = 20;
                ListeMonstre l1 = createListeMonstre();
                Monster m1 = monsterlvl1("Goblin");
                Monster m2 = monsterlvl1("Orc");
                Monster m3 = monsterlvl1("Troll");
                l1 = addMonster(l1, m1);
                l1 = addMonster(l1, m2);
                l1 = addMonster(l1, m3);
                combat1(p, &l1);
                if (estMortPlayer(*p))
                {
                    Contexte(-1);
                    affichagePlayer(*p);
                }
                else
                {
                    Contexte(0);
                    Monster m4 = monsterlvl1("Elfe");
                    Monster m5 = monsterlvl1("Sorciere");
                    Monster m6 = monsterlvl2("Dragon");
                    l1 = addMonster(l1, m4);
                    l1 = addMonster(l1, m5);
                    l1 = addMonster(l1, m6);
                    combat2(p, &l1);
                }
                if (estMortPlayer(*p))
                {
                    Contexte(-1);
                    affichagePlayer(*p);
                }
                else
                {
                    printf("Vous avez triomphez de tous les monstres, vous avez gagne la partie\n");
                }
                *tScore = saveScore(*p, *tScore, nb);
                save(lp, *tScore, *nb);
                printf("\n\nAppuyez sur entree pour continuer...");
                getchar();
                clear();
                Menu(p, tScore, nb, lp);
            case 2:
                p->score = 0;
                p->hp = 20;
                ListeMonstre l2 = createListeMonstre();
                Monster m7 = monsterlvl2("Goblin");
                Monster m8 = monsterlvl1("Orc");
                Monster m9 = monsterlvl1("Troll");
                l2 = addMonster(l2, m7);
                l2 = addMonster(l2, m8);
                l2 = addMonster(l2, m9);
                combat1(p, &l2);
                Contexte(0);
                Monster m10 = monsterlvl1("Elfe");
                Monster m11 = monsterlvl2("Sorciere");
                Monster m12 = monsterlvl2("Dragon");
                l2 = addMonster(l2, m10);
                l2 = addMonster(l2, m11);
                l2 = addMonster(l2, m12);
                combat2(p, &l2);
                if (estMortPlayer(*p))
                {
                    Contexte(-1);
                    affichagePlayer(*p);
                }
                else
                {
                    printf("Vous avez triomphez de tous les monstres, vous avez gagne la partie\n");
                }
                *tScore = saveScore(*p, *tScore, nb);
                save(lp, *tScore, *nb);
                printf("\n\nAppuyez sur entree pour continuer...");
                getchar();
                clear();
                Menu(p, tScore, nb, lp);
            case 3:
                p->score = 0;
                p->hp = 20;
                ListeMonstre l3 = createListeMonstre();
                Monster m13 = monsterlvl3("Goblin");
                Monster m14 = monsterlvl2("Orc");
                Monster m15 = monsterlvl2("Troll");
                l3 = addMonster(l3, m13);
                l3 = addMonster(l3, m14);
                l3 = addMonster(l3, m15);
                combat1(p, &l3);
                Contexte(0);
                Monster m16 = monsterlvl2("Elfe");
                Monster m17 = monsterlvl3("Sorciere");
                Monster m18 = monsterlvl3("Dragon");
                l3 = addMonster(l3, m16);
                l3 = addMonster(l3, m17);
                l3 = addMonster(l3, m18);
                combat2(p, &l3);
                if (estMortPlayer(*p))
                {
                    Contexte(-1);
                    affichagePlayer(*p);
                }
                else
                {
                    printf("Vous avez triomphez de tous les monstres, vous avez gagne la partie\n");
                }
                *tScore = saveScore(*p, *tScore, nb);
                save(lp, *tScore, *nb);
                printf("\n\nAppuyez sur entree pour continuer...");
                getchar();
                clear();
                Menu(p, tScore, nb, lp);
            case 4:
                p->score = 0;
                p->hp = 20;
                ListeMonstre l5 = createListeMonstre();
                Monster m0 = monsterlvl7("Mr.Hasbani");
                l5 = addMonster(l5, m0);
                combat1(p, &l5);
                if (estMortPlayer(*p))
                {
                    Contexte(-1);
                    affichagePlayer(*p);
                }
                else
                {
                    printf("Vous avez triomphez du Boss Final, vous aurez plus 5 points sur le prochain DS d'algorithmie, vous avez gagne la partie\n");
                    p->score += 8387;
                }

                *tScore = saveScore(*p, *tScore, nb);
                save(lp, *tScore, *nb);
                printf("\n\nAppuyez sur entree pour continuer...");
                getchar();
                clear();
                Menu(p, tScore, nb, lp);

            case 5:
                clear();
                Menu(p, tScore, nb, lp);
            }
        case 2:
            // Contexte(1);
            p->score = 0;
            p->hp = 20;
            ListeMonstre l = createListeMonstre();
            Monster m1 = monsterlvl1("Goblin");
            Monster m2 = monsterlvl1("Orc");
            Monster m3 = monsterlvl1("Troll");
            l = addMonster(l, m1);
            l = addMonster(l, m2);
            l = addMonster(l, m3);
            combat1(p, &l);
            Contexte(0);
            Monster m4 = monsterlvl1("Elfe");
            Monster m5 = monsterlvl2("Sorciere");
            Monster m6 = monsterlvl2("Dragon");
            l = addMonster(l, m4);
            l = addMonster(l, m5);
            l = addMonster(l, m6);
            combat2(p, &l);
            if (!estMortPlayer(*p))
            {
                Contexte(3);
                Monster m7 = monsterlvl3("Geant");
                Monster m8 = monsterlvl3("Hydre");
                Monster m9 = monsterlvl3("Kraken");
                l = addMonster(l, m7);
                l = addMonster(l, m8);
                l = addMonster(l, m9);
                combat2(p, &l);
            }
            if (estMortPlayer(*p))
            {
                Contexte(-1);
                affichagePlayer(*p);
            }
            else
            {
                printf("Vous avez triomphez de tous les monstres, vous avez gagne la partie\n");
            }
            *tScore = saveScore(*p, *tScore, nb);
            save(lp, *tScore, *nb);
            printf("\n\nAppuyez sur entree pour continuer...");
            getchar();
            clear();
            break;
        case 3:
            clear();
            affichageListePlayer(*lp);
            printf("\n\nAppuyez sur entree pour continuer...");
            getchar();
            clear();
            break;
        case 4:
            clear();
            affichageListeScore(*tScore, *nb);
            printf("\n\nAppuyez sur entree pour continuer...");
            getchar();
            clear();
            break;
        case 5:
            statistiques(*tScore, *nb);
            printf("\n\nAppuyez sur entree pour continuer...");
            while (getchar() != '\n')
                ;

            getchar();
            clear();
            break;
        case 9:
            printf("Au revoir...");
            usleep(1000);
            exit(0);
        default:
            Menu(p, tScore, nb, lp);
        }
    }
}
