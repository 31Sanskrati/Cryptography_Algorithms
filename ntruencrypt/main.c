#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "polynome.h"
#include "test.h"

int main()
{
    polynomial_d *t1=empty_pol();
    t1->p[0]=1;
    t1->p[1]=-1;
    degr(t1);
    print_pol(t1);printf("\n");
    polynomial_d *test=empty_pol();
    print_pol(test);
    lin_comb(empty_pol(),t1->p[t1->deg],t1,test);
    print_pol(test);printf("\n");
    test_div_euc_p();
    
    return 0;
}
