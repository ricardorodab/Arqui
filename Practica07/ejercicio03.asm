#Jose Ricardo Rodriguez Abreu
		.data
cadena:		.space 64			#Espacio de la palabra.
cadenaFinal:	.space 64			#Espacio para la cadena final.
length:		.word   0 			#Es el tamaño de la cadena.
		.text	
main:	
		la	$a2, cadenaFinal 	#Asignamos el tamaño a la cadena final.		
		li	$v0, 8			#Llamamos para el input.
		la	$a0, cadena		#Guardamos el espaciode la cadena.
		la	$a1, 64			#Reservamos el espacio de la cadena.
		move 	$s0,$a0			#Movemos la cadena a $s0.
		syscall
		jal	tamano
		move	$a1, $v0		#Guardamos el resultado como argumento.
		jal	reversa				
imprime:
		la	$a0, cadenaFinal	#Pasamos la cadena final a $a0.
		li	$v0,4			#Imprimimos la cadena.
		syscall						
exit:
		li	$v0, 10			#Terminamos el programa.
		syscall		
	
		
			
					
reversa:
		add	$t2, $a0, $a1		#Calculamos la dirección del último
		subi	$t2, $t2, 1		#Restamos 1 para obtener el ultimo byte	
loopr:		
		lb	$t0, 0($t2)		#Cargamos la letra.
		beqz 	$t0, salir 		#Salimos de pega1 si es cero.      
		#beq 	$t0, $t1 salir 		#Salimos de pega1 si es salto de linea.
		sb	$t0, 0($a2) 		#Cargamos el byte en $a2.
		subi	$t2, $t2, 1		#Movemos la palabra palabra.
		addi	$a2, $a2, 1		#Movemos la palabra final.
		j	loopr			#Volvemos al ciclo.		
salir:
		jr	$ra			#Volvemos.
	
	
	
tamano:
		move	$t0, $a0		#Copiamos la cadena.
		lw 	$t1, length		#Cargamos el tamaño de la cadena.
loop:	
		addi	$t0, $t0, 1		#Tomamosel siguiente caracter.
		lb	$t3, ($t0)		#Cargamos una letra.
		beqz	$t3, fin		#Si es igual que cero imprime la cuenta.
		addi 	$t1,$t1,1		#Añadimos uno en caso contario.
		j	loop			#Regresamos al loop.
fin:		
		move	$v0, $t1		#Regresamos el resultado.
		jr	$ra			#Volvemos.