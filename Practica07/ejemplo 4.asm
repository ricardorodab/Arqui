	.data
str: 	.asciiz	"lamoralccaromal"
palin:	.asciiz	"La palabra es palindromo"
nopalin:.asciiz	"La palabra no es palindromo"
len:	.word	15
	
	.text

	la	$t0, str		#Cargamos dir inicio
	lw	$t1, len		#Cargamos longitud
	add	$t2, $t0, $t1		#Calculamos dir último
	subi	$t2, $t2, 1		#Restamos 1 para obtener ultumo byte
loop:	
	bge	$t0, $t2, sipalin
	lb 	$t4, ($t2) 
	lb	$t3, ($t0)
	addi	$t0, $t0, 1
	subi	$t2, $t2, 1
	beq	$t3, $t4, loop
	la	$a0, nopalin
	li	$v0, 4
	syscall
	j exit
sipalin:la	$a0, palin
	li	$v0, 4
	syscall
	
	
exit:	li $v0, 10
	syscall
