/* -------------------------------------------------------------------
 * Pract08.c
 * versión 1.0
 * Copyright (C) 2015  José Ricardo Rodríguez Abreu.
 * Facultad de Ciencias,
 * Universidad Nacional Autónoma de México, Mexico.
 *
 * Este programa es software libre; se puede redistribuir
 * y/o modificar en los términos establecidos por la
 * Licencia Pública General de GNU tal como fue publicada
 * por la Free Software Foundation en la versión 2 o
 * superior.
 *
 * Este programa es distribuido con la esperanza de que
 * resulte de utilidad, pero SIN GARANTÍA ALGUNA; de hecho
 * sin la garantía implícita de COMERCIALIZACIÓN o
 * ADECUACIÓN PARA PROPÓSITOS PARTICULARES. Véase la
 * Licencia Pública General de GNU para mayores detalles.
 *
 * Con este programa se debe haber recibido una copia de la
 * Licencia Pública General de GNU, de no ser así, visite el
 * siguiente URL:
 * http://www.gnu.org/licenses/gpl.html
 * o escriba a la Free Software Foundation Inc.,
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * -------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

/* El maximo numero de caracteres que soporta una linea. */
#define MAXLONG 1000

/* Tipo line para guardar una linea.*/
typedef struct
{
  char *cadena;
  int linea;
} line;

/* Funcion que nos regresa una cadena sin el primer caracter
   de la original. */
char *strEliminaPrimero(char *string)
{
  char *nuevaCadena;
  int longitud = strlen(string);
  char cadena[longitud-1];
  nuevaCadena = malloc(sizeof(cadena));
  int i;
  for(i = 0; i < longitud-1; i++)
    {
      nuevaCadena[i] = string[i+1];
    }
  return nuevaCadena;
}

/* Funcion para crear el numero en binario.*/
void escribeNumero(int registro, int limite, FILE *fp)
{
  int i,j;
  for(i = limite-1; i >= 0; i--){
    j = registro >> i;
    if(j & 1){
      //Escribe 1.
      fprintf(fp,"1");
    }else{
      //Escribe 0.
      fprintf(fp,"0");
    }    
  }
}

/* Funcion para revisar los casos posibles. */
void caso(char *cadena, queue cola,FILE *fp,line *label)
{
  if(strcmp(cadena, "lw") == 0)
    {
      //000001
      fprintf(fp,"000001");
      char *segundo = dequeue(cola);
      char *primero = dequeue(cola);
      char registro1[3];
      char desplaza[10];
      int i = 0;
      while(primero[i] != '(')
	{
	  desplaza[i] = primero[i];
	  i++;
	}
      desplaza[i++] = '\0';
      registro1[0] = primero[++i];
      registro1[1] = primero[++i];
      registro1[2] = '\0';
      escribeNumero(atoi(registro1),5,fp);
      escribeNumero(atoi(strEliminaPrimero(segundo)),5,fp);
      escribeNumero(atoi(desplaza),16,fp);
    }
  else if(strcmp(cadena, "lh") == 0)
    {
      //000010
      fprintf(fp,"000010");
      char *segundo = dequeue(cola);
      char *primero = dequeue(cola);
      char registro1[3];
      char desplaza[10];
      int i = 0;
      while(primero[i] != '(')
	{
	  desplaza[i] = primero[i];
	  i++;
	}
      desplaza[i++] = '\0';
      registro1[0] = primero[++i];
      registro1[1] = primero[++i];
      registro1[2] = '\0';
      escribeNumero(atoi(registro1),5,fp);
      escribeNumero(atoi(strEliminaPrimero(segundo)),5,fp);
      escribeNumero(atoi(desplaza),16,fp);
    }
  else if(strcmp(cadena, "lb") == 0)
    {
      //000011
      fprintf(fp,"000011");
      char *segundo = dequeue(cola);
      char *primero = dequeue(cola);
      char registro1[3];
      char desplaza[10];
      int i = 0;
      while(primero[i] != '(')
	{
	  desplaza[i] = primero[i];
	  i++;
	}
      desplaza[i++] = '\0';
      registro1[0] = primero[++i];
      registro1[1] = primero[++i];
      registro1[2] = '\0';
      escribeNumero(atoi(registro1),5,fp);
      escribeNumero(atoi(strEliminaPrimero(segundo)),5,fp);
      escribeNumero(atoi(desplaza),16,fp);
    }
  else if(strcmp(cadena, "sw") == 0)
    {
      //000100
      fprintf(fp,"000100");
      char *segundo = dequeue(cola);
      char *primero = dequeue(cola);
      char registro1[3];
      char desplaza[10];
      int i = 0;
      while(primero[i] != '(')
	{
	  desplaza[i] = primero[i];
	  i++;
	}
      desplaza[i++] = '\0';
      registro1[0] = primero[++i];
      registro1[1] = primero[++i];
      registro1[2] = '\0';
      escribeNumero(atoi(registro1),5,fp);
      escribeNumero(atoi(strEliminaPrimero(segundo)),5,fp);
      escribeNumero(atoi(desplaza),16,fp);
    }
  else if(strcmp(cadena, "sh") == 0)
    {
      //000101
      fprintf(fp,"000101");
      char *segundo = dequeue(cola);
      char *primero = dequeue(cola);
      char registro1[3];
      char desplaza[10];
      int i = 0;
      while(primero[i] != '(')
	{
	  desplaza[i] = primero[i];
	  i++;
	}
      desplaza[i++] = '\0';
      registro1[0] = primero[++i];
      registro1[1] = primero[++i];
      registro1[2] = '\0';
      escribeNumero(atoi(registro1),5,fp);
      escribeNumero(atoi(strEliminaPrimero(segundo)),5,fp);
      escribeNumero(atoi(desplaza),16,fp);
    }
  else if(strcmp(cadena, "sb") == 0)
    {
      //000110
      fprintf(fp,"000110");
      char *segundo = dequeue(cola);
      char *primero = dequeue(cola);
      char registro1[3];
      char desplaza[10];
      int i = 0;
      while(primero[i] != '(')
	{
	  desplaza[i] = primero[i];
	  i++;
	}
      desplaza[i++] = '\0';
      registro1[0] = primero[++i];
      registro1[1] = primero[++i];
      registro1[2] = '\0';
      escribeNumero(atoi(registro1),5,fp);
      escribeNumero(atoi(strEliminaPrimero(segundo)),5,fp);
      escribeNumero(atoi(desplaza),16,fp);
    }
  else if(strcmp(cadena, "add") == 0)
    {
      //000111
      fprintf(fp,"000111");
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(1,11,fp); //OPERACION 1
    }
  else if(strcmp(cadena, "addi") == 0)
    {
      //001000
      fprintf(fp,"001000");
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(dequeue(cola)),16,fp);
    }
  else if(strcmp(cadena, "sub") == 0)
    {
      //001001
      fprintf(fp,"001001");
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(3,11,fp); //OPERACION 11
    }
  else if(strcmp(cadena, "subi") == 0)
    {
      //001010
      fprintf(fp,"001010");
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(dequeue(cola)),16,fp);
    }
  else if(strcmp(cadena, "and") == 0)
    {
      //001011
      fprintf(fp,"001011");
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(7,11,fp); //OPERACION 111
    }
  else if(strcmp(cadena, "andi") == 0)
    {
      //001100
      fprintf(fp,"001100");
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(dequeue(cola)),16,fp);
    }
  else if(strcmp(cadena, "or") == 0)
    {
      //001101
      fprintf(fp,"001101");
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(15,11,fp); //OPERACION 1111
    }
  else if(strcmp(cadena, "ori") == 0)
    {
      //001110
      fprintf(fp,"001110");
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(dequeue(cola)),16,fp);
    }
  else if(strcmp(cadena, "beq") == 0)
    {
      //001111
      fprintf(fp,"001111");
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      int i = 0;
      char *etiqueta = dequeue(cola);
      while(strcmp(label[i++].cadena,etiqueta) != 0);
      line linea = label[--i]; 
      escribeNumero(linea.linea,16,fp);
    }
  else if(strcmp(cadena, "bgt") == 0)
    {
      //010000
      fprintf(fp,"010000");
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      escribeNumero(atoi(strEliminaPrimero(dequeue(cola))),5,fp);
      int i = 0;
      char *etiqueta = dequeue(cola);
      while(strcmp(label[i++].cadena,etiqueta) != 0);
      line linea = label[--i]; 
      escribeNumero(linea.linea,16,fp);
    }
  else if(strcmp(cadena, "j") == 0)
    {
      //010001
      fprintf(fp,"010001");
      int i = 0;
      char *etiqueta = dequeue(cola);
      while(strcmp(label[i++].cadena,etiqueta) != 0);
      line linea = label[--i]; 
      escribeNumero(linea.linea,26,fp);
    }
  else if(strcmp(cadena, "jr") == 0)
    {
      //010010
      fprintf(fp,"010010");
      int i = 0;
      char *etiqueta = dequeue(cola);
      while(strcmp(label[i++].cadena,etiqueta) != 0);
      line linea = label[--i]; 
      escribeNumero(linea.linea,26,fp);
    }
  else
    {
      //En caso de encontrarnos una etiqueta.
      return;
    }
  //Escribir salto de línea.
  fprintf(fp,"\n");
}

/*-----------------------------------------------
 * Funcion principal del programa.
 *-----------------------------------------------
 */
int main(int argc, char *argv[])
{
  int i,numLinea, numEtiquetas;
  // Reservamos para el maximo numero de lineas un espacio.
  char linea[MAXLONG];
  // A lo mas 60 lineas ergo 60 etiquetas.
  line label[60];
  // Usaremos este apuntador de cadenas para parsearlas a todas
  char *palabra;
  //Creamos una cola donde se guardara el parseo.
  queue cola = make_queue();
  //Si el parametro no es valido terminamos.
  if(argv[1] == NULL){
    printf("Favor de ejecutar el programa con \"./a.out <Nombre del archivo>\"\n");
    return 0;
  }
  //Abrimos el archivo que nos hayan pasado como argumento.
  FILE *file;  
  file = fopen(argv[1],"r");
  //Revisamos si el archivo abrio bien.
  if(file == NULL){
    printf("El archivo no existe o existe un problema al abrirlo.\n");
    return 1;
  }
  numLinea = numEtiquetas = 0;
  //Mientras no haya terminado de leer el archivo:
  while(fgets(linea,MAXLONG,file) && !feof(file))
    {
      //No sabemos si la primera palabra es etiqueta. 
      int etiqueta = 0;
      //Iniciamos una nueva palabra a parsear.
      palabra = "";
      i = 0;
      while(linea[i] != '\0' && linea[i] != '#' && linea[i] != '\n')
	{
	  //Nos saltamos los tabuladores y los espacios.
	  while(linea[i] == ' ' || linea[i] == '\t'){
	    i++;
	  }
	  //Entramos a la palabra.
	  while(linea[i] != ' ' && linea[i] != '\0' &&
		linea[i] != '#' && linea[i] != '\n' &&
		linea[i] != '\t')
	    {	      	     
	      char c = linea[i++];
	      char nuevaPalabra[strlen(palabra)+1];	      
	      strcpy(nuevaPalabra,palabra);	      
	      strncat(nuevaPalabra,&c,1);
	      palabra = malloc(sizeof(nuevaPalabra));
	      int j = 0;
	      //Mini while para copiar la palabra.
	      while(nuevaPalabra[j] != '\0'){
		palabra[j] = nuevaPalabra[j];
		if(palabra[j] == ':')
		  {		    
		    etiqueta = 1;
		  }		
		j++;
	      }
	    }	  
	  //Si es etiqueta la agregamos.
	  if(etiqueta)
	    {	      
	      //Le quitamos los dos puntos.
	      palabra[strlen(palabra)-1] = '\0';
	      line linea = {palabra,numLinea};
	      label[numEtiquetas] = linea;
	      etiqueta = 0;
	      numEtiquetas++;
	    }
	  if(strlen(palabra) > 0)
	    {
	      enqueue(palabra,cola);
	    }
	  palabra = "";
	}
      numLinea++;
    }
  //Creamos nuestro archivo de salida y cambiamos extension a .o.
  FILE *salida;
  char nombreSalida[strlen(argv[1])];
  strcpy(nombreSalida,argv[1]);
  i = 0;
  while(nombreSalida[i] != '.' && nombreSalida[i] != '\0')
    {
      i++;
    }
  nombreSalida[++i] = 'o';
  nombreSalida[++i] = '\0';
  salida = fopen(nombreSalida,"w");
  //Revisamos si el archivo abrio bien.
  if(salida == NULL){
    printf("Problema al crear el archivo %s.\n",nombreSalida);
    return 1;
  }
  //14 CASOS!
  while(!(is_empty(cola)))
    caso(dequeue(cola),cola,salida,label);  
  fclose(salida);
  fclose(file);
  return 0;
} //Fin de Pract08.c
