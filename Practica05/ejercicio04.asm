	.data
x:	.word 1			#Guarda el valor de X en la memoria
y:	.word 0			#Guarda el valor de Y en la memoria
i:	.word 0 		#Reservamos el espacio en la memoria para I

	.text
	lw 	$t3, i		#Cargamos el valor de i
	lw	$t0, x		#Carga el valor de x
	lw 	$t1, y		#Carga el valor de y

condicion:			#Prueba que i < 100
	beq $t3, 100, fin	#Aquí ve si i == 100
	
do:				#Bloque do
	add 	$t1, $t0, $t1	#Realiza la suma x+y y lo guarda en $t1
	addi	$t3, $t3, 1	#Le sumamos 1 a i: i++
	j 	condicion	#Regresa a checar la condicion
		
fin:				#Bloque para finalizar el bloque for
	sw	$t1, y		#Guarda el valor en y	
	
