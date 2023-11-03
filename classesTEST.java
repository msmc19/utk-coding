// Dylan DelRosa
// 10/18/21
// Point of program is to create a class and print info regarding
// the ints entered such as min, max, product, sum, average and # entered

import java.util.Scanner;
class classesTEST {
   public static void main(String[] args) {
      
      // declares the variables and creates the object classes
      boolean isrunning = true;
      classes myclass = new classes();
      Scanner s = new Scanner(System.in);

      // checks to see if an int was entered
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
      
      // Prints all of the information about the ints entered
      System.out.format("Number of values entered = %d%n", myclass.getNumValues());
      System.out.format("Sum of all values        = %d%n", myclass.getSum());
      System.out.format("Product of all values    = %d%n", myclass.getProduct() /* TODO: Get the product */);
      System.out.format("Biggest value            = %d%n", myclass.getMax() /* TODO: Get the maximum value */);
      System.out.format("Smallest value           = %d%n", myclass.getMin() /* TODO: Get the minimum value */);
      System.out.format("Average of all values    = %.2f%n", myclass.getAverage() /* TODO: Get the average of all values */);
   }

   // it sets the number of integer that have been entered
   // sets the sum of the ints that have been entered
   // sets the product of the ints that have been entered
   // sets the min and max of the ints that have been entered
   public void addValue(int val) {
      mNumValues++;
      mSumOfValues = mSumOfValues + val;
      mProductOfValues *= val;
      if (mNumValues == 1) {
         mMaximumValue = val;
         mMinimumValue = val;
      }
      else {
         if (val > mMaximumValue) {
            mMaximumValue = val;
         }
         else if (val < mMaximumValue) {
            mMinimumValue = val;
         }
      }
    }

   // find and returns the average of ints entered
   public double getAverage() {
      if (mNumValues == 0) {
         return 0.00;
      }
      else {
         return (mSumOfValues * 1.0) / mNumValues;
      }
               
   }

   public classes() {
      mNumValues = 0;
      mSumOfValues = 0;
      mMaximumValue = 0;
      mMinimumValue = 0;
      mProductOfValues = 1;
   }

   // declares all the fields and intializes the product to 1
   private int mNumValues;
   private int mSumOfValues;
   private int mProductOfValues;
   private int mMaximumValue;
   private int mMinimumValue;

   // these are all the getter methods which return their respective variable
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