#include "article.h"


article infoarticle(){
    char name[N];
    float pri;
    double quant;
    article Artcle;
    printf("\n Entrez le nom de l article ");
    scanf("%s",name);
    printf("\n Entrez le prix unitaire ");
    scanf("%f",&pri);
    printf("\nEntrez la quantite de l article en stock ");
    scanf("%lf",&quant);
    Artcle = creerarticle(name,pri,quant);
    return Artcle;
}
article creerarticle(char name[],float pri,double quant){
    article NouveauArticle;
    strcpy(NouveauArticle.nom,name);
    NouveauArticle.prix=pri;
    NouveauArticle.quantite=quant;
    return NouveauArticle;
}
void afficher(article ARTICLE){
    printf("\n Nom: \t\t\t%s",ARTICLE.nom);
    printf("\n Prix unitaire: \t%.2f F CFA",ARTICLE.prix);
    printf("\n Quantite en stock: \t%.2f Kg",ARTICLE.quantite);
}