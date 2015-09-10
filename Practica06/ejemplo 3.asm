#Universidad Nacional Autonoma de México
#Facultad de Ciencia
#Organización y Arquitectura de Computadoras

#Fibonacci
	.data
x:	.word	7		#Estado inicial de la variable x
	
	.text
main:	
	lw	$a0,x		#Cargamos x en $a0
	jal 	fibonacci	#Llamamos la subrutina fibonacci
	j	exit

fibonacci:
	subi	$sp,$sp,8	#Reservamos espacio para la pila (Stack).	
	sw	$ra,($sp)	#push $ra
	sw	$fp,4($sp)	#push $fp
	addi	$fp,$fp,4	#establecer $fp
	#tarea
	beq	$a0,1,return	#Branch si x = 1
	sub	$a0,$a0,1	#restamos uno a $a0
	jal	fibonacci	#llamamos a fibonacci
	move	$t0,$v0		#movemos lo de $v0 a $t0.
	add	$v0,$t0,$v1	#sumamos
	move	$v1,$t0
	j	save
	
return:	li	$v0,1		#cargamos inmediato 1 en $v1	
	li	$v1,1		#cargamos inmediato 1 en $v1
save:	lw	$ra,($sp)	#restauramos el $ra
	lw	$fp,4($sp)	#restauramos el $fp
	addi	$sp,$sp,8	#pop de la pila
	jr	$ra		#regresar el control
exit:	nop			#Fin
