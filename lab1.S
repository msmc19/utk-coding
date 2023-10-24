# Name: Aaron Marshall
# NET ID: amarsh32
# Purpose: This is a RISC-V assembly language program for the sum_prod function

.global sum_prod

sum_prod:
    # prologue
    addi sp, sp, -16
    sd ra, 0(sp)
    sd s0, 8(sp)

    # initialize variables
    li s0, 1
    li s1, 0
    li t0, 0

loop:
    # exit condition
    bge t0, a1, end

loop_body:
    # product *= values[i]
    slli t1, t0, 2 # multiply index by 4 to get byte offset
    add t1, t1, a0 # get memory address of values[i]
    lw t2, 0(t1) # load values[i] into t2
    mul s0, s0, t2 # multiply product by values[i]

    # sum += values[i]
    add s1, s1, t2 # add values[i] to sum

    # increment index
    addi t0, t0, 1
    j loop

end:
    # epilogue
    sw s0, 0(a2) # store product in memory location pointed to by a2
    mv a0, s1 # return sum
    mv a1, a2 # return product
    ld ra, 0(sp)
    ld s0, 8(sp)
    addi sp, sp, 16
    ret

