/*
This program that uses classes to calculate inputted integers and print information
regarding minimum, maximum, product, sum, and average.
*/
// Aaron Marshall
// 4/18/2022

import java.util.Scanner;
class classes {

   /* 
   The two sections below are intended to declare the fields of intended use and
   set each field to their respective value (including product set to 1)
   */

   private int mNumValues;
   private int mSumOfValues;
   private int mProductOfValues;
   private int mMaximumValue;
   private int mMinimumValue;

   public classes() {
      mNumValues = 0;
      mSumOfValues = 0;
      mProductOfValues = 1;
      mMaximumValue = 0;
      mMinimumValue = 0;
   }
   public static void main(String[] args) {

      /* 
      These variables below are initialized to keep the program running including
      the classes.
      */

      boolean isrunning = true;
      classes myclass = new classes();
      Scanner s = new Scanner(System.in);

      /* 
      This do/while loop checks to see if the user inputted an integer.
      */

      do {
         do {
            System.out.print("Enter an integer (\"quit\" to quit): ");
            if (!s.hasNextInt()) {
               if (s.next().equals("quit")) {
                  isrunning = false;
                  break;
               }
               System.out.println("You did not enter an integer, try again.");
            }
            else {
               myclass.addValue(s.nextInt());
               break;
            }
         } while (true);
      } while (isrunning);
      s.close();
      
      /* 
      Reguarding the integers/string inputted, the respective values of each field in
      the class will be printed
      */

      System.out.format("Number of values entered = %d%n", myclass.getNumValues());
      System.out.format("Sum of all values        = %d%n", myclass.getSum());
      System.out.format("Product of all values    = %d%n", myclass.getProduct());
      System.out.format("Biggest value            = %d%n", myclass.getMax());
      System.out.format("Smallest value           = %d%n", myclass.getMin());
      System.out.format("Average of all values    = %.2f%n", myclass.getAverage());
   }

   /* 
   The function below is intended as the "calculating" portion by using a list of operators
   and if/else statements to use the inputted integers and calculate the right output for each
   field.
   */

   public void addValue(int val) {
      mNumValues++;
      mSumOfValues += val;
      mProductOfValues *= val;

      if (mNumValues == 1) {
         mMaximumValue = val;
         mMinimumValue = val;
      } else {
         if (mMaximumValue < val) {
            mMaximumValue = val;
         } else {
            if (mMinimumValue > val) {
               mMinimumValue = val;
            }
         }
      }
   }

   /* 
   This function takes the average of the integers inputted
   */

   public double getAverage() {
      if (mNumValues == 0) {
         return 0.00;
      } else {
         return (mSumOfValues * 1.0 / mNumValues);
      }
   }

   /* 
   These methods below are used to take the values from the desired calculation functions
   and return the respective values in the indicated fields provided above
   */

   public int getSum() {
      return mSumOfValues;
   }

   public int getNumValues() {
      return mNumValues;
   }

   public int getProduct() {
      return mProductOfValues;
   }

   public int getMin() {
      return mMinimumValue;
   }

   public int getMax() {
      return mMaximumValue;
   }
}