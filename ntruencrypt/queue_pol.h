#ifndef QUEUE_POL_H
#define QUEUE_POL_H

#include "polynome.h"


queue_pol *queue_new (void);
void queue_post (queue_pol **, polynomial_d *);
void queue_get (queue_pol **, polynomial_d *);
void queue_delete (queue_pol **);

#endif 
