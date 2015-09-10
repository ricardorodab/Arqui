		.text
rutina_1:	# 1 Callee
		subi 	$sp, $sp, 20		# Reservar espacio en la pila (Push).
		# 2 Callee
		sw	$fp, 4($sp) 		# Guardar $fp
		sw	$ra, 0($sp)		# Guardar $ra		
		# 3 Callee
		addi 	$fp, $sp, 16		# Establecer $fp
		addi 	$t0, $zero, 1		
		addi	$s0, $t0, 10		
		# 1 Caller
		move 	$a0, $s0		# Pasar argumento en a0				
		# 2 Caller
		sw	$t0, 0($fp)		# Guardar en pila $t0		
		# 3 Caller
		jal	rutina_2 		# Llamada a subrutina		
		# 2 Al terminar Callee
		lw	$t0, 0($fp)		# Recuperar de la pila $t0		
		add	$t1, $t0, $s0		
		add	$v0, $v0, $t1		# Devolver resultado		
		lw	$ra, 0($sp)		# Restauro $ra 
		lw 	$fp, 4($sp)		# Restauro $fp
		# 3 Al terminar Callee
		addi 	$sp, $sp, 20		#N Pop		
		jr	$ra					
rutina_2:
		# 1 Callee
		subi 	$sp, $sp, 12		# Push Reservando espacio en la pila.	
		# 2 Callee
		sw	$s0, 8($sp)		# Guarda $s0
		sw	$fp, 4($sp) 		# Guarda $fp
		sw	$ra, 0($sp)		# Guarda $ra
		# 3 Callee
		addi 	$fp, $sp, 8		# Establecer $fp		
		move	$t0, $a0		# Obtener argumento de a0
		addi 	$s0, $t0, 100		
		# 1 Caller
		move 	$a0, $s0		# Pasar argumento en a0				
		# 2 Caller
		sw	$t0, 0($fp)		# Guardar en pila $t0			
		# 3 Caller
		jal	rutina_3 		# Llamada a subrutina		
		# 2 al terminar Callee
		lw	$t0, 0($fp)		# Recuperar de la pila $t0		
		add	$t1, $t0, $s0		
		add	$v0, $v0, $t1		# Devolver resultado
		lw	$ra, 0($sp)		# Restauro $ra 
		lw 	$fp, 4($sp)		# Restauro $fp
		lw	$s0, 8($sp)		# Restauro $sp
		# 3 al terminar Callee
		addi 	$sp, $sp, 12		# Pop
		jr	$ra							
rutina_3:	
		subi 	$sp, $sp, 8		# Push Reservando espacio en la pila.	
		# 2 Callee
		sw	$fp, 4($sp) 		# Guarda $fp
		sw	$ra, 0($sp)		# Guarda $ra
		# 3 Callee
		addi 	$fp, $sp, 4		# Establecer $fp
		
		move	$t0, $a0		# Obtener argumento de a0
		addi 	$v0, $t0, 1000		# Devolver resultado		
		# 6 Callee
		lw	$ra, 0($sp)		# Restauro $ra 
		lw 	$fp, 4($sp)		# Restauro $fp
		addi 	$sp, $sp, 8		# Pop		
		jr 	$ra			
