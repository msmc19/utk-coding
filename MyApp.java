import java.util.Scanner;
public class MyApp {
    
    public static void main(String[] args) {
        // The Scanner is an object
        // This is carving out memory for the scanner. 
        Scanner scan = new Scanner(System.in);

        // This is our class that we created in Dog.java
        // and our first object of type Dog.
        // The object is named :silvie: and I am using a constructor like I did with the Scanner.
        dog silvie = new Dog();
        dog rover = new Dog(20, 3, "Rover Smith");

        silvie.mAge = 9; // I can ONLY do this if mAge is public... "public" means anyone can access/assign the variable.
        System.out.println(silvie.mAge);
        silvie.setWeight(50);
        rover.setWeight(30);

        System.out.println("Silvie's weight is" + silvie.getWeight());
        double newWeight = silvie.convertLBStoKGS();
        System.out.println(newWeight);

        silvie.setName("Silvie Crumpton");
        System.out.println("My dog's name is " + silvie.getName());
    }
}
