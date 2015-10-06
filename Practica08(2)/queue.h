/* Definición de una cola de cadenas a partir de una lista ligada, 
   se ofrecen funciones para crear una cola válida, encolar, desencolar, 
   ver el primer elemento y verificar si la cola está vacía */

#ifndef QUEUE_H
#define QUEUE_H

/* Definición de lista ligada */
typedef struct li
{
  char *head;
  struct li *tail;
} *linked_list;

/* Definición de cola */
typedef struct qu
{
  linked_list front;
  linked_list back;
} *queue;

/* Crea una nueva cola */
queue make_queue(void);

/* Encola el elemento e en la cola q */
void enqueue(char *e, queue q);

/* Regresa un apuntador al primer elemento de la cola y 
   lo elmina de esta. Si la cola está vacía, regresa NULL */
char *dequeue(queue q);

/* Regresa un apuntador al primer elemento  de la cola sin 
   eliminarlo. Si la cola está vacía, regresa NULL*/

char *peek(queue q);
/* Prueba si la cola está vacía 
   Regresa 1 si la cola está vacía, 0 en otro caso */
#define is_empty(X) X->front == NULL 

#endif
