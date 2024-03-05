#include "epicerie.c"

int main (){
    int choix;
    double Pmoyen;
    do
    {
        printf("\t\tChoix disponible\n");
        printf("1-inserer un nouvel article\n");
        printf("2-Afficher tous les articles de votre epicerie \n");
        printf("3-Rechercher un article\n");
        printf("4-Retirer un article\n");
        printf("5-Prix moyens d un epice\n");
        printf("6-Vente\n");
        printf("Entrez 0 pour quitter");
        printf("\n\nQuel est votre choix ");
        scanf("%d",&choix);
        switch (choix)
        {
        // case 0:
        //     supprimer(Epicerie);
        //     afficherEpicerie(Epicerie);
        //     break;
        case 1:
            Epicerie = insererArticle(Epicerie);
            break;
        case 2:
            if (Epicerie==NULL)
            {
                printf("\nL epicerie est vide pour le moment \n");
            }
            else{
                printf("\nVoici la listes des articles de votre notre epicerie ");
                afficherEpicerie(Epicerie);
            }
            break;
        case 3:
            sousEpicerie = rechercheArticle(Epicerie);
            if (sousEpicerie==NULL)
            {
                afficherEpicerie(sousEpicerie);
            }
            else{
                printf("\n Resultat de la recherche\n");
                afficherEpicerie(sousEpicerie);
            }
            break;
        case 4:
            Epicerie = retirerArticle(Epicerie);
            printf("\nVoici la liste apres retrait de l article \n");
            afficherEpicerie(Epicerie);
            break;
        case 5:
            sousEpicerie = rechercheArticle(Epicerie);
            Pmoyen = prixmoyen(sousEpicerie);
            if (Pmoyen==0)
            {
                printf("\n Aucun article trouve");
            }
            else 
               printf("\n Le prix moyen de l epice est %.2f F CFA\n",Pmoyen);
            break;
        case 6:
            vente(Epicerie);
            break;
        }
    } while (choix != 0);
    printf("\nTerminer\n");
    system("PAUSE");
    return 0;
}