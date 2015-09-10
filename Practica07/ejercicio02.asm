#Jose Ricardo Rodriguez Abreu
		.data
cadena1:	.space	 64			#Espacio para la cadena 1.
cadena2:	.space 	 64			#Espacio para la cadena 2.
cadenaFinal:	.space 	128			#Espacio para la cadena final.
		.text
main:	
		la	$a2, cadenaFinal 	#Asignamos el tamaño a la cadena final.		
entrada1:
		la	$a0, cadena1		#Guardamos a la cadena 1.
		la	$a1, 64			#Asignamos espacio para cadena 1.
		li	$v0, 8			#Llamamos para el input.
		syscall
		move	$s0, $a0		#Guardamos la cadena en $s0
entrada2:
		la	$a0, cadena2		#Guardamos a la cadena 2.
		la	$a1, 64			#Asignamos espacio para cadena 2.
		li	$v0, 8			#Llamamos para el input.
		syscall
		move	$s1, $a0		#Guardamos la cadena en $s1.
		
		li	$t1 10 			#Asignamos el 10 para el salto de linea.
		la	$a0, cadena1		#Ponemos el argumento en $a0.
		la	$a1, cadena2		#Ponemos el argumento en $a1.
		jal	concat			#Llamamos a la subrutina.
		
imprime:
		la	$a0, cadenaFinal	#Pasamos la cadena final a $a0.
		li	$v0,4			#Imprimimos la cadena.
		syscall						
exit:
		li	$v0, 10			#Terminamos el programa.
		syscall		

concat:		
pega1:
		lb	$t0, 0($a0)		#Cargamos la letra.
		beqz 	$t0, pega2 		#Salimos de pega1 si es cero.      
		beq 	$t0, $t1 pega2 		#Salimos de pega1 si es salto de linea.
		sb	$t0, 0($a2) 		#Cargamos el byte en $a0.
		addi	$a0, $a0, 1		#Movemos la primer palabra.
		addi	$a2, $a2, 1		#Movemos la palabra final.
		j	pega1			#Volvemos al ciclo.
pega2:
		lb	$t0, 0($a1)		#Cargamos la letra.
		beqz 	$t0, salir 		#Salimos de pega1 si es cero.      
		beq 	$t0, $t1 salir 		#Salimos de pega1 si es salto de linea.
		sb	$t0, 0($a2) 		#Cargamos el byte en $t0.
		addi	$a1, $a1, 1		#Movemos la primer palabra.
		addi	$a2, $a2, 1		#Movemos la palabra final.
		j	pega2
salir:		
		sb	$zero 0($a0)		#Le agregamos el fin de cadena.
		jr	$ra			#Terminamos la subrutina.