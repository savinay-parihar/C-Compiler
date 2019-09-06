.data 
.text
main:
goto 7
li.s $f5,2.0
mfc1 $a0, $f5
mfc1 $v0, $f5
li.s $f0, 2.3
swc1 $f5, 8($sp)


li $v0,10
syscall
