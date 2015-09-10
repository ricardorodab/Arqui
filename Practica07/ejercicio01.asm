#Jose Ricardo Rodriguez Abreu
		.data
cadena:		.space 64		#Espacio de la palabra.
length:		.word 0 		#Es el tamaño de la cadena.
		.text	
main:	
		li	$v0, 8		#Llamamos para el input.
		la	$a0, cadena	#Guardamos el espaciode la cadena.
		la	$a1, 64		#Reservamos el espacio de la cadena.
		move 	$t0,$a0		#Movemos la cadena a $t0.
		syscall
		lw 	$t1, length	#Cargamos el tamaño de la cadena.
loop:	
		addi	$t0, $t0, 1	#Tomamosel siguiente caracter.
		lb	$t3, ($t0)	#Cargamos una letra.
		beqz	$t3, imprime	#Si es igual que cero imprime la cuenta.
		addi 	$t1,$t1,1	#Añadimos uno en caso contario.
		j	loop		#Regresamos al loop.
imprime:
		add	$a0,$t1,$zero	#Colocamos el conteoen $a0.
		li	$v0,1		#Ordenamos imprimir.
		syscall		
exit:
		li $v0, 10		#Salimos del programa.
		syscall