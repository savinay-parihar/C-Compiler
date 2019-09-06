.data
 .text
 j main
main:
l2: li.s $f0, 4.0
swc1 $f0, 0($sp)
l3: lwc1 $f0, 0($sp)
swc1 $f0, 8($sp)
l4: li.s $f0, 6.0
swc1 $f0, 16($sp)
l5: lwc1 $f0, 16($sp)
swc1 $f0, 24($sp)
l6: li.s $f0, 0.0
swc1 $f0, 32($sp)
l7: lwc1 $f0, 32($sp)
swc1 $f0, 40($sp)
l8: li.s $f0, 0.0
swc1 $f0, 48($sp)
l9: lwc1 $f0, 48($sp)
swc1 $f0, 40($sp)
l10: li.s $f0, 3.0
swc1 $f0, 56($sp)
l11: lwc1 $f0, 40($sp)
lwc1 $f1, 56($sp)
c.lt.s $f0, $f1
bc1t l17
l12: j l20
l13: lwc1 $f0, 40($sp)
swc1 $f0, 64($sp)
l14: lwc1 $f0, 40($sp)
li.s $f1, 1.0
add.s $f0, $f0, $f1
swc1 $f0, 72($sp)
l15: lwc1 $f0, 72($sp)
swc1 $f0, 40($sp)
l16: j l10
l17: lwc1 $f0, 8($sp)
lwc1 $f1, 24($sp)
add.s $f0, $f0, $f1
swc1 $f0, 80($sp)
l18: lwc1 $f0, 80($sp)
swc1 $f0, 8($sp)
l19: j l11
l20: li.s $f0, 6.0
swc1 $f0, 88($sp)
l21: lwc1 $f0, 88($sp)
swc1 $f0, 40($sp)
li $v0, 10
 syscall
