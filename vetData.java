import java.util.Scanner;
class vetData {
    public static void main(String[] args) {
        /* This program will ask for data about a dog from the user, including first & last
        name of owner, pet's name, pet's weight, last time it took medication in the AM
        (on the hour), pet's age,
        Then we will do some calculations on the data.
        Then we will output confirmations to the user (use System.out.format). */
        String first, last, petName; // notice String is capitalized
        double weightLBS, weightKGS;
        int medsAM, medsPM;

        System.out.println("Welcome to the database!");
        System.out.println("Please enter your first and last name (use '_' for two words in first/last name): ");
        Scanner myInput = new Scanner(System.in);
        first = myInput.next();
        last = myInput.next();
        // System.out.println("F: " + first + " L: " + last);
        System.out.println("Please enter pet's name (Use '_' for two words in name ): ");
        petName = myInput.next();
        System.out.println("Please enter pet's weight in pounds: ");
        weightLBS = myInput.nextDouble();
        System.out.println("Please enter last AM medication (on the hour): ");
        medsAM = myInput.nextInt();

        /* Calculation section */
        // medsAM is 8, then I want to give the animal meds 10 hours later, 6pm
        // 8 + 10 = 18.... 18 % 12.... taking  18/12 and changing it to a mixed number: 1 6/12
        // the answer to 18 % 12 is the remainder of 18/12.
        // the answer to 18 / 12 with int div is 1.
        
        // The animal needs to take medication 10 hours later, but printed with PM.
        medsPM = (medsAM + 10) % 12;
        System.out.println(medsPM);

        // Pounds / 2.2046 = Result in Kilograms (kg)
        // weightLBS / 2.2046 = weightKGS; 
        weightKGS = weightLBS / 2.2046;

        /* Output */
        // Pet's anme: NAME
        // Take medication at ___ PM
        System.out.format("Owner Last Name: %10s Owner First Name: %-10s", last, first);
        System.out.format("Pet's name: %s\n", petName);
        System.out.format("Take medication at %d PM\n", medsPM);
        System.out.format("Pet's weight in KGs: %f\n", weightKGS);

        //Pet's name:          Marco
        //Pet's weight in KGS: 3.63


        }
}
