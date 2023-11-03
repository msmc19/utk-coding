/* Exam 2 */

/* 
- Will cover old material from midterm 1 (20% ish)
Review that old exam.
Questions will be similar to the ones on that exam, but changed numbers
x * y / a + b - c % d 
(Integer division and modulus review**)
- mod, integer division, type casting (into to a double, double to an int)

Ex. 
3 % 6 = 3 (Numerator of fraction)
5 % 2 = 1 (Remainder of the modulus)

- formatted output (%f, double, %d, integer)
- switch/if/else
- compound conditions in our if statements

Ex.
// Code snippet on exam scores, exam is an int
if (exam > 0 && exam < 100) {

}

- left/right justification for formatted output (minus sign) and rounding

Ex. 
System.out.format("My exam score is %-8.2f and I passed.", examFloat); 99.11111 or 80.2345
My exam score is    99.11 and I passed

- New material for loops, while loops, do-while loops, classes
 - Do-while / while loops
   Big difference: do-while has ot execute once (1 iteration), and then we check if a condition is true
   to start looping. while loop, check condition first (if it's not true on the first check, we
   may not execute at all!)
- For loops
   We know the starting and end point of the loop.
   A little bit more structured, more parts.
- Both types, know the parts (body of the loop, conditional statements, etc)
   initializer
   condition <-- while loop
   step <-- for
   body <-- for, while loop

Ex. x and y, fill in the numbers to make more questions to test yourself
int i = x;
int j = 0;
do {
   j += 1;
} while (i < 0);
System.out.print(i); <-- change whether you print i or j

Ex.
int i;
for (i = x; i < y; i++) { <-- change x and y 
   // nothing here
}
System.out.print(i);

- Classes

Focus on the vocabulary
*What does a member variable mean? = a variable that is part of a class (typically needs to be private)
*The "new" keyboard? = (allocate memory for an object, use it with the constructor)
etc.

Methods/functions:
*Write the function name/return type/arguments (ie. the first line of a function definition)
given the following information:
- returns a String
- is accessible outside of the class 
- takes two parameters: a String and an int called x and y respectively
- has the name getString

public String getString(String x, int y) { <-- can leave off the {
public String getString(int y, String x) {
   // stuff in here
   return "a";
}

another:
- returns nothing
- is accessible to methods inside the class only
- takes two parameters: a String and a double (a and b)
- has the name buildString

private void buildString(String a, double b)

generalize:
accessor info SPACE return type SPACE function name OPEN PARENTHESIS  parameter type 1 .... CLOSE PAREN

class Test {
   int score;
   Test () {
      System.out.print("hello");
   }
   Test(int i) {
      score = i;
   }
   Test(int i, j ) {
      score = i - j;
   }
}

public ___ setSCore(int i) {

}
public ___ averageScore(){

}



*/