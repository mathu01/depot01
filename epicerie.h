#include "article.c"
struct cellule
{
    article UnArcticle;
    struct cellule *suivant;
};

typedef  struct cellule cellule;

cellule *Epicerie = NULL;
cellule* sousEpicerie = NULL;
cellule* insererArticle(cellule* Epi/*,article unArticle*/);
cellule* insereracticle(cellule* epic,article elementTrouve);
void afficherEpicerie(cellule* Epicerie);
cellule* rechercheArticle(cellule* Epicerie);
cellule* retirerArticle(cellule* Epicerie);
double prixmoyen(cellule* sousListe);
void supprimer(cellule* Epicerie);
void vente(cellule* souslist);
double calculquanti(cellule* liste);
cellule* affichevente(cellule*);
