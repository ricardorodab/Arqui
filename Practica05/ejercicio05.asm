	.data
x:	.word 1024		#Guarda el valor de X en la memoria
y:	.word 7			#Guarda el valor de Y en la memoria Y != 0
r:	.word 0 		#Reservamos el espacio en la memoria para R
c:	.word 0			#Reservamos el espacio en la memoria para C

	.text
	lw	$t0, x		#Carga el valor de x
	lw 	$t1, y		#Carga el valor de y
	lw	$t2, r		#Carga el valor de r
	lw	$t3, c		#Carga el valor de c

if: 				#Bloque if
	beqz 	$t1, fin	#Va a fin por división entre 0
	j 	else		#Como no saltó a fin, salta a else	
	
else:				#Bloque else		
	blez	$t0, residuo	#Vemos si hacemos la división. x <= 0 ?
	sub 	$t0, $t0, $t1	#Realiza la resta x-y y lo guarda en x
	bgez	$t0, divide	#Si es cero o mayor a cero aumentamos el cociente x >= 0 ?
	j	residuo		#Si x es menor que cero, saltamos para sacar el residuo.
divide:
	addi	 $t3, $t3, 1	#Añade uno al cociente
	j 	else		#Vuelve a dividir
	
residuo:
	beqz	$t0, multiplo	#Vamos a asignar a c como cero.
	add 	$t2, $t1, $t0	#Pone el residuo que sacamos de la forma y-x
	j	asignacion	#Saltamos a asignar las v1 y v0
	
multiplo:
	move	$t2, $zero	#Asignamos cero a r por ser multiplo y de x
	j 	asignacion	#Saltamos a asignar las v1 y v0
	
asignacion:
	move	$v0, $t3	#Guardamos el cociente en v0
	move	$v1, $t2	#Guardamos el residuo en v1	
	
fin:				#Bloque para finalizar el bloque if
