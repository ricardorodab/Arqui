.data
x:	.word 12
y:	.word 10
z:	.word 0
.text	
	lw	$t0, x
	lw 	$t1, y
	lw 	$t2, z
etiqutea:	
	beq $t1, $t2, ocho
	j otro
ocho: 
	add $t2, $zero, 8
	j fin
otro:  
	add $t2, $zero, 7
fin:
