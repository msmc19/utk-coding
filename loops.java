//loops.java
/* 
This program takes a users input as the the x value for e^x. 
It will calculate what e^x value that is inputted by the user. If the 
user inputs a non-double value, there is an prompt to try again. If 
you input "quit" the program is stopped. 
*/
// Aaron Marshall
// 3-27-2022

import java.util.Scanner;
import java.lang.Math;

/* 
The second import above allows us to execute the 
Math.exp() command and properly take an inputted double and raise
it to the e^x 
*/

class loops {
public static void main(String[] args) {
      double exponent;

      Scanner scan = new Scanner(System.in);

/* 
The while loop below helps to keep the program
constantly looping to restart the program after an input and
allow the user to keep using it without manually restarting 
*/      

     while(true) {

      System.out.print("Enter exponent: ");

/* 
The if statement's below start by scanning for a double input
value in which if found, that number is used as x for e^x and then
calculated with a result outputted.

The second two if statement's not only check for a string value
but also checks if it's a string and equals "quit." If both
these parameters are correct, the program is stopped, otherwise
there is an error prompt stated and the program is restarted. 
*/      
      
        if (scan.hasNextDouble()) {
            exponent = scan.nextDouble();
            var result = Math.exp(exponent);
            System.out.println("Result = " + result);
        } else {
          if (scan.hasNext()) {
            if (scan.next().equals("quit")) {
              break;
            }
            else {
              System.out.println("Invalid input.");
            }
          }
        }
     }
  scan.close();
  }
}  

