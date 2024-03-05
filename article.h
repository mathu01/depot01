#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
struct article {
    char nom[N];
    float prix;
    double quantite;
};

typedef struct article article;
article infoarticle();
article creerarticle(char*,float,double);
void afficher(article);
