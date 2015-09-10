/* -------------------------------------------------------------------
 * Limit.c
 * versión 1.0
 * Copyright (C) 2014  José Ricardo Rodríguez Abreu.
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
#include <limits.h>

int main(void)
{

  int tamano = CHAR_BIT;
  printf("Tamaño en bytes de un INT = %d\n", ((int)sizeof (int))*tamano );
  printf("El tamaño en bytes de un CHAR = %d\n", (int)sizeof (char)*tamano);
  printf("El tamaño en bytes de un SHORT = %d\n", (int)sizeof (short)*tamano);
  printf("El tamaño en bytes de un SHORT INT = %d\n", (int)sizeof (short int)*tamano);
  printf("El tamaño en bytes de un LONG = %d\n", (int)sizeof (long)*tamano);  
  printf("El tamaño en bytes de un LONG LONG = %d\n", (int)sizeof (long long)*tamano);  
  printf("El tamaño en bytes de un LONG LONG LONG = %d\n", (int)sizeof (long long long)*tamano);  

} // Fin de Limit.c
