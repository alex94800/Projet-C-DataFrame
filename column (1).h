#ifndef COLUMN_H
#define COLUMN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_REALOC 256
#define MAX_COLONNES 100


typedef struct column {
    char title[100];
    int *tab;
    int LOGIQUE;
    int PHYSIQUE;
} COLUMN;



COLUMN* create_column(const char *title) {

    COLUMN *p = malloc(sizeof(COLUMN));
    strncpy(p->title, title, sizeof(p->title) - 1);
    p->title[sizeof(p->title) - 1] = '\0';
    p->tab = calloc(SIZE_REALOC, sizeof(int));
    p->LOGIQUE = 0;
    p->PHYSIQUE = SIZE_REALOC;
    return p;

}


int valuesue_insert(COLUMN *col, int valuesue) {
    if (col->LOGIQUE == col->PHYSIQUE) {
        int capacite = col->PHYSIQUE + SIZE_REALOC;
        int* temp = realloc(col->tab, capacite * sizeof(int));
        if (temp == NULL) {
            return 0;
        }
        col->tab = temp;
        col->PHYSIQUE = capacite;
    }
    col->tab[col->LOGIQUE++] = valuesue;
    return 1;
}


void delete_column(COLUMN **col) {
    if ((*col)->tab != NULL) {
        free((*col)->tab);
    }
    free(*col);
    *col = NULL;
}



void print_col(COLUMN *col) {
    for (int i = 0; i < col->LOGIQUE; i++) {
        printf("[%d] %d\n", i, col->tab[i]);
    }
}


int nombre_occurence(COLUMN *col, int values) {

    int i;
    int nombre = 0;
    for (i=0; i < col->LOGIQUE; i++) {
        if (col->tab[i] == values) {
            nombre++;
        }
    }
    if (nombre == 0) {
        return printf("No occurence of this valuesue found");
    }
    return nombre;
}



int valuesue_at_pos(COLUMN *col, int pos) {

    int i;
    if (pos > col->LOGIQUE) {
        return 0;
    }
    for (i=0; i < col->LOGIQUE; i++) {
        if (i == pos) {
            return col->tab[i];
        }
    }

}


int grader_valuesue(COLUMN *col, int values) {
    int i;
    int nombre = 0;
    for (i=0; i < col->LOGIQUE; i++) {
        if (col->tab[i] > values) {
            nombre++;
        }
    }

    return nombre;
}

int valuesue_lower(COLUMN *col, int values) {
    int i;
    int nombre = 0;
    for (i=0; i < col->LOGIQUE; i++) {
        if (col->tab[i] < values) {
            nombre++;
        }
    }

    return nombre;

}


int valuesue_equal(COLUMN *col, int values) {
    int i;
    int nombre = 0;
    for (i=0; i < col->LOGIQUE; i++) {
        if (col->tab[i] == values) {
            nombre++;
        }
    }

    return nombre;

}

#endif 
