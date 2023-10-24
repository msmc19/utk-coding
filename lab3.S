# Name: Aaron Marshall
# NET ID: amarsh32
# Purpose: This is an assembly program take five provided mapping functions (add,sub,min,max) that will go through and array of doubles and execute a function on each one.


.section .text
.globl map
map:
  addi sp, sp, -24    // add 8 bytes more to the stack
  sd ra, 16(sp)       // save ra on stack
  sd s0, 8(sp)        // save s0 on stack
  sd s1, 0(sp)        // save s1 on stack
  la t0, values       // load values address into t0
  ld t1, (t0)         // load values[0] into t1
  addi t2, zero, 0    // loop index
loop:
  blt t2, num_values, continue  // if index < num_values, jump to continue
  j endloop           // otherwise, jump to endloop
continue:
  ld s0, (t1)         // load value into s0
  mv s1, map_value    // move map_value into s1
  mv a0, s0           // move s0 into a0 as left operand
  mv a1, s1           // move s1 into a1 as right operand
  jal mapping_func    // call mapping_func
  sd fa0, (t1)        // store result back into values[i]
  addi t1, t1, 8      // increment the pointer
  addi t2, t2, 1      // increment the index
  j loop              // jump to loop
endloop:
  ld ra, 16(sp)       // restore ra
  ld s0, 8(sp)        // restore s0
  ld s1, 0(sp)        // restore s1
  addi sp, sp, 24     // restore stack pointer
  ret

.globl map_add
map_add:
  fadd.d fa0, fa0, fa1
  ret

.globl map_sub
map_sub:
  fsub.d fa0, fa0, fa1
  ret

.globl map_min
map_min:
  fmin.d fa0, fa0, fa1
  ret

.globl map_max
map_max:
  fmax.d fa0, fa0, fa1
  ret

