//learning to print a new way, formatted printing
//Big dif between print/println and format:
//  we dont use the plus sign to separate literal strings and variables
//  we use specific symobls to denote where the variable will go 
//  we habe to tell java what type those variables are

import java.util.Scanner;
class formattedOutput{
    public static void main(String[] args){
        String first, last;
        double gpa;
        Scanner s = new Scanner(System.in);

        System.out.println("what's ur god damn first name?");
        first = s.next();
        System.out.println("What's ur mother fucking last name?");
        last = s.next();
        System.out.println("Whats ur bloody GPA, down to four decimal places?");
        gpa = s.nextDouble();

        /* Inside(),first thing to write is the formatted string in quotes
        INCLUDING the special symbols for having variables in the string
        After the string in quotes, we list the variable we will use in that 
        string in order.
        ("formatted string here", variable1, variable2, variable3)
        f = float and we use this for doubles
        d = decimal and we use this for ints
        s = for strings
        double pi = 3.14
        name = "CC"

        ("hello my number is %f and my name is %s", pi, name)
        ("string with specifiers that start with % ")
        */
        //System.out.format("First: %s Last: %s GPA: %f%n", first, last, gpa);
        //System.out.println("First: "+ first + "last: "+ last+ "GPA: "+gpa);

        System.out.format("First: %-10s Last: %-10s GPA: %010.2f%n", first, last, gpa);
        int i = 10;
        int j = 20;
        System.out.format("i + j = %d%n", i + j);
        
        /*
        % _ ____ * _____ f the minus sign, character width, a period, and sig digs
        % _ ____ s   the first blank is where a minus sign can go, and the second is char width
        % _ ____ d   same for integers
        %-10s   left justified with 10 characters width
        %10s   
        %s 


        --------
        Line 37 has left justified of 10 characters wide and line 38 has right 
        sam     Smith     3.56
             sam    Smith    3.56
        
        */

    }
}