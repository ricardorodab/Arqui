	.data
x:	.word	4			# Guarda el valor de X en la memoria
y:	.word 	8			# Guarda el valor de Y en la memoria
z: 	.word	0			# Reservamos el espacio en la mememoria para Z

	.text	 
main:	lw	$a0, x			# Argumento para la rutina x*y
	lw	$a1, y			# Argumento para la rutina x*y
	
	# Inicio rutina multiplicacion (sumar x + x y veces)
	# 1 Callee
	subi 	$sp, $sp, 20		# Reservar espacio en la pila (Push).
	# 2 Callee
	sw	$fp, 4($sp) 		# Guardar $fp
	sw	$ra, 0($sp)		# Guardar $ra
	# 3 Callee
	addi 	$fp, $sp, 16		# Establecer $fp
	# 4 Callee 
	move	$t0, $a0		# Recuperar argumento x	
	move	$t1, $a1		# Recuperar argumento y
	add	$t2, $zero, $zero	# Iniciar acumulador  z
loop:	beqz 	$t1, exit		# Verificar si ya se realizaron todas las sumas.	
	# 1 Caller
	move 	$a0, $t0		# Pasar argumento x
	move	$a1, $t2		# Pasar argumento z
	# 2 Caller
	sw	$t0, 0($fp)		# Guardar en pila $t0
	sw	$t1, -4($fp)		# Guardar en pila $t1
	sw	$t2, -8($fp)		# Guardar en pila $t2
	#3 Caller
	jal	suma
	lw	$t0, 0($fp)		# Recuperar de la pila $t0
	lw	$t1, -4($fp)		# Recuperar de la pila $t1
	lw	$t2, -8($fp)		# Recuperar de la pila $t2
	subi	$t1, $t1, 1		# Disminuir contador 
	move	$t2, $v0		# Actualizar acumulador z con el resultado de la suma
	j	loop			# Saltar para verificar si ya termino
exit:	# 5 Callee 
	move	$v0, $t2		# Pasar resultado
	# 6 Callee
	lw	$ra, 0($sp)		# Restaurar $ra 
	lw 	$fp, 4($sp)		# Restaurar $fp
	# 7 Callee
	addi 	$sp, $sp, 20		# Pop
	# 8 Callee
	jr	$ra			# Regresar al caller
	#Fin rutina multiplicacion.
		
suma:	# Inicio rutina suma
	# 1 Callee
	subi 	$sp, $sp, 8		# Push Reservando espacio en la pila.
	# 2 Callee
	sw	$fp, 4($sp) 		# Guarda $fp
	sw	$ra, 0($sp)		# Guarda $ra
	# 3 Callee
	addi 	$fp, $sp, 4		# Establecer $fp
	# 4 Callee
	add 	$t0, $a0, $a1		# Se suma x y y
	# 5 Callee
	move 	$v0, $t0		# Se pasa el recultado
	# 6 Callee
	lw	$ra, 0($sp)		# Restauro $ra 
	lw 	$fp, 4($sp)		# Restauro $fp
	# 7 Callee
	addi 	$sp, $sp, 8		# Pop
	# 8 Callee
	jr	$ra			# Regresar al caller
	# Fin rutina suma
