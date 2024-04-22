#ifndef TEST_H
#define TEST_H
#include "polynome.h"
/* Initialise le polynome u à la valeur souhaité par l'utilisateur */
void def_pol(polynomial_d *u);

/* Crée autant de polynomes u et v que l'utilisateur souhaite 
 * puis test div_euc(u,v,r,q) r et q ayant déjà été initialisés à empty_pol()*/ 
void test_div_euc_p_o(void);

/* Initialise le polynome u à la valeur souhaité par l'utilisateur */
void get_pol(FILE *in, polynomial_d *u);

/* Crée autant de polynomes u et v que l'utilisateur souhaite 
 * puis test div_euc(u,v,r,q) r et q ayant déjà été initialisés à empty_pol()*/
void test_div_euc_p(void);

/* Crée autant de polynomes u et v que l'utilisateur souhaite 
 * puis test pgcd(u,v,r,q) r et q ayant déjà été initialisés à empty_pol()*/
void test_pgcd(void);

#endif


    
