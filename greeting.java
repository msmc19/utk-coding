//greeting.java
/* This program takes the inputted first and last names as stored strings then outputs
the first and last name in a greeting statement. */
// Aaron Marshall
// 2-1-2021
import java.util.Scanner;
class greeting {
   public static void main(String[] args) {
       // Both variables below "first" and "last" are recognized as inputted strings or words
      String first;
      String last;
      // This process below allows to take the input from the user and store it to any specific variable stated
      Scanner scan = new Scanner(System.in);
      System.out.println("What is your first name? ");
      first = scan.next();
      // With the statement that is outputted, the scanner takes
      // the inputted string that you state and stores it in the string variable as "first"
      System.out.println("What is your last name? ");
      last = scan.next();
      // Similarly to the first variable, this statement and scanner does the same
      // process, except it takes your second input and stores your string in the "last" variable
      System.out.println("Hi " + first + "! I hope the " + last + " family is well! ");
      scan.close();
      /* Lastly the printed statement above takes both the stored strings in "first"
      and "last" then uses a greeting statement that prints with your two variables */
      // The scan.close stops anymore typed inputs
   }
}