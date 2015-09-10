.data
x:	.word 12
y:	.word 10
z:	.word 0
.text	
	lw	 $t0, x
	lw 	$t1, y
	add 	$t2, $t0, $t1
	sw 	$t3, z