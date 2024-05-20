#include <stdio.h>
#include "fonctions.h"


int main()
{
    COLUMN *ma_colonne = create_column("My column");

    insert_value(ma_colonne,5);
    insert_value(ma_colonne,3);
    insert_value(ma_colonne,5);
    print_col(ma_colonne);
    printf("%d\n",occurence(ma_colonne,5));
    printf("%d\n", position(ma_colonne, 2));
    printf("%d\n",superieur(ma_colonne, 1));
    printf("%d\n",inferieur(ma_colonne, 4));

    COLUMN** data_frame;
    int nbcol=1,val=3;
    data_frame=creat_data_frame(3);
    fill_data_frame(data_frame,nbcol);
    Nbr_val_egale_data_frame(data_frame,val,nbcol);
    fill_data_frameLigne(data_frame,nbcol);
    del_data_frameLigne(data_frame,nbcol);
    rename_Col( data_frame,&nbcol);
    ReplaceValue( data_frame, nbcol);
    print_data_frame(data_frame,nbcol);
    return 0;
}
