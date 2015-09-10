.data
x:	.word	2		#Guarda el valor de X en la memoria
y:	.word 	3		#Guarda el valor de Y en la memoria
z: 	.word	0		#Reservamos el espacio en la mememoria para Z

.text	 
	lw	$t0, x		#Carga el valor de x
	lw	$t1, y		#Carga el valor de y
	add 	$t2, $t1, $t0	#Se suma x e y
	sw	$t2, z		#Guarda el valor en z
	
			

