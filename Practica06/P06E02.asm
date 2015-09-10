	.data
x:	.word	2		#Estado inicial de la variable x
y:	.word	10		#Estado inicial de la variable y
	.text
main:	
	lw	$a0,x		#Cargamos x en $a0
	lw	$a1,y
	jal 	potencia	#Llamamos la subrutina potencia
	j	exit

potencia:
	subi	$sp,$sp,8	#Reservamos espacio para la pila (Stack).	
	sw	$ra,($sp)	#push $ra
	sw	$fp,4($sp)	#push $fp
	addi	$fp,$fp,4	#establecer $fp
	beqz	$a1,return	#Branch si y = 0
	sub	$a1,$a1,1	#restamos uno a $a1
	jal	potencia	#llamamos a potencia
	move	$t0,$v0		#movemos lo de $v0 a $t0.
	mul	$v0,$t0,$a0	#multiplicamos
	move	$v1,$t0
	j	save
	
return:	li	$v0,1		#cargamos inmediato 1 en $v1	
save:	lw	$ra,($sp)	#restauramos el $ra
	lw	$fp,4($sp)	#restauramos el $fp
	addi	$sp,$sp,8	#pop de la pila
	jr	$ra		#regresar el control
exit:	nop	




