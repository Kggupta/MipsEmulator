add $1, $2, $2 ; i am a comment
beq $1, $2, generalkenobi
hellothere:
addi $1, $2, 7
jr $31
; comments 
generalkenobi:
pri $1 ; a made up command to print stuff to console
addi $2, $1, 3
beq $1, $2, hellothere
pri $2
bne $1, $2, hellothere
