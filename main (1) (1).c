#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"


int main() {


    CDataframe *df = create_dataframe();
    add_column(df, create_column("Colonne 1"));
    add_column(df, create_column("Colonne 2"));
    add_column(df, create_column("Colonne 3"));


    int ligne1[] = {20, 20, 87};
    int ligne2[] = {2323, 52323, 87};
    int ligne3[] = {9990, 232323, 0};
    add_row(df, ligne1);
    add_row(df, ligne2);
    add_row(df, ligne3);



    print_dataframe(df);
    printf("\n");



    change_valeur_at(df, 1, 0, 999);
    print_dataframe(df);
    printf("\n");



    printf("Suppression de la ligne 2:\n");
    delete_row(df, 1);
    print_dataframe(df);
    printf("\n");



    rename_column(df, 2, "Nouvelle Colonne test");
    print_dataframe(df);
    printf("\n");

  
    printf("test de la recherche de la valeur 99 que nous avons ajouter précedement\n");
    if (contains_value(df, 999)) {
        printf("La valeur 999 est bien présente.\n");
    } else {
        printf("La valeur 999 n'est pas présente.\n");
    }
    printf("\n");



    for (int i = 0; i < df->colonnes; i++) {
        delete_column(&df->col[i]);
    }
    free(df);

    return 0;
}
