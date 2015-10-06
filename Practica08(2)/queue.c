#include <stdlib.h>
#include <string.h>
#include "queue.h"

queue make_queue(void)
{
  queue q =  malloc(sizeof(queue));
  /* Inicializar apuntadoras a NULL */ 
  q->front = NULL;  
  q->back = NULL;
  return q;
}

void enqueue(char *e, queue q)
{
  /* Se reserva espacio para el nuevo elemento,
     se inicilaizan los apuntadores y se copia la cadena */
  linked_list n = malloc(sizeof(linked_list));
  n->head = malloc(strlen(e) + 1);
  n->tail = NULL;
  strcpy(n->head, e);
  if(is_empty(q))
    {
      /* Si la cola está vacía, el frente y el final 
	 deben apuntar al mismo elemento */
      q->front = n;
      q->back = n;
    }
  else
    {
      /* El final apunta al nuevo elemento y
	 se actualiza la lista */
      q->back->tail = n;
      q->back = n;
    }
}

char *dequeue(queue q)
{
  /* Si la cola está vacía, regresa NULL */
  if(is_empty(q))
    return NULL;
  /* Obtenemos la dirección de la cadena 
     y la dirección del primer elemento */
  char *c = q->front->head;
  linked_list l = q->front;
  if(q->back == q->front)
    /* Si sólo hay un elemento en la cola,
       el inicio y el final deberán apuntan a NULL */
    q->back = NULL;
  q->front = q->front->tail;
  free(l);
  return c;
}

char *peek(queue q)
{
  return is_empty(q) ? NULL: q->front->head;
}

