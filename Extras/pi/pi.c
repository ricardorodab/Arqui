/*
 * Programa para encontrar los digitos que suman 13 de pi.
 * Jose Ricardo Rodriguez Abreu.
 */
#include <stdio.h>
//Es el tamano de mi archivo.
#define TAM 12400

int main(void){
  //Suma de pi sumados dan 13
  int i, suma,j,h;
  FILE *file;
  file = fopen("pi_formato.txt","r");
  int str2[TAM];
  j = 0;
  for(i = 0; i < TAM; i++){
    int pr = fgetc(file);
    if(pr != (int)' ' && pr != (int)'\n'){
      str2[j] = pr-'0';
      j++;
    }
  }
  suma = i = 0;
  while(i < j)
    {
      for(h = i; h < i+9; h++){       
	suma += str2[h];
      }
      if(suma == 13){
	for(h = i; h < i+9; h++){       
	  printf("%d",str2[h]);
	}
	printf("\n");
	fclose(file);
	return 0;
      }
      suma = 0;
      i++;
    }
  //LEER LINEA
  /*FILE *file;
  char str[30];
  file = fopen("pi_formato.txt","r");
  fgets(str,30,file);
  char pr;
  */
  //LEER ARCHIVO
  /*
  FILE *file;
  int i;
  file = fopen("pi_formato.txt","r");
  if(file == NULL)
    return 1;
  for(i = 0; i< 12400; i++)
    {
     int pr = fgetc(file);
      if(pr != (int)' ' && pr != (int)'\n')
	printf("%c",pr);
    }
  fclose(file);
  */
  return 0;
}
