#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
  /* Creación de una cola */
  queue q = make_queue();

  /* Prueba de is_empty */
  printf("La cola está vacía?: %d \n", is_empty(q));

  /* Se agregan tres elementos a la cola */
  char *c = "cadena 1";
  enqueue(c, q);
  enqueue("cadena 2", q);
  c = "cadena 3";
  enqueue(c, q);   

  /* Prueba de is_empty */
  printf("La cola está vacía?: %d \n", is_empty(q));

  /* Prueba peek */
  printf("peek 1: %s \n", peek(q));
  
  /* Prueba dequeue */
  char *d = dequeue(q);
  printf("dequeue 1 : %s \n", d);
  free(d);
  
  /* Prueba peek */
  printf("peek 2: %s \n", peek(q));

  /* Prueba dequeue */
  d = dequeue(q);
  printf("dequeue 2 : %s \n", d);
  free(d);
  
  /* Prueba peek */
  printf("peek 3: %s \n", peek(q));

  /* Prueba dequeue */
  d = dequeue(q);
  printf("dequeue 3 : %s \n", d);
  free(d);
  
  /* Prueba peek */
  printf("peek 4: %s \n", peek(q));

  /* Prueba dequeue */
  d = dequeue(q);
  printf("dequeue 4 : %s \n", d);

  /* Prueba de is_empty */
  printf("La cola está vacía?: %d \n", is_empty(q));
  free(q);  

}

