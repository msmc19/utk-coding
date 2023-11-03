/* Need this line everytime you need input from the user */
/* Brings in the ability to use the Scanner */
import java.util.Scanner;
class test {
   public static void main(String[] args) {
      // This is a single line comment and will be thrown out
      // We have created two variables to hold data and set
      // them to 10 and 20. 
      /* Then I will print out a + b and 
      see what happens. I am currently writing in a multi-line comment. 
      */
      /* We created a piece of data called 'a' and told the compiler
      that it will be only whole numbers in 'a'. 
      This is called "declaring and initializing a". */
      int a = 10;
      /* Here in line 15, I declared b.
      Separately, in line 16, I initialized b. */
      int b;
      b = 20;
      double c = 3.14;

      /* To declare a variable/make a holder for data: 
      data_type variable_name;

      To declare and initialize at the same time:
      data_type variable_name = data_value;

      For strings and characters, use " " for strings and ' ' for chars

      String myString = "Hello";
      char myChar = 'c';

      boolean taskComplete = true;
      */

      /* 
      System.out.print or System.out.println
      are two ways to print to the screen.
      The plus sign can be used to do different
      things in Java, for instance it can add numbers together
      and it can concatenate strings to print to the screen.
      The following two lines show those two differences.
      */
      System.out.println(a + " " + b);
      System.out.println(a + b);

      System.out.println("a is equal to " + a + " and c is equal to " + c);

      String name;
      /* Declaring a Scanner called scan 
      and telling it that we will be reading input
      from the user on system.in (input from the console) 
      The line below will be written everytime you need 
      to get input from the user, but you can change 'scan'
      to another name if you'd like. */
      // Prompt the user for the input
      System.out.println("What is your name?");

      Scanner scan = new Scanner(System.in);
      // read in the name in the line below
      /* To be more specific, we only read
      in the next word from the user.
      .next() will grab everything until whitespace (enter, space, tab)
      */
      name = scan.next();
      // verify that I read in the correct name
      System.out.println("Your name is: " + name);

      System.out.println("What is your age?");
      int age;
      age = scan.nextInt();
      System.out.println("Your age is: " + age);
      age = age + 10;
      System.out.println("Your age plus 10: " + age);

      // After we are done reading, close the scanner.
      scan.close();
   }
}