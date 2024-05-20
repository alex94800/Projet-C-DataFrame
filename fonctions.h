#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PROJET_C_FONCTIONS_H
#define PROJET_C_FONCTIONS_H

#define REALOC_SIZE 256

typedef struct
{
    char * Title;
    int TP;
    int TL;
    int * Data;
}COLUMN;///on définie notre nouveau type "COLUMN"

COLUMN *create_column(char* title);

int insert_value(COLUMN* colonne, int value);

void delete_column(COLUMN **colonne);

void print_col(COLUMN* colonne);

int occurence(COLUMN* colonne,int x);

int position(COLUMN* colonne, int x);

int superieur(COLUMN *colonne, int x);
int inferieur(COLUMN *colonne, int x);
int egale(COLUMN *colonne, int x);

COLUMN** creat_data_frame(int taille);
void fill_data_frame(COLUMN** data_frame,int nombreCol);

void print_data_frame(COLUMN** data_frame,int nombreCol);
void print_data_frameLimitLigne(COLUMN** data_frame,int nombreCol,int LigneLimite);
void print_data_frameLimitCol(COLUMN** data_frame,int nombreCol,int Collimit);


void fill_data_frameLigne(COLUMN** data_frame,int nombreCol);
void del_data_frameLigne(COLUMN** data_frame,int nombreCol);

void add_data_frameCol(COLUMN** data_frame, int *nombre_colonne);
void del_data_frameCol(COLUMN** data_frame,int *nombre_colonne);

void rename_Col(COLUMN** data_frame,int* nombre_colonne);

int Research_Value(COLUMN** data_frame,int nombre_colonne,int x);
void ReplaceValue(COLUMN** data_frame,int nombre_colonne);
void printName(COLUMN** data_frame,int nombre_colonne);

int Nbr_lignes_data_frame(COLUMN** data_frame, int nbcol);
int Nbr_colonnes_data_frame(COLUMN** data_frame);
int Nbr_val_egale_data_frame(COLUMN** data_frame, int valeur, int nbcol);
int Nbr_val_sup_data_frame(COLUMN** data_frame, int valeur, int nbcol);
int Nbr_val_inf_data_frame(COLUMN** data_frame, int valeur, int nbcol);


#endif S
