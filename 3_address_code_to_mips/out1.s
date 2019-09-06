addthem:
lw $a0, 4($sp)
sw $a0, 0($sp)
addiu $sp, $sp, -4
lw $a0, 8($sp)
lw $t1, 4($sp)
addiu $sp, $sp, 4
add $a0, $a0, $t1
sw $a0, 0($sp)
lw $v0, 16($sp)
jr $ra
main:
li $a0, 8
sw $a0, 20($sp)
lw $a0, 20($sp)
sw $a0, 24($sp)
li $a0, 4
sw $a0, 16($sp)
lw $a0, 16($sp)
sw $a0, 4($sp)
li $a0, 3
sw $a0, 28($sp)
lw $a0, 28($sp)
sw $a0, 8($sp)
lw $a0, 4($sp)
lw $a1, 8($sp)
jal addthem
li $v0,10
syscall