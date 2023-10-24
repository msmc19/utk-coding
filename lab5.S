# Name: Aaron Marshall
# NET ID: amarsh32
# Purpose: A simple text-based game that allows the user to navigate through rooms and view their descriptions.

# References(s): The "look_at_all_rooms" functions was taken from TA office hours.
# Reference(s): riscv-spec.pdf; pg.24, pg.46

# Define constant strings for output
.section .rodata
exits_str: .string "Exits: "
newline_str: .string "\n"
n_str: .string "n "
e_str: .string "e "
s_str: .string "s "
w_str: .string "w "

# Start of the program
.section .text
# Function to display information about a single room
.global look_at_room
look_at_room:
    # Save registers and create stack frame
    addi sp, sp, -32
    sd ra, 24(sp)
    sd s0, 16(sp)
    addi s0, sp, 32

    # Print room title
    lw a1, 0(a0) # r->title
    call printf

    # Print room description
    lw a1, 8(a0) # r->description
    call printf

    # Print exit directions
    la a1, exits_str
    call printf

    # Print north exit if it exists
    lw a1, 16(a0) # r->exits[0]
    li t1, -1
    beq a1, t1, check_east
    la a1, n_str
    call printf

check_east:
    # Print east exit if it exists
    lw a1, 20(a0) # r->exits[1]
    beq a1, t1, check_south
    la a1, e_str
    call printf

check_south:
    # Print south exit if it exists
    lw a1, 24(a0) # r->exits[2]
    beq a1, t1, check_west
    la a1, s_str
    call printf

check_west:
    # Print west exit if it exists
    lw a1, 28(a0) # r->exits[3]
    beq a1, t1, end_look_at_room
    la a1, w_str
    call printf

end_look_at_room:
    # Restore registers and return
    ld ra, 24(sp)
    ld s0, 16(sp)
    addi sp, sp, 32
    ret

# Function to display information about all rooms
.global look_at_all_rooms
look_at_all_rooms:
    # Save registers and create stack frame
    addi sp, sp, -32
    sd ra, 24(sp)
    sd s0, 16(sp)
    addi s0, sp, 32

    # Save 'rooms' and 'num_rooms'
    mv s0, a0
    mv s1, a1

    # Initialize loop counter 'i' to 0
    li s2, 0

loop_body:
    # Break out of the loop if i == num_rooms
    beq s1, s2, end_look_at_all_rooms

    # Calculate offset for current room
    li t0, 32
    mul t1, t0, s2

    # Calculate address of current room
    add a0, s0, t1

    # Call look_at_room for the current room
    call look_at_room

    # Print a newline character
    li a0, 10
    call putchar

    # Increment loop counter 'i'
    addi s2, s2, 1
    j loop_body

end_look_at_all_rooms:
    # Restore registers and return
    ld ra, 24(sp)
    ld s0, 16(sp)
    addi sp, sp, 32
    ret

# Function to move between rooms
.global move_to
move_to:
    # Save registers and create stack frame
    addi sp, sp, -32
    sd ra, 24(sp)
    sd s0, 16(sp)
    addi s0, sp, 32

    # Calculate address of the desired exit
    slli t1, a2, 3 # t1 = a2 * 8 (size of int)
    add a5, a1, t1 # a5 = a1 + t1 (current->exits[direction])
    lw a5, 0(a5)   # a5 = *a5 (value at the address)
    li t1, -1
    beq a5, t1, move_null

    # Calculate address of the destination room
    slli t1, a5, 5  # t1 = a5 * 32 (size of Room)
    add a0, a0, t1  # a0 = a0 + t1 (rooms + current->exits[direction])
    j move_end

move_null:
    # If no exit, return nullptr
    li a0, 0 # a0 = nullptr

move_end:
    # Restore registers and return
    ld ra, 24(sp)
    ld s0, 16(sp)
    addi sp, sp, 32
    ret

