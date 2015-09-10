	.data
x:	.word 42		#Guarda el valor de X en la memoria
y:	.word 56		#Guarda el valor de Y en la memoria Y
r:	.word 0 		#Reservamos el espacio en la memoria para R

	.text
	lw	$t0, x		#Carga el valor de x
	lw 	$t1, y		#Carga el valor de y
	lw	$t2, r		#Carga el valor de r

	

if: 				#Bloque if
	bgt  	$t0, $t1 else	#A else si x>y
	j 	ymayor		#Cambio valores si x < y	

ymayor:
	move	$t0, $t1	#Cargo el mayor en t0
	lw	$t1, x		#Cargo x (el menor) en t1	
	
else:				#Bloque else		
	blez	$t0, residuo	#Vemos si hacemos la división. x <= 0 ?
	sub 	$t0, $t0, $t1	#Realiza la resta x-y y lo guarda en x
	bgez	$t0, else	#Si es cero o mayor a cero volvemos a dividir
	j	residuo		#Si x es menor que cero, saltamos para sacar el residuo.
	
residuo:
	beqz	$t0, multiplo	#Vamos a asignar a Y como MCD.
	add 	$t2, $t1, $t0	#Pone el residuo que sacamos de la forma y-x
	j	asignacion	#Saltamos a asignar las v1 y v0
	
multiplo:
	move	$v0, $t1 	#Asignamos cero a r por ser multiplo y de x
	j 	fin		#Saltamos a temrinar la ejecución
	
asignacion:
	move	$t0, $t1	#Guardamos el cociente en t0 (el nuevo x)
	move	$t1, $t2	#Guardamos el residuo en t1 (el nuevo y)	
	j	else
	
fin:				#Bloque para finalizar el bloque if