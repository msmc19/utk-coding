/*
This program is able to take a users input including 12 - 16 values for the matrix
and 3 - 4 values for the vector creating a 3x3 / 4x4 matrix and vector then multiplying them
together outputting a 3x1 / 4x1 vector result. 
*/
// Aaron Marshall
// 5/3/2022


import java.util.Scanner;
class arrays {
    private final static int VECTOR_SIZE = 3;
    private final static int MATRIX_SIZE = VECTOR_SIZE * VECTOR_SIZE;
    public static void main(String[] args) {

     /*
     The two variables below are array of doubles that will store the two
     inputs values as doubles into arrays for both the matrix and vector.
     */
         double matrix[];
         matrix = new double [MATRIX_SIZE];

         double vector[];
         vector = new double [VECTOR_SIZE];

     /*
     The scanner below initializes the users input and starts by taking the
     values for the matrix size. The for loop checks for the user's input and then
     stores the values given into the matrix array. This process is also done for the 
     vector size array.
     */

        Scanner s = new Scanner(System.in);
        System.out.format("Enter %d matrix values: ", MATRIX_SIZE);



        for (int i = 0; i < matrix.length; i++){
         matrix[i] = s.nextDouble();
       }

        System.out.format("Enter %d vector values: ", VECTOR_SIZE);  

        for (int i = 0; i < vector.length; i++){
         vector[i] = s.nextInt();
       }

        s.close();

     /* 
     Once finished scanning, the function below will multiply the matrix and vector arrays
     after calling from the two private function that format and correctly multiply the matrix
     and vector arrays producing a correct vector result. 
     */

        double result[];
        result = multiply(matrix, vector);

        System.out.print("Result = [");
        printVector(result);
        System.out.println("]");
    }

    /* 
    The private function below will properly print the resultant vector
    from the user's input by creating correct spacing and the respective decimal
    places with " %.3f "
    */

    private static void printVector(double[] arr) {
         for(int i = 0; i < VECTOR_SIZE; i++) {
               System.out.format(" %.3f ", arr[i]);
         }
    }

    /* 
    The private function below is the main function that calculates the output 
    vector after multiplying the given input for the matrix and vector values. An
    embedded for loop system is necessary to properly run the resultant calculation.
    In addition, with the (VECTOR_SIZE * i) + j allows for the function to avoid an
    iteration variable to be created allowing for the function to bypass and calculate
    the resultant of matrix * vector. 
    */


    private static double[] multiply(double[] matrix, double[] vector) {
         double result[] = new double [VECTOR_SIZE];
         for (int i = 0; i < VECTOR_SIZE; i++) {
            for (int j = 0; j < VECTOR_SIZE; j++) {
               result[i] += (matrix[(VECTOR_SIZE * i) + j] * vector[j]);
            }
         }
         return result;
    }
}