	.data
x:	.word 5		        #Guarda el valor de X en la memoria para efectos de prueba
y:	.word 10		#Guarda el valor de Y en la memoria para efectos de prueba

	.text

	lw	$t0, x			#Carga el valor de x
	lw	$t1, y			#Carga el valor de y en $t1 
	add 	$t1, $t0, $zero 	#Guarda el valor de $t0 en $t1 borrando lo que hubiera en $t1
	
