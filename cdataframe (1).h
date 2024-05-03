#ifndef CDATAFRAME_CDATAFRAME_H
#define CDATAFRAME_CDATAFRAME_H

#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    COLUMN *colonnes[MAX_COLUMNS];
    int colonnes;
} CDataframe;


CDataframe *create_dataframe() {
    CDataframe *df = malloc(sizeof(CDataframe));
    df->colonnes = 0;
    for (int i = 0; i < MAX_COLUMNS; ++i) {
        df->colonnes[i] = NULL;
    }
    return df;
}


int add_column(CDataframe *df, COLUMN *col) {
    if (df->colonnes < MAX_COLUMNS) {
        df->colonnes[df->colonnes++] = col;
        return 1;
    }
    return 0;
}


void print_dataframe(CDataframe *df) {
    for (int i = 0; i < df->colonnes; i++) {
        COLUMN *col = df->colonnes[i];
        printf("Column %d: %s\n", i+1, col->titre);
        printf("valeur:\n");
        for (int j = 0; j < col->LOGIQUE; j++) {
            printf("[%d] %d\n", j, col->tab[j]);
        }
    }
}


void print_limited_row(CDataframe *df, int limit_line) {
    for (int i = 0; i < df->colonnes; i++) {
        COLUMN *col = df->colonnes[i];
        printf("Column %d: %s\n", i+1, col->titre);
        printf("valeur:\n");
        for (int j = 0; j < col->LOGIQUE; j++) {
            if (j <= limit_line) {
                printf("[%d] %d\n", j, col->tab[j]);
            }
        }
    }
}


void print_col_limitedumn (CDataframe *df, int col_limited) {
    for (int i = 0; i < df->colonnes; i++) {
        if (i <= col_limited) {
            COLUMN *col = df->colonnes[i];
            printf("Column %d: %s\n", i + 1, col->titre);
            printf("valeur:\n");
            for (int j = 0; j < col->LOGIQUE; j++) {
                printf("[%d] %d\n", j, col->tab[j]);
            }
        }
    }
}


int add_row(CDataframe *df, int *valeur) {
    if (df == NULL || valeur == NULL) {
        return 0;
    }

    for (int i = 0; i < df->colonnes; i++) {
        if (!valeur_insert(df->colonnes[i], valeur[i])) {
            return 0;
        }
    }
    return 1;
}


int delete_row(CDataframe *df, int ligne_index) {
    if (df == NULL || ligne_index < 0) {
        return 0;
    }

    for (int i = 0; i < df->colonnes; i++) {
        COLUMN *col = df->colonnes[i];
        if (ligne_index >= col->LOGIQUE) {
            continue;
        }

        for (int j = ligne_index; j < col->LOGIQUE - 1; j++) {
            col->tab[j] = col->tab[j + 1];
        }
        col->LOGIQUE--;
    }
    return 1;
}


int rename_column(CDataframe *df, int index_colonne, const char *nw_name) {
    if (df == NULL || nw_name == NULL || index_colonne < 0 || index_colonne >= df->colonnes) {
        return 0;
    }

    COLUMN *col = df->colonnes[index_colonne];
    if (col == NULL) {
        return 0;
    }

    strncpy(col->titre, nw_name, sizeof(col->titre) - 1);
    col->titre[sizeof(col->titre) - 1] = '\0';
    return 1;
}


int contains_valeur(CDataframe *df, int valeur) {
    for (int i = 0; i < df->colonnes; i++) {
        COLUMN *col = df->colonnes[i];
        if (col != NULL) {
            for (int j = 0; j < col->LOGIQUE; j++) {
                if (col->tab[j] == valeur) {
                    return 1;
                }
            }
        }
    }
    return 0;
}


int change_valeur_at(CDataframe *df, int index_colonne, int ligne_index, int nouvelle_valeur) {
    if (df == NULL || index_colonne < 0 || index_colonne >= df->colonnes) {
        return 0;
    }

    COLUMN *col = df->colonnes[index_colonne];
    if (col == NULL || ligne_index < 0 || ligne_index >= col->LOGIQUE) {
        return 0;
    }

    col->tab[ligne_index] = nouvelle_valeur;
    return 1;
}

#endif 
