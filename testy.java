/* 
A program to collect student data for
a database and verify that data back to the user.
*/

public class testy {
    public static void main(String[] args) {
        /*
        Recieve input from the user, including first name, 
        last name, student ID, high school, last letter grade in 
        CS course, GPA 
        */
        String firstName;
        String lastName;
        String studentID;
        String highSchool;
        char lastGrade;
        int age;
        double GPA;

        /* Prompt the user for data */

        System.out.print("Welcome to the student database!\n What is your first name? ");
        Scanner scan = new Scanner(System.in);
        System.out.print(" What is your last name? ");
        lastName = scan.next(); // assigning data to firstName
        System.out.print(" What is your student ID? ");
        studentID = scan.next();
        System.out.print(" What high school did you attend? ");
        highSchool = scan.next();
        System.out.print(" What high school did you attend? ");
        highSchool = scan.next();

        /* Veryify the information with the user */
        System.out.println("Thank you! Your data is... ");
        System.out.print("First name: "+firstName+"\nLast name: "")
     }
}
