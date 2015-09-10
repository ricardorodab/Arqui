	.data
x:	.word -1		#Guarda el valor de X en la memoria
y:	.word 10		#Guarda el valor de Y en la memoria
r:	.word 0 		#Reservamos el espacio en la memoria para R

	.text
	lw	$t0, x		#Carga el valor de x
	lw 	$t1, y		#Carga el valor de y

if: 				#Bloque if
	bltz 	$t0, then	#Va a then si $t0 es menor a cero
	j 	else		#Como no saltó a then, salta a else
	
then:				#Bloque then
	add 	$t2, $t0, $t1	#Realiza la suma x+y y lo guarda en $t2
	sw	$t2, r		#Guarda el valor en r
	j 	fin		#Termina la ejecución de código
	
else:				#Bloque else		
	sub 	$t2, $t0, $t1	#Realiza la resta x-y y lo guarda en $t2
	sw 	$t2, r		#Guarda el r
	
fin:				#Bloque para finalizar el bloque if	
	
