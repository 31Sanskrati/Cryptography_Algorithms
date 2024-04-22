#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "test.h"
#include "queue_pol.h"

/* Initialise le polynome u à la valeur souhaité par l'utilisateur */
void def_pol(polynomial_d *u){
    int coef,val_coef;
    int is_well_def=0;
    while (is_well_def==0){
        int go_on_def_pol=1;
        while(go_on_def_pol==1){
            printf("X^");
            scanf("%d",&coef);
            scanf("%d",&val_coef);
            printf("go_on_def_pol OUI(1) NON(0) :");
            scanf("%d",&go_on_def_pol);
            printf("\n");
            u->p[coef]=val_coef;
        }
        degr(u);
        print_pol(u);
        /* print_pol_o(u);*/
        printf("Est-ce le bon polynome ? OUI(1) NON(0) ");
        scanf("%d",&is_well_def);
        printf("\n");
    }
}

/* Crée autant de polynomes u et v que l'utilisateur souhaite 
 * puis test div_euc(u,v,r,q) r et q ayant déjà été initialisés à empty_pol()*/
void test_div_euc_p_o(void){
    int go_on=1;
    
    polynomial_d *u=empty_pol();
    polynomial_d *v=empty_pol();
    polynomial_d *r=empty_pol();
    polynomial_d *q=empty_pol();
    while(go_on==1){
        printf("/* begin div_eucl test */\n");
        printf("Initialisation de u :\n");
        def_pol(u);
        print_pol(u);
        printf("deg u :%d\n",u->deg);
        printf("Initialisation de v :\n");
        def_pol(v); 
        print_pol(v);
        printf("deg v :%d",v->deg);
        div_euc(u,v,r,q);
        printf("r : ");
        print_pol(r);
        printf("q : ");
        print_pol(q);
        printf("/* end div_eucl test */\n\n");
        printf("go_on OUI(1) NON(0) :");
        scanf("%d",&go_on);
        printf("\n");
    }
    free(u);
    free(v);
    free(r);
    free(q);
}

/* Initialise le polynome u à la valeur souhaité par l'utilisateur */
void get_pol(FILE *in, polynomial_d *u){
    int coef,val_coef;
    
    while(getc(in)!='\n'){
        fscanf(in,"%d %d",&coef,&val_coef);
        u->p[coef]=val_coef;
    }
    degr(u);
}

/* Crée autant de polynomes u et v que l'utilisateur souhaite 
 * puis test div_euc(u,v,r,q) r et q ayant déjà été initialisés à empty_pol()*/
void test_div_euc_p(void){
    FILE *in = fopen("test_div_euc_p.txt","r");
    
    if (in == NULL)
    {
        printf("Cannot open the source file.\n");
        exit(1);
    }
    
    char ch;
    
    polynomial_d *u = empty_pol();
    polynomial_d *v = empty_pol();
    polynomial_d *r = empty_pol();
    polynomial_d *q = empty_pol();
    
    while(!feof(in)){
        printf("/* begin div_eucl test */\n");
        
        printf("u :");
        get_pol(in,u);
        print_pol(u);
        printf("deg u :%d\n",u->deg);
        
        printf("v :");
        get_pol(in,v); 
        print_pol(v);
        printf("deg v :%d\n\n",v->deg);
        
        div_euc_p(u,v,r,q);
        printf("r : ");
        print_pol(r);
        
        printf("q : ");
        print_pol(q);
    
        printf("/* end div_eucl test */\n\n");
        
        ch = getc(in);
    }
    free(u);
    free(v);
    free(r);
    free(q);
}

/* Crée autant de polynomes u et v que l'utilisateur souhaite 
 * puis test pgcd(u,v,r,q) r et q ayant déjà été initialisés à empty_pol() */
void test_pgcd_o(void){
    int go_on=1;
    polynomial_d *u=empty_pol();
    polynomial_d *v=empty_pol();
    polynomial_d *rn=empty_pol();
    while(go_on==1){
        printf("/* begin pgcd test */\n");
        printf("Initialisation de u :\n");
        def_pol(u);
        print_pol(u);
        printf("deg u :%d\n\n",u->deg);
        printf("Initialisation de v :\n");
        def_pol(v); 
        print_pol(v);
        printf("deg v :%d\n\n",v->deg);
        pgcd_o(u,v,rn);
        printf("rn : ");
        print_pol(rn);
        printf("/* end pgcd test */\n\n");
        printf("go_on OUI(1) NON(0) :");
        scanf("%d",&go_on);
        printf("\n");
    }
    free(u);
    free(v);
    free(rn);
}

/* Crée autant de polynomes u et v que l'utilisateur souhaite 
 * puis test pgcd(u,v,r,q) r et q ayant déjà été initialisés à empty_pol()*/
void test_pgcd(void){
    int go_on=1;
    queue_pol *q_p;
    q_p=queue_new();
    polynomial_d *u=empty_pol();
    polynomial_d *v=empty_pol();
    polynomial_d *rn=empty_pol();
    while(go_on==1){
        printf("/* begin pgcd test */\n");
        printf("Initialisation de u :\n");
        def_pol(u);
        print_pol(u);
        printf("deg u :%d\n\n",u->deg);
        printf("Initialisation de v :\n");
        def_pol(v); 
        print_pol(v);
        printf("deg v :%d\n\n",v->deg);
        pgcd(u,v,rn,&q_p);
        printf("rn : ");
        print_pol(rn);
        printf("/* end pgcd test */\n\n");
        printf("go_on OUI(1) NON(0) :");
        scanf("%d",&go_on);
        printf("\n");
    }
    free(u);
    free(v);
    free(rn);
}
