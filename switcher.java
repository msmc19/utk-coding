/*
This program uses scanners and switch statements to allow the user
to input two double values and an arithmetic operator which will 
output a double value based on the used operator. If the arithmetic
operator is not in one of the specified cases, then it will default to 
and state the operator in invalid.
*/
// Aaron Marshall
// 2/25/2022
import java.util.Scanner;
public class switcher {
      public static void main(String[] args) {
        double left, right;
        String operator;

        Scanner s = new Scanner(System.in);

    /* The code below scans the inputs given based on the variables inputted and their preference */

        System.out.println("Enter <left> <op> <right>: ");
        left = s.nextDouble();
        operator = s.next();
        right = s.nextDouble();

        s.close();

    /* The switch statements below take the three inputted variables and calculates them to get a proper result */

        switch(operator) {
        case "*":
            System.out.format("%.1f * %.1f = %.1f\n", left,right, left * right);
            break;
        case "+":
            System.out.format("%.1f + %.1f = %.1f\n", left,right, left + right);
            break;
    
        case "-":
            System.out.format("%.1f - %.1f = %.1f\n", left,right, left - right);
            break;
        case "/":
            System.out.format("%.1f / %.1f = %.1f\n", left,right, left / right);
            break;
        default:
            System.out.println("Invalid operator!");
      }
    }
}