#ifndef POLYNOME_H
#define POLYNOME_H


/* on choisit le triplet public (N,p,q) au debut du programme 
* TOUS les polynomes seront de degré N-1 */
#define N 11
#define P 7
#define Q 2
/* les polynomes seront donc representés par des tableaux de taille N  */
typedef int * polynomial;

struct polynomial_s{
    polynomial p;
    int deg;
};
typedef struct polynomial_s polynomial_d;

struct queue_pol_s
{
   struct queue_pol_s *prev;
   struct queue_pol_s *next;
   polynomial_d *p_d;
};

typedef struct queue_pol_s queue_pol;
#include "queue_pol.h"
/* print le polynome sous sa forme mathematique */
void print_pol(polynomial_d *u);
/* print le tableau représentant le polynome u */
void print_pol_o(polynomial_d *u);

/* print le polynome sous sa forme mathematique dans le fichier texte out*/
void print_pol2(FILE *out, polynomial_d *u);

/* Renvoie le polynôme nul possèdant N coefficient */
polynomial_d *empty_pol();

/* Remet à zero un polynome */
void zero(polynomial_d *u);

/* Renvoie le polynome X^n */
polynomial_d *X(int n);

/* Met le degré du polynome_d u au degré de u */
void degr(polynomial_d *u);

/* Renvoie value à la puissance power */
int pow_opt(int value, int power);

/* Renvoie un pointeur sur le polynôme f où ses coefficients sont modulos n, où n=p ou n=q */
void modulo_p(polynomial_d *u, polynomial_d *p_dmp);
void modulo_q(polynomial_d *u, polynomial_d *p_dmq);

/* Renvoie un pointeur sur le polynôme f modulo X^N-1 
* où N est le paramètre que l'on se donne au début du chiffrement */
void modulo_N(polynomial_d *u, polynomial_d *p_dmN);

/* Renvoie un pointeur sur la combinaison linéaire de deux polynômes u et v et d'un entier relatif break
* Renvoie u+ kv */
void lin_comb(polynomial_d *u, int k, polynomial_d *v, polynomial_d *p_dcl);

/* Renvoie un pointeur sur le produit de convolution de deux polynômes */
void conv(polynomial_d *u, polynomial_d *v, polynomial_d *p_dc);

/* Renvoie le center lift du polynome f */
void center_lift(polynomial_d *u, polynomial_d *p_dl);

/* Renvoie un pointeur sur l'inverse d'un polynôme f dans l'anneau F_n, où n=p ou n=q */
void inv(polynomial_d *u, int n);

/* fonction auxiliaire de div_euc permettant de remettre le degré de r à son actuel degré, 
 * car celui ci décroit à chque itération de la boucle while */
void deg_dec(polynomial_d *u);
/* Fait la division euclidienne de u par v dans R_p
 * v doit être unitaire
 * Modifie les arguments r, reste et q, quotient donnée en argument */
void div_euc_p(polynomial_d *u, polynomial_d *v, polynomial_d *r, polynomial_d *q);
/* Fait la division euclidienne de u par v dans R_q
 * v doit être unitaire
 * Modifie les arguments r, reste et q, quotient donnée en argument */
void div_euc_q(polynomial_d *u, polynomial_d *v, polynomial_d *r, polynomial_d *q);
/*Modifie les arguments r, reste et q, quotient donnée en argument */
void div_euc(polynomial_d *u, polynomial_d *v, polynomial_d *r, polynomial_d *q);

/* Rend unitaire un polynome u */
void unitaire(polynomial_d *u);
/* Fait le pgcd de u et v 
 * Modifie les arguments r, reste et q, quotient donnée en argument */
void pgcd_o(polynomial_d *u, polynomial_d *v, polynomial_d *rn);
 /* Fait le pgcd de u et v 
 * Modifie les arguments r, reste et q, quotient donnée en argument */
void pgcd(polynomial_d *u, polynomial_d *v, polynomial_d *rn, queue_pol **q_p);
/* Fait le pgcd de u et v 
 * Modifie les arguments r, reste et q, quotient donnée en argument */
void bezou(polynomial_d *u, polynomial_d *v, polynomial_d *rn, polynomial_d *an, polynomial_d *bn, queue_pol* q_p);

polynomial_d *inv_q(polynomial);
polynomial_d *inv_p(polynomial);

#endif
