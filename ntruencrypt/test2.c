#include <stdio.h>
#include <stdlib.h>
#include "test2.h"

/* Initialise le polynome u à la valeur souhaité par l'utilisateur */
void get_pol(FILE *in, polynomial_d *u){
    int coef,val_coef;
    
    while(getc(in)!='\n'){
        fscanf("%d %d",&coef,&val_coef);
        u->p[coef]=val_coef;
    }
    degr(u);
    
    printf("\n");
}

void test_div_euc_p()
{
    FILE *in, *out;
 
    in = fopen("test_div_euc_o _p.txt", "r");
    if (in == NULL)
    {
        printf("Cannot open the source file.\n");
        exit(1);
    }
 
    out = fopen("result_div_euc_o_p.txt", "w");
    if (out == NULL)
    {
        printf("Cannot open the destination file.\n");
        exit(1);
    }
 
    char ch;
 
    // faire jusqu'à ce que la fin du fichier soit atteinte
    while (!feof(in))
    {
        // lit la prochaine paire d'entrées du fichier
        get_pol(in,u);
        get_pol(in,v);
 
        // calcule pgcd et imprime dans le fichier de sortie
        print_pol2(out,r);
        print_pol2(out,q);
 
        // passe à la ligne suivante
        ch = getc(in);
    }
 
    // ferme le flux de fichiers d'entrée et de sortie
    fclose(out);
    fclose(in);
}

void test_div_euc_q()
{
    FILE *in, *out;
 
    in = fopen("test_div_euc_o_q.txt", "r");
    if (in == NULL)
    {
        printf("Cannot open the source file.\n");
        exit(1);
    }
 
    out = fopen("result_div_euc_o_q.txt", "w");
    if (out == NULL)
    {
        printf("Cannot open the destination file.\n");
        exit(1);
    }
 
    char ch;
 
    // faire jusqu'à ce que la fin du fichier soit atteinte
    while (!feof(in))
    {
        // lit la prochaine paire d'entrées du fichier
        get_pol(in,u,v);
        
        // calcule r et q et imprime dans le fichier de sortie
        polynomial_d *r=empty_pol();
        polynomial_d *q=empty_pol();
        
        div_euc_o_q(u,v,r,q);
        print_pol2(out,r,q);
 
        // passe à la ligne suivante
        ch = getc(in);
    }
 
    // ferme le flux de fichiers d'entrée et de sortie
    fclose(out);
    fclose(in);
 
    return 0;
}
