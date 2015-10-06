	add	$01 $00 $00
	addi	$02 $00 10
	addi 	$03 $00 1
foo:	sw	$01 0($01)
	add	$01 $01 $03
	bgt	$02 $01 foo
