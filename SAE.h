#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char pseudo[32];
    int hp, *score, ngame;
} Player;

typedef struct
{
    char name[16];
    int hp, damage, weapon, level;
} Monster;