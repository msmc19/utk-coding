# Name: Aaron Marshall
# NET ID: amarsh32
# Purpose: This is an assembly program that provides a single functions that returns a random number between
# minimum and maximum value.


.global get_rand
get_rand:
    addi    sp, sp, -24      # allocate 24 bytes on the stack
    sd      s0, 0(sp)        # save s0 on the stack
    sd      s1, 8(sp)        # save s1 on the stack
    sd      ra, 16(sp)       # save return address on the stack
    mv      s0, a1           # move max_val to s0
    mv      s1, a0           # move min_val to s1

    addi    a0, zero, 0      # set a0 to 0
    call    rand             # call the rand function
    sub     s0, s0, s1       # find the range of the random number
    addi    s0, s0, 1        # add 1 to include max_val
    remu    a0, a0, s0       # calculate the remainder
    add     a0, a0, s1       # add min_val to the remainder

    ld      s0, 0(sp)        # restore s0 from the stack
    ld      s1, 8(sp)        # restore s1 from the stack
    ld      ra, 16(sp)       # restore return address from the stack
    addi    sp, sp, 24       # deallocate 24 bytes from the stack
    ret                      # return the result

