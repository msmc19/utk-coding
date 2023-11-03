//loops.java
/* 
This program will prompt the user if they want to find the product or sum. It
will then ask the user for a set amount of values that want to be inputted and calculated.
Once the user inputs x amount of values that want to be calculated, a summation or product will
be outputted based on the user's given inputs.
*/
// Aaron Marshall
// 4-3-2022


import java.util.Scanner;
class forloops {
   public static void main(String[] args) {
      String input;
      double n;

      Scanner s = new Scanner(System.in);

      while (true) {
      System.out.print("Sum or product (type 'quit' to quit): ");
      input = s.next();
      if (input.equals("quit")) {
         break;
      }
      else if (!input.equals("sum") && !input.equals("product")) {
         System.out.println("Invalid operation, try again.");
         continue;
      }

      /* The first IF statement starts by checking if the input is "sum." If so, a double *sum* is created being set to 0.
      An integer is created called *sumValue* which is checked until its less than n. The value n is the value inputted by the 
      user which is the amount of values needed to calculate the sum. With this you input the n amount of values that will be 
      summarized and the system take the sum variable and adds the inputted values into that variable which creates a total
      summation of the inputted values. This is then outputted into a precise 3 decimal places.*/ 



      System.out.print("How many values? ");
      n = s.nextDouble();
      if (input.equals("sum")) {
         double sum;
         sum = 0;
         int sumValue;
         for (sumValue = 0; sumValue < n; sumValue++) {
           System.out.print("Enter value # " + sumValue + ": ");
           sum = sum + s.nextDouble(); 

         }
         System.out.println("Sum = " + String.format("%.3f", sum));
      }


     /* The statement below in the else statement takes the "product" input and calculates the product of a set amount of values inputted as "n."
        The only difference in this statement is instead of the product variable being set to 0, it is 1. The reason for is to avoid inputted values
        being multiplied by 0 resulting in a product of 0.*/


      else {
           double product;
           product = 1;
           int productValue;
           for (productValue = 0; productValue < n; productValue++) {
              System.out.print("Enter value # " + productValue + ":");
              product *= s.nextDouble();

        }
        System.out.println("Product = " + String.format("%.3f", product));
      }
     }
     s.close();
   }
}