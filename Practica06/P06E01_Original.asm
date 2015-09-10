		.text
rutina_1:	addi 	$t0, $zero, 1
		addi	$s0, $t0, 10		
		move 	$a0, $s0		# Pasar argumento en a0		
		jal	rutina_2 		# Llamada a subrutina
		add	$t1, $t0, $s0		
		add	$v0, $v0, $t1		# Devolver resultado
		jr	$ra			
		
rutina_2:	move	$t0, $a0		# Obtener argumento de a0
		addi 	$s0, $t0, 100		
		move 	$a0, $s0		# Pasar argumento en a0		
		jal	rutina_3 		# Llamada a subrutina
		add	$t1, $t0, $s0		
		add	$v0, $v0, $t1		# Devolver resultado
		jr	$ra			
				
rutina_3:	move	$t0, $a0		# Obtener argumento de a0
		addi 	$v0, $t0, 1000		# Devolver resultado
		jr 	$ra			
