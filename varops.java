/*
This program ask for three inputted doubles from the user
then it proceeds to use the formula stated to output a result
based on the inputted values
*/
// Aaron Marshall
// 2/8/2022
import java.util.Scanner;
public class varops {
    public static void main(String[] args) {
/* These  variables below will store the three values inputted
as "a" "b" and "c."
*/
        double a;
        double b;
        double c;
/*
The scanner below stores the three values you input into each
variable stated above.
*/
        Scanner s = new Scanner (System.in);
        System.out.println(" Enter three doubles (a / b + c): ");
        a = s.nextDouble();
        b = s.nextDouble();
        c = s.nextDouble();
        s.close();
/* 
The "result" below takes the "a,b,c" variables and uses the
formula a / b + c to get an answer based on those variables 
stored values.
*/
        double result = (a / b + c);
        System.out.println(a + " / " + b + " + " + c + " = " + result);
    }
}