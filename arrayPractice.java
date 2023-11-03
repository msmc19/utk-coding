/* These are the "on the fly" notes we did in class on 4/28 
   and what the file looked like by the end of class. */
import java.util.Scanner;
import java.util.ArrayList;
class arrayPractice {
   public static void main(String[] args) {
      int lengthOfArray;
      int[] scores; //0 to 100

      Scanner scan = new Scanner(System.in);
      System.out.print("Enter the number of scores: ");
      lengthOfArray = scan.nextInt();

      // Now that I know how long my array should be, I can allocate memory for it.
      scores = new int[lengthOfArray]; // 4 bytes * # of scores

      for (int i = 0; i < scores.length; i++) {
         System.out.println(scores[i]);
      }

      // Input scores manually in the code
      //scores[0] = 100;
      //scores[1] = 95;
      //scores[2] = 80;
      //scores[3] = 99;
      // What if the user said there were 2 scores?

      // Using a loop, start at 0 stop when the "lengthOfArray" variable is hit
      for (int i = 0; i < lengthOfArray; i++) {
         //Prompt the user for a score
         System.out.print("What is the score for student #" + (i + 1) + ": ");
         scores[i] = scan.nextInt();
      }

      for (int i = 0; i < scores.length; i++) {
         System.out.println(scores[i]);
      }

      int sizeOfAL = lengthOfArray;
      ArrayList <Integer> scores2;  // declaring an array list
      scores2 = new ArrayList<>(sizeOfAL); // space for 3 ints

      // Empty scores -> uninitialized
      //for (int i = 0; i < sizeOfAL; i++) {
      //   System.out.println(scores2.get(i)); 
      //}

      for (int i = 0; i < sizeOfAL; i++) {
         System.out.print("Enter a score for the ArrayList: ");
         int s = scan.nextInt();
         scores2.add(s);
      }

      for (int i = 0; i < sizeOfAL; i++) {
         System.out.println(scores2.get(i));
      }

      // Beyond the initial size I allocated:
      System.out.print("Enter a score for the ArrayList: ");
      int s = scan.nextInt();
      scores2.add(s);   //dynamically allocating one more spot (resizing the AL automatically by 1, and inserting the value
                        // we scanned in to the end)

      System.out.println(scores2.get(3));
      //size is 4 (if the user inputted 3 initially)

      scores2.clear();
      System.out.println("Cleared AR");

      System.out.println("Size of scores2 is: " + scores2.size());

      for (int i = 0; i < sizeOfAL; i++) {
         System.out.println(scores2.get(i)); 
      }
      



   }
}

// TP ID: 896887