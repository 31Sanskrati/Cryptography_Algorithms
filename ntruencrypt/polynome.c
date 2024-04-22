#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "polynome.h"
/* Renvoie le polynome nul possedant N coefficients */
polynomial_d *empty_pol ()
{
    polynomial_d *p_d;
    p_d=malloc(sizeof(polynomial_d));
    p_d->deg=0;        
    p_d->p=calloc(N, sizeof (int));
    return p_d;
}

/* Remet un polynome à zéro */
void zero(polynomial_d *u){
    for(int k=0;k<N;k++){
        u->p[k]=0;
    }
}

/* Renvoie le polynome X^n */
polynomial_d *X(int n){
    polynomial_d *p_dxn = empty_pol();
    p_dxn->p[n]=1;
    p_dxn->deg=n;
    return p_dxn;
}

/* Met le degré du polynome_d u au degré de u */
void degr(polynomial_d *u){
    u->deg=N;
    while((u->p[u->deg]==0)&&(u->deg>=1)){
        u->deg--;
    }
}

/* Affiche le polynome donné en entrée */
void print_pol(polynomial_d *u){
    if(u->deg ==0){
        printf("%d\n",u->p[0]);
    }
    else {
        int first_non_zero=0;
        while (u->p[first_non_zero]==0){
            first_non_zero++;
        }
        if(first_non_zero==0){
            printf("%d ",u->p[first_non_zero]);
        }
        else if(first_non_zero==u->deg){
            if(u->p[first_non_zero]==1){
                printf("X^%d",first_non_zero);
            }
            else{
                printf("%dX^%d",u->p[first_non_zero],first_non_zero);
            }
        }
        else{
            if(u->p[first_non_zero]==1){
                printf("X^%d ",first_non_zero);
            }
            else{
                printf("%dX^%d ",u->p[first_non_zero],first_non_zero);
            }
        }
        for (int k=first_non_zero + 1; k<u->deg; k++){
            if(u->p[k]<0){
                if(u->p[k]==-1){
                    printf("- X^%d ",k);
                }
                else{
                    printf("- %dX^%d ",-u->p[k],k);
                }
            }
            else if(u->p[k]>0){
                if(u->p[k]==1){
                    printf("+ X^%d ",k);
                }
                else{
                    printf("+ %dX^%d ",u->p[k],k);
                }
            }
        }
        if(first_non_zero!=u->deg){
            if(u->p[u->deg]<0){
                if(u->p[u->deg]==-1){
                    printf("- X^%d\n",u->deg);
                }
                else{
                    printf("- %dX^%d\n",-u->p[u->deg],u->deg);
                }
            }
            else if(u->p[u->deg]>0){
                if(u->p[u->deg]==1){
                    printf("+ X^%d\n",u->deg);
                }
                else{
                    printf("+ %dX^%d\n",u->p[u->deg],u->deg);
                }
            }
        }   
        else{
            printf("\n");
        }
    }
}

/* Affiche le polynome donné en entrée dans le fichier out*/
void print_pol2(FILE *out, polynomial_d *u){
    if(u->deg ==0){
        fprintf(out,"%d\n",u->p[0]);
    }
    else {
        int first_non_zero=0;
        while (u->p[first_non_zero]==0){
            first_non_zero++;
        }
        if(first_non_zero==0){
            fprintf(out,"%d ",u->p[first_non_zero]);
        }
        else if(first_non_zero==u->deg){
            if(u->p[first_non_zero]==1){
                fprintf(out,"X^%d",first_non_zero);
            }
            else{
                fprintf(out,"%dX^%d",u->p[first_non_zero],first_non_zero);
            }
        }
        else{
            if(u->p[first_non_zero]==1){
                fprintf(out,"X^%d ",first_non_zero);
            }
            else{
                fprintf(out,"%dX^%d ",u->p[first_non_zero],first_non_zero);
            }
        }
        for (int k=first_non_zero + 1; k<u->deg; k++){
            if(u->p[k]<0){
                if(u->p[k]==-1){
                    fprintf(out,"- X^%d ",k);
                }
                else{
                    fprintf(out,"- %dX^%d ",-u->p[k],k);
                }
            }
            else if(u->p[k]>0){
                if(u->p[k]==1){
                    fprintf(out,"+ X^%d ",k);
                }
                else{
                    fprintf(out,"+ %dX^%d ",u->p[k],k);
                }
            }
        }
        if(first_non_zero!=u->deg){
            if(u->p[u->deg]<0){
                if(u->p[u->deg]==-1){
                    fprintf(out,"- X^%d\n",u->deg);
                }
                else{
                    fprintf(out,"- %dX^%d\n",-u->p[u->deg],u->deg);
                }
            }
            else if(u->p[u->deg]>0){
                if(u->p[u->deg]==1){
                    fprintf(out,"+ X^%d\n",u->deg);
                }
                else{
                    fprintf(out,"+ %dX^%d\n",u->p[u->deg],u->deg);
                }
            }
        }   
        else{
            fprintf(out,"\n");
        }
    }
}

/* print le tableau représentant le polynome u */
void print_pol_o(polynomial_d *u){
    printf("[%d;",u->p[0]);
    for(int k=1;k<N-1;k++){
        printf("%d;",u->p[k]);
    }
    printf("%d]\n",u->p[N-1]);
    degr(u);
}

/* Renvoie value à la puissance power */
int pow_opt(int value, int power){
    int r=value;
    for(int k=1;k<power;k++){
        r=r*value;
    }
    return r;
}

/* Renvoie le polynome f ou ses coefficients sont modulos p ou q */
void modulo_p (polynomial_d *u, polynomial_d *p_dmp)
{
    for (int k = 0; k<=u->deg; k++)
        {
            p_dmp->p[k]=u->p[k]%P;
        }
        degr(u);
}
void modulo_q (polynomial_d *u, polynomial_d *p_dmq)
{
  for (int k = 0; k<=u->deg; k++)
    {
        p_dmq->p[k]=u->p[k]%Q;
    }
    degr(u);
}
/* Renvoie un pointeur sur la combinaison linéaire de deux polynômes u et v et d'un entier relatif break
* Renvoie u+ kv */
void lin_comb(polynomial_d *u, int l, polynomial_d *v, polynomial_d *p_dcl){
    for (int k=0; k<=u->deg || k<=v->deg; k++){
        p_dcl->p[k]= u->p[k] + l*v->p[k];
    }
    degr(p_dcl);
}
    
/* Renvoie le produit de convolution de deux polynomes */
void conv(polynomial_d *u, polynomial_d *v, polynomial_d *p_dc)
{
    for (int k=0; k<N; k++)
    {
        for (int i=0; i<=k; i++){
            p_dc->p[k]= p_dc->p[k] + u->p[i]*v->p[k-i];
        }
        for (int i=N+k-v->deg; i<=u->deg; i++){
            p_dc->p[k]= p_dc->p[k] + u->p[i]*v->p[N+k-i];
            
        }
    }
    degr(p_dc);
}

/* Renvoie le center lift d'un polynome f 
 * dont on a donné en argument le polynbome */
void center_lift(polynomial_d *u, polynomial_d *p_dl){
    int coef;
    for(int k=0; k<=u->deg; k++){
        coef = u->p[k]%Q;
        if(2*coef>Q){
            p_dl->p[k] = Q-coef;
        } 
        else{
            p_dl->p[k] = coef;
        }
    }
}

/* fonction auxiliaire de div_euc permettant de remettre le degré de r à son actuel degré, 
 * car celui ci décroit à chque itération de la boucle while */
void deg_dec(polynomial_d *u){
    while((u->p[u->deg]==0)&&(u->deg>=1)){
        u->deg--;
    }
}

/* Fait la division euclidienne de u par v dans R_p
 * v doit être unitaire
 * Modifie les arguments r, reste et q, quotient donnée en argument */
void div_euc_p(polynomial_d *u, polynomial_d *v, polynomial_d *r, polynomial_d *q){
    r->p=u->p;
    
    if(u->deg<v->deg){
       r->deg=u->deg;
    }
    else{
        degr(r);
        
        q->deg=u->deg-v->deg;
        polynomial_d *p_dc=empty_pol();
        
        int v_inv_p = pow_opt(v->p[v->deg],P-1)%P;
        int i=0;
        
        while (r->deg >= v->deg){
            printf("on est la (%d)\n",i);
            printf("r :");
            print_pol(r);
            
            printf("q :");
            print_pol(q);
            
            conv(X(r->deg-v->deg), v, p_dc);
            printf("p_dc :");
            print_pol(p_dc);
            printf("\n");
            
            q->p[r->deg-v->deg]=r->p[r->deg]*v_inv_p%P;
            
            lin_comb(r, -1*r->p[r->deg]*v_inv_p, p_dc, r);
            zero(p_dc);
            
            i++;
            
        }
        free(p_dc);
    }
}
/* Fait la division euclidienne de u par v dans R_q
 * v doit être unitaire
 * Modifie les arguments r, reste et q, quotient donnée en argument */
void div_euc_q(polynomial_d *u, polynomial_d *v, polynomial_d *r, polynomial_d *q){
    r->p=u->p;
    
    if(u->deg<v->deg){
       r->deg=u->deg;
    }
    else{
        degr(r);
        
        q->deg=u->deg-v->deg;
        polynomial_d *p_dc=empty_pol();
        
        int v_inv_q =pow_opt(v->p[v->deg],Q-1)%Q;
        int i=0;
        
        while (r->deg >= v->deg){
            printf("on est la (%d)\n",i);
            printf("r :");
            print_pol(r);
            
            printf("q :");
            print_pol(q);
            
            conv(X(r->deg-v->deg), v, p_dc);
            printf("p_dc :");
            print_pol(p_dc);
            printf("\n");
            
            q->p[r->deg-v->deg]=r->p[r->deg]*v_inv_q%Q;
            
            lin_comb(r, -1*r->p[r->deg]*v_inv_q, p_dc, r);
            zero(p_dc);
            
            i++;
            
        }
        free(p_dc);
    }
}

/* Fait la division euclidenne de dom(v)u par v 
 * v peut donc ne pas être unitaire 
 * Modifie les arguments r reste et q quotient donnée en argument */
void div_euc(polynomial_d *u, polynomial_d *v, polynomial_d *r, polynomial_d *q){
    if(v->p[v->deg]==1){
        div_euc_q(u,v,r,q);
    }
    else{
        polynomial_d *p_dc=empty_pol();
        r->deg=u->deg;
        r->p=u->p;
        int i=0;
        while (r->deg >= v->deg){
            lin_comb(empty_pol(),v->p[v->deg],r,r);
            printf("on est la(%d)\n",i);
            printf("r :");
            print_pol(r);
            lin_comb(empty_pol(),v->p[v->deg],q,q);
            printf("q :");
            print_pol(q);
            printf("v :");
            print_pol(v);
            conv(X(r->deg-v->deg), v, p_dc);
            printf("p_dc :");
            print_pol(p_dc);
            printf("\n");
            q->p[r->deg-v->deg]=r->p[r->deg]/v->p[v->deg];
            degr(q);
            lin_comb(r, -1*(r->p[r->deg]/v->p[v->deg]), p_dc, r);
            zero(p_dc);
            i++;
        }
        free(p_dc);
    }
}

/* Rend unitaire un polynome u */
void unitaire(polynomial_d *u){
    for (int k=0;k<=u->deg;k++){
        u->p[k]=u->p[k]/u->p[u->deg];
    }
}

/* Fait le pgcd de u et v 
 * Modifie les arguments r, reste et q, quotient donnée en argument */
void pgcd_o(polynomial_d *u, polynomial_d *v, polynomial_d *rn){
    rn->deg=u->deg;
    rn->p=u->p;
    polynomial_d *rn_plus_1;
    rn_plus_1 = empty_pol();
    rn_plus_1->deg=v->deg;
    rn_plus_1->p=v->p;
    polynomial_d *q=empty_pol();
    polynomial_d *aux=empty_pol();
    while((rn_plus_1->deg!=0)||(rn_plus_1->p[0]!=0)){
        div_euc(rn,rn_plus_1,rn,q);
        aux->deg=rn->deg;
        aux->p=rn->p;
        rn->deg=rn_plus_1->deg;
        rn->p=rn_plus_1->p;
        rn_plus_1->deg=aux->deg;
        rn_plus_1->p=aux->p;
    }
    free(rn_plus_1);
    unitaire(rn);
}
/* Fait le pgcd de u et v 
 * Modifie les arguments r, reste et q, quotient donnée en argument */
void pgcd(polynomial_d *u, polynomial_d *v, polynomial_d *rn, queue_pol **q_p){
    rn->deg=u->deg;
    rn->p=u->p;
    
    polynomial_d *rn_plus_1=empty_pol();
    rn_plus_1->deg=v->deg;
    rn_plus_1->p=v->p;
    
    polynomial_d *qn=empty_pol();
    polynomial_d *aux=empty_pol();
    while((rn_plus_1->deg!=0)||(rn_plus_1->p[0]!=0)){
        queue_post(q_p,qn);
        div_euc(rn,rn_plus_1,rn,qn);
        aux->deg=rn->deg;
        aux->p=rn->p;
        rn->deg=rn_plus_1->deg;
        rn->p=rn_plus_1->p;
        rn_plus_1->deg=aux->deg;
        rn_plus_1->p=aux->p;
    }
    free(rn_plus_1);
    unitaire(rn);
}       
/* Trouve deux suites de polynomes an et bn pour tout n on ait
 * rn-1=u*an-1 + v*bn-1 
 * rn=u*an + v*bn
 * rn-1= qn*rn +rn-1 -> rn+1= qn*(u*an +v*bn) +u*an-1 +v*bn-1
 * rn+1=u*(qn*an+an-1) + v*(qn*bn+bn-1)
 * an+1=qn*an +an-1 ; a0=1 et a1=0 
 * bn+1=qn*bn +bn-1 ; b0=0 et b1=1 
 * Il s'agit donc d'avoir la suite de polynome (qn)
 */ 
void bezout(polynomial_d *u, polynomial_d *v, polynomial_d *rn, polynomial_d *an, polynomial_d *bn, queue_pol *q_p){
    pgcd(u,v,rn,&q_p);}
    
        
/* Renvoie l'inverse d'un polynome f dans l'anneau F_p ou F_q 
polynomial *inv_p (polynomial f){
    p111 An intro to matghematical gngn
    p402
}
polynomial *inv_q (polynomial f);
*/
