#include "epicerie.h"


cellule* insererArticle(cellule* Epi/*,article UnArticle*/){
    cellule* NouvelleListe;
    article art;
    art = infoarticle();
    NouvelleListe = (cellule*)malloc(sizeof(cellule));
    NouvelleListe->UnArcticle = art;
    NouvelleListe->suivant = NULL;
    if (Epi == NULL)
    {
        return NouvelleListe;
    }
    else{
        cellule *parcours,*prec;
        parcours = Epi;
        do
        {
            if (strcmp(parcours->UnArcticle.nom,art.nom)==0 && parcours->UnArcticle.prix==art.prix)
            {
                parcours->UnArcticle.quantite += art.quantite;
                return Epi;
            }
            prec = parcours;
            parcours=parcours->suivant;
        } while(parcours != NULL);
        prec->suivant = NouvelleListe;
        return Epi;
    }
    
}

void afficherEpicerie(cellule* epicerie){
    if (epicerie == NULL)
    {
        printf("\nVotre epicerie est vide\n ");
    }
    else{
        cellule* pointeurListe;
        pointeurListe = epicerie;
        int i = 0;
        while (pointeurListe != NULL)
        {
            printf("\n\t\tARTICLE %d",++i);
            afficher(pointeurListe->UnArcticle);
            pointeurListe = pointeurListe->suivant;
            printf("\n");
        }
        printf("\n");
        //printf("\nNous avons %d elements dans l epicerie\n",i);
        
    }
    return;
}
cellule* insereracticle(cellule* epic,article art){
    cellule* NouvelleListe;
    NouvelleListe = (cellule*)malloc(sizeof(cellule));
    NouvelleListe->UnArcticle = art;
    NouvelleListe->suivant = NULL;
    if (epic == NULL)
    {
        return NouvelleListe;
    }
    else{
        cellule* parcours;
        parcours = epic;
        while (parcours->suivant != NULL)
        {
            parcours=parcours->suivant;
        }
        parcours->suivant = NouvelleListe;
        return epic;
    }

}
cellule* rechercheArticle(cellule* Epiceri){
    if (Epiceri == NULL)
    {
        // printf("\nAucun element disponible pour le moment\n");
        return NULL;
    }
    else{
        // int i=0;
        char nm[N];
        //float price;
        cellule *pointeur = Epiceri;
        cellule *list = NULL;
        printf("\nEntrez le nom de l article que vous cherchez ");
        scanf("%s",nm);
        // printf("\nEntrez son prix unitaire ");
        // scanf("%f",&price);
        while (pointeur != NULL)
        {
            if (strcmp(pointeur->UnArcticle.nom,nm)==0)
            {
                list = insereracticle(list,pointeur->UnArcticle);
            }
            pointeur=pointeur->suivant;  
            // i++;  
        }
        return list;
    }  
}

cellule* retirerArticle(cellule* Epicerie){
    if (Epicerie == NULL)
    {
        printf("\nListe vide");
        return NULL;
    }
    else{
        char no[N];
        float pr;
        cellule *precedent,*parcours;
        printf("\nEntrez le nom de l epecice a retirer ");
        scanf("%s",no);
        printf("\nEntrez le prix unitaire ");
        scanf("%f",&pr);
        precedent=Epicerie;
        if (strcmp(precedent->UnArcticle.nom,no)==0 && precedent->UnArcticle.prix==pr)
        {
            Epicerie = precedent->suivant;
            free(precedent);
            return Epicerie;
        }
        else{
            parcours = precedent->suivant;
            while (parcours != NULL)
            {
                if (strcmp(parcours->UnArcticle.nom,no)==0 && parcours->UnArcticle.prix==pr)
                {
                    precedent->suivant = parcours->suivant;
                    free(parcours);
                }
                precedent = parcours;
                parcours = parcours->suivant;  
            }
            return Epicerie; 
        }
    }
}

double prixmoyen(cellule* sousListe){
    if (sousListe == NULL)
    {
        return 0;
    }
    else{
        double px,somprix=0,somquantite=0;
        cellule* pointeur;
        pointeur = sousListe;
        while (pointeur != NULL)
        {
            somprix += pointeur->UnArcticle.prix * pointeur->UnArcticle.quantite;
            somquantite += pointeur->UnArcticle.quantite;
            pointeur = pointeur->suivant;
        }
        px = somprix/somquantite;
        return px;
    }
}

void supprimer(cellule* Epicerie){
    cellule *previous, *next;
    previous =Epicerie;
    next = Epicerie->suivant;
    do
    {
        free(previous);
        previous = next;
        next = next->suivant;
    } while (next != NULL); 
}
double calculquanti(cellule* liste){
    cellule* pt;
    double p = 0;
    pt = liste;
    while (pt !=NULL)
    {
        p += pt->UnArcticle.quantite;
        pt = pt->suivant;
    }
    return p;
}
void vente(cellule* Epicerie){
    cellule* stock = NULL;
    stock = rechercheArticle(Epicerie);
    if (stock ==NULL)
    {
        printf("\nEpice non disponible pour le moment\n");
    }
    else{
        cellule* pointa;
        double qt,voulu;
        float owo = 0;
        qt = calculquanti(stock);
        pointa = Epicerie;
        printf("\nEntrez la quantite que vous voulez payer ");
        scanf("%lf",&voulu);
        if (qt < voulu)
        {
            printf("\nLa quantite disponible est unsiffisante a votre demande\n");
        }
        else{
            while (pointa != NULL && voulu != 0)
            {
                if (strcmp(pointa->UnArcticle.nom,stock->UnArcticle.nom)==0)
                {
                    if (pointa->UnArcticle.quantite < voulu){
                        owo  += pointa->UnArcticle.quantite * pointa->UnArcticle.prix;
                        voulu -= pointa->UnArcticle.quantite;
                        pointa->UnArcticle.quantite = 0;
                    }
                    else{
                        owo = voulu * pointa->UnArcticle.prix;
                        pointa->UnArcticle.quantite -= voulu;
                        voulu = 0;
                    }
                }
                pointa = pointa->suivant;
            }
            //afficherEpicerie(Epicerie);
            printf("\nVoici votre addition ");
            printf("\nEpice:\t%s",stock->UnArcticle.nom);
            printf("\nTotal:\t%.2f\n",owo);
        } 
    }   
}

