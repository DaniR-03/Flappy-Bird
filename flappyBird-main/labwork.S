  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #
  
.data
.globl hexasc, delay, time2string, enable_interrupt
.text
  #Hexasc**
hexasc:     
	move     $v0, $a0
    andi     $a0, $a0, 15

    li      $t0, 10

    slt     $t1, $a0, $t0 
    beq     $t1, 1, number
    addi    $a0, $a0, 7

number:     
	addi     $a0, $a0, 48
    move    $v0, $a0
    jr    $ra
    nop
#delay **
delay:    
	li     $t3, 1000 # int ms = 1000
    	li     $t4, 6500 #int k = 6500
    	li     $t0, 0 #int i = 0

    	move      $t1, $t3
    	move     $s0, $ra
    	jal     delaystart
    	nop
    	jr     $s0
    	nop

delaystart: 
	slt     $t5, $t1, $0
    	bne    $t5, 1, while
    	jr     $ra
    	nop

while:   
	subu    $t1, $t1, 1
    	li    $t0, 0
    	j    loop2
    	nop
loop2:
    slt     $t2, $t0, $t4
    addi     $t0, $t0, 1
    bne    $t2, 0, loop2

    j    delaystart
    nop
    
    
#time2string **

time2string:
	PUSH  $ra
    	PUSH  $s0
    	PUSH  $s1

    move    $s0, $a0    #$s0 adressen 
    move     $s1, $a1    #move     $t1 $a1    #$a1 hela korven

    #Digit 4
    andi     $a0, $s1, 0xF000    #0x000F
    srl    $a0, $a0, 12
    jal    hexasc
    nop
    sb    $v0, 0($s0)

    #Digit 3
    andi    $a0, $s1, 0xF00    #0x00F
    srl    $a0, $a0, 8
    jal     hexasc
    nop
    sb    $v0, 1($s0)

    #colon
    li     $v0, 0x3a
    sb    $v0, 2($s0)

	#2 digit
	andi $a0, $s1, 0xF0
	srl $a0, $a0, 4
	slti $t6, $a0, 0x1
	jal hexasc
	nop
	sb $v0, 3($s0)
	
	#1 digit
	andi $a0, $s1, 0xF
	srl $a0, $a0, 0
	slti $t7, $a0, 0x1
	jal hexasc
	nop
	sb $v0, 4($s0)
	
	add $t0,$t6, $t7
	beq $t0, 2, addX
	
	#null
	li $v0, 0x00
	sb $v0, 5($s0)
	
back:	
	POP	$s1
	POP	$s0
	POP	$ra
	

jr	$ra
nop

addX:
	li $v0, 0x58
	sb $v0, 5($s0)
	li $v0, 0x00
	sb $v0, 6($s0)
	j back
	nop

enable_interrupt:
	ei 
	jr $ra