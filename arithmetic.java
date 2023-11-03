public class arithmetic {
    public static void main (String[] ars){
        System.out.println(3+6);
        System.out.println(3+6-2*4+5); //evaluates using the PEMDAS method
        
        //Divison is different in java, specifically w INTEGERS

        //since both 9 and 6 are ints, java will use an int as the output as well. i.e whole numbers
        System.out.println(9/6);
        
        //using duoubles changes the value of the output to a double
        System.out.println(9.0/6.0);
        
        //even if just one of the values is a double, the output will be a double too
        System.out.println(9.0/6);


        // % == Mod or Modulo
        //Shits IMPORTANT, gives u the remainder of a divison
        // 1(3/6) is the reuslt of 9/6
        //the remainder is 3, so when we do 9 % 6 we will get 3 as an answer
        System.out.println(9 % 6);

        //just some examples:
        System.out.println(8 % 4);
        System.out.println(1 % 4);
        System.out.println(2 % 4);
        System.out.println(3 % 4);
        System.out.println(5 % 4);

        //prefix and postfix increment (and decrement) operators:
        //These are unary operators which means this operates on a single variable
        System.out.println("Prefix and Postfix increment/decrement ops");
        int i = 10;
        int j = 20;
        System.out.println("i = "+ i + " and j = "+j);

        i++; // equates to i = i + 1 and is the postfix
        ++j; //equates to j = j + 1 BUT the assignemt and the increment happen in a different way

        System.out.println("i = "+ i + " and j = "+j);

        int k = 10;
        int l = 20;

        k = l++;
        System.out.println(k);
        k = ++j;
        System.out.println(k);

        //ASSIGNMENT and INCREMENT are super different
        // for the Assignmnet, we need a value to put in k
        // assignment is the k =
        // increment is the k + 1
        
        // the placement of the ++ is important because if u do it before it'll increment before, 
        // and if you do it after itll assign the value to k first, THEN increment the +1

        //summary: on POSTFIX, we do ASSIGNMENT first, then INCREMENT (i = j++)
        //       : on PREFIX, we do INCREMENT first, then ASSIGNMENT (i = ++j)
    }
    
}
