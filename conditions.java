/*
This program takes the username and password input from the user and 
checks to see if the inputs fall under the necessary requirements to enter.
If they don't the user will be prompted an issue with their input.
*/
// Aaron Marshall
// 3/1/2022
import java.util.Scanner;
public class conditions {
    public static void main(String[] args) {
        String user, pass;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter username: ");
        user = s.next();

/* The input below scans the user's input for the "username" and 
checks if the user's input does NOT equal "orange" then it will output
a response saying that the username is invalid.
*/
        if (!user .equals("orange")) {
            System.out.printf("Unknown user, "+"'"+user+"'.");
            s.close();
            return;
        }

/* Assuming the user puts "orange" in as the username, the program will then
prompt the user for a password. If the user's input for the password
is equal to "white" then it will prompt "Welcome!" If the user does NOT input "white"
the program will prompt the user "Incorrect Password."
*/
        System.out.print("Enter password: ");
        pass = s.next();

        if (pass .equals("white")) {
            System.out.println("Welcome!");
        } else {
            System.out.println("Incorrect Password.");
            s.close();
            return;
        }

    }
}
