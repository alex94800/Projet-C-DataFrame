#include "fonctions.h"

// Crée une nouvelle colonne avec un titre donné
COLUMN *create_column(char* title) {
    COLUMN *colonne= (COLUMN*) malloc(sizeof(COLUMN));
    colonne->TP=0;
    colonne->TL=0;
    colonne->Data = NULL;
    colonne->Title = (char*) malloc((strlen(title)+1)*sizeof(char));
    strcpy(colonne->Title,title);
    return colonne;
}

// Insère une valeur dans une colonne donnée
int insert_value(COLUMN* colonne, int valeur) {
    if (colonne->TP ==  0) {
        colonne->Data=(int*)malloc(REALOC_SIZE*sizeof(int));
        colonne->Data[colonne->TL]=valeur;
        colonne->TL++;
        colonne->TP = REALOC_SIZE;
        return 1;
    } else if(colonne->TL==colonne->TP) {
        colonne->Data= (int*)realloc(colonne->Data,(colonne->TP+REALOC_SIZE)*sizeof (int));
        colonne->Data[colonne->TL]=valeur;
        colonne->TL++;
        colonne->TP += REALOC_SIZE;
        return 1;
    } else {
        colonne->Data[colonne->TL] = valeur;
        colonne->TL++;
        return 1;
    }
    return 0;
}

// Supprime une colonne et libère la mémoire
void delete_column(COLUMN **colonne) {
    free((*colonne)->Data);
    free((*colonne)->Title);
    free((*colonne));
    *colonne=NULL;
}

// Affiche les valeurs d'une colonne
void print_col(COLUMN* colonne) {
    for (int i=0;i<colonne->TL;i++) {
        printf("[%d] %d\n",i,colonne->Data[i]);
    }
}

// Compte le nombre d'occurrences d'une valeur dans une colonne
int occurence(COLUMN* colonne,int x) {
    int occurence=0;
    for (int i=0;i<colonne->TL;i++) {
        if (colonne->Data[i]==x)
            occurence++;
    }
    return occurence;
}

// Renvoie la valeur à une position donnée dans une colonne
int position(COLUMN *colonne, int x) {
    return colonne->Data[x];
}

// Compte les valeurs supérieures à x dans une colonne
int superieur(COLUMN *colonne, int x) {
    int total=0;
    for (int i=0;i<colonne->TL;i++) {
        if (colonne->Data[i]>x)
            total++;
    }
    return total;
}

// Compte les valeurs inférieures à x dans une colonne
int inferieur(COLUMN *colonne, int x) {
    int total=0;
    for (int i=0;i<colonne->TL;i++) {
        if (colonne->Data[i]<x)
            total++;
    }
    return total;
}

// Compte les valeurs égales à x dans une colonne
int egale(COLUMN *colonne, int x) {
    int total=0;
    for (int i=0;i<colonne->TL;i++) {
        if (colonne->Data[i]==x)
            total++;
    }
    return total;
}

// Crée un tableau de colonnes de taille donnée
COLUMN** creat_data_frame(int taille) {
    COLUMN** data_frame= malloc(sizeof(COLUMN)*taille);
    return data_frame;
}

// Remplit un tableau de colonnes avec des valeurs
void fill_data_frame(COLUMN** data_frame,int nombre_colonne) {
    char titre[50];
    int taille,val;
    for (int i = 0; i < nombre_colonne; i++) {
        printf("Entrer le titre de la colone numéro %d\n", i);
        scanf("%s", titre);
        data_frame[i] = create_column(titre);
        printf("Combien y'a t'il de valeur dans cette colonne ");
        scanf("%d", &taille);
        for (int j = 0; j < taille; j++) {
            printf("Entrez la %d val\n", j);
            scanf("%d", &val);
            insert_valeur(data_frame[i], val);
        }
    }
}

// Affiche toutes les colonnes d'un tableau de colonnes
void print_data_frame(COLUMN** data_frame,int nombre_colonne) {
    for(int i=0;i<nombre_colonne;i++) {
        printf("%de colonne :\n",i+1);
        print_col(data_frame[i]);
    }
}

// Affiche les premières lignes des colonnes jusqu'à une limite donnée
void print_data_frameLimitLigne(COLUMN** data_frame,int nombre_colonne,int LigneLimite) {
    for(int i=0;i<nombre_colonne;i++) {
        printf("%de colonne :\n",i+1);
        for (int j=0;j<LigneLimite;j++)
            printf("[%d]:%d\n",j,data_frame[i]->Data[j]);
    }
}

// Affiche les premières colonnes jusqu'à une limite donnée
void print_data_frameLimitCol(COLUMN** data_frame,int nombre_colonne,int Collimit) {
    for(int i=0;i<nombre_colonne && i<Collimit ;i++) {
        printf("%de colonne :\n",i+1);
        print_col(data_frame[i]);
    }
}

// Ajoute une ligne à une colonne spécifiée dans un tableau de colonnes
void fill_data_frameLigne(COLUMN** data_frame,int nombre_colonne) {
    int colonne,i=0,valeur;
    printf("Quel est la colonne à laquelle vous voulez rajouter une ligne ?\n");
    scanf("%d",&colonne);
    if (colonne<=nombre_colonne) {
        printf("Quelle est la valeur que vous souhaitez rajouter? ?\n");
        scanf("%d", &valeur);
        do {
            i++;
        } while (i < data_frame[colonne]->TL && data_frame[colonne]->Data[i] != 0);
        insert_valeur(data_frame[colonne], valeur);
    }
}

// Supprime une ligne d'une colonne spécifiée dans un tableau de colonnes
void del_data_frameLigne(COLUMN** data_frame,int nombre_colonne) {
    int colonne,ligne;
    printf("Quelle ligne  et de quel colonne voulez-vous supprimer ?\n colonne = ");
    scanf(" %d",&colonne);
    printf("\nligne =");
    scanf("%d",&ligne);
    if (colonne<nombre_colonne && data_frame[colonne]->Data[ligne]!=0) {
        for (int j=ligne; j < data_frame[colonne]->TL - 1;j++) {
            data_frame[colonne]->Data[j]=data_frame[colonne]->Data[j+1];
        }
        data_frame[colonne]->TL--;
        printf("La ligne %d de la colonne %d a été supprimée.\n", ligne, colonne);
    } else
        printf("Erreur avec les vals choisies \n");
}

// Ajoute une nouvelle colonne à un tableau de colonnes
void add_data_frameCol(COLUMN** data_frame,int *nbcol) {
    char* titre[50];
    int taille,val;
    printf("Quel nom voulez-vous donner à votre nouvelle colonne ?");
    scanf("%s", titre);
    data_frame[*nbcol] = create_column(titre);
    printf("Combien de val dans cette colonne ? ");
    scanf("%d", &taille);
    for (int j = 0; j < taille; j++) {
        printf("Entrez la %d val\n", j);
        scanf("%d", &val);
        insert_valeur(data_frame[*nbcol], val);
    }
    (*nbcol)++;
}

// Supprime une colonne spécifiée d'un tableau de colonnes
void del_data_frameCol(COLUMN** data_frame,int* nbcol) {
    int colonne;
    printf("Quelle est la colonne que vous voulez supprimer? ?\n ");
    scanf(" %d",&colonne);
    if (colonne< *nbcol) {
        delete_column(&data_frame[colonne]);
        for (int i=colonne ;i+1 < *nbcol; i++)
            data_frame[i+1]=data_frame[i];
        (*nbcol)--;
    } else
        printf("Il y a une erreur avec les valeurs choisies \n");
}

// Renomme une colonne spécifiée dans un tableau de colonnes
void rename_Col(COLUMN** data_frame,int* nbcol) {
    char titre[50];
    int colonne;
    printf("Quel est la colonne que vous souhaitez renommer? \n");
    scanf("%d",&colonne);
    if (colonne<*nbcol) {
        printf("Nouveau titre: \n");
        scanf("%s",titre);
        strcpy(data_frame[colonne]->Title, titre);
    }
}

// Recherche une valeur dans un tableau de colonnes
int Research_value(COLUMN** data_frame,int nbcol,int x) {
    for (int i=0;i<nbcol;i++) {
        for (int j=0 ; j<data_frame[i]->TL; j++) {
            if (data_frame[i]->Data[j]==x)
                return 1;
        }
    }
    return 0;
}

// Remplace une valeur dans une colonne spécifiée et une ligne donnée
void Replacevalue(COLUMN** data_frame,int nbcol) {
    int colonne,ligne,valeur;
    printf("Quelle colonne ?\n");
    scanf("%d",&colonne);
    printf("Quelle ligne ?\n");
    scanf("%d",&ligne);
    printf("Nouvelle valeur ?\n");
    scanf("%d",&valeur);
    if (colonne<

nbcol && ligne<data_frame[colonne]->TL) {
        data_frame[colonne]->Data[ligne] = valeur;
    } else {
        printf("Il y a une erreur avec les valeurs choisies\n");
    }
}

// Affiche les titres des colonnes d'un tableau de colonnes
void printName(COLUMN** data_frame,int nbcol) {
    for (int i=0;i<nbcol;i++){
        printf("colonne num %d = %s \n",i,data_frame[i]->Title);
    }
}

// Renvoie le nombre de lignes dans un tableau de colonnes
int Nbr_lignes_data_frame(COLUMN** data_frame, int nombre_colonne){
    int nombre_de_ligne=0;
    for (int i=0;i<nombre_colonne;i++) {
        nombre_de_ligne=nombre_de_ligne + data_frame[i]->TL;
    }
    return(nombre_de_ligne);
}

// Renvoie le nombre de colonnes dans un tableau de colonnes
int Nbr_colonnes_data_frame(COLUMN** data_frame){
    return(sizeof(data_frame)/sizeof(int));
}

// Compte les valeurs inférieures à une valeur donnée dans un tableau de colonnes
int Nbr_val_egale_data_frame(COLUMN** data_frame, int val, int nombre_colonne){
    int i,j,nb_val=0;
    for(i=0;i<nombre_colonne;i++){
        for(j=0;j<data_frame[i]->TL;j++){
            if(data_frame[i]->Data[j] < val)
                nb_val++; 
            }
        }
        return(nb_val);

// Compte le nombre de valeurs supérieures à une valeur donnée dans un DataFrame à plusieurs colonnes.   
int Nbr_val_sup_DataFrame(COLUMN** data_frame, int val, int nbcol){
    int i,j,nb_val=0;
    for(i=0;i<nbcol;i++){
        for(j=0;j<data_frame[i]->TL;j++){
            if(data_frame[i]->Data[j] > val )
                nb_val++;
        }
    }
    return(nb_val);
}

// Compte le nombre de valeurs inférieures à une valeur donnée dans un DataFrame à plusieurs colonnes.
int Nbr_val_inf_DataFrame(COLUMN** data_frame, int val, int nbcol){
    int i,j,nb_val=0;
    for(i=0;i<nbcol;i++)
    {
        for(j=0;j<data_frame[i]->TL;j++)
        {
            if(data_frame[i]->Data[j] < val)
                nb_val++; 
        }
    }
    return(nb_val);
}
}
