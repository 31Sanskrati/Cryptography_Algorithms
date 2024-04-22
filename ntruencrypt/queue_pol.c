#include <stdio.h>
#include <stdlib.h>
#include "queue_pol.h"
#include "polynome.h"
static void queue_first (queue_pol**);
static void queue_prev (queue_pol**);
static void queue_last (queue_pol**);
static void queue_next (queue_pol**);

queue_pol*queue_new (void)
{
   return (NULL);
}

void queue_post (queue_pol** pp_queue, polynomial_d *p_d)
{
   if (pp_queue != NULL)
   {
      queue_pol*p_l = NULL;
      queue_pol*p_p = NULL;

      queue_first (pp_queue);
      p_l = *pp_queue;
      p_p = malloc (sizeof (*p_p));
      if (p_p != NULL)
      {
         p_p->p_d = p_d;
         p_p->next = p_l;
         p_p->prev = NULL;
         if (p_l != NULL)
            p_l->prev = p_p;
         *pp_queue = p_p;
      }     
      else
      {
         fprintf (stderr, "Memoire insuffisante\n");
         exit (EXIT_FAILURE);
      }
   }
   return;
}

void queue_get (queue_pol** pp_queue, polynomial_d *p_d)
{
   if (pp_queue != NULL && *pp_queue != NULL)
   {
      queue_pol*p_l = NULL;
      queue_pol*p_p = NULL;
      
      queue_last (pp_queue);
      p_l = *pp_queue;
      if (p_l != NULL)
         p_p = p_l->prev;
      p_d->deg = p_l->p_d->deg;
      p_d->p = p_l->p_d->p;
      free (p_l);
      p_l = NULL;
      if (p_p != NULL)
         p_p->next = NULL;
      *pp_queue = p_p;
   }
}

void queue_delete (queue_pol** pp_queue)
{
    polynomial_d *p_dd=empty_pol();
   if (pp_queue != NULL && *pp_queue != NULL)
   {
      while (*pp_queue != NULL){
          queue_get (pp_queue,p_dd);
          free(p_dd);
      }
   }
   return;
}

static void queue_first (queue_pol** pp_queue)
{
   if (pp_queue != NULL && *pp_queue != NULL)
   {
      while ((*pp_queue)->prev != NULL)
         queue_prev (pp_queue);
   }
   return;
}

static void queue_prev (queue_pol** pp_queue)
{
   if (pp_queue != NULL && *pp_queue != NULL)
      *pp_queue = (*pp_queue)->prev;
   return;
}

static void queue_last (queue_pol** pp_queue)
{
   if (pp_queue != NULL && *pp_queue != NULL)
   {
      while ((*pp_queue)->next != NULL)
         queue_next (pp_queue);
   }
   return;
}

static void queue_next (queue_pol** pp_queue)
{
   if (pp_queue != NULL && *pp_queue != NULL)
      *pp_queue = (*pp_queue)->next;
   return;
}
