/*closing costs calc
  Ask the user for 3 houses they arer interested in,
  price, down payment %
  Output the cash the user needs in order to close on the home*/
import java.util.Scanner;

public class closingCosts {
    static void prompt1(int num){
        System.out.println("what is the price of home "+num+"? ");
    }
    static void prompt2(){
    System.out.println("how much of a downpayment (in %) would you use for this house?");
    }
    static double calculation(int price, int downPayment) {
        double cash, dPP, cCP;
        int closingCostsPercent=4;

        // doing my calculation in here instead of the main body of the program

        dPP = downPayment / 100.0;
        cCP = closingCostsPercent / 100.0;
       cash = (price * dPP )+(price * cCP);

        return cash;
    }
    public static void main(String []args){
        Scanner s = new Scanner(System.in);
        int homePrice, downPaymentPercent;
        double cashToClose;
        

        /*Prompting the user for info */
        prompt1(1);
        homePrice = s.nextInt();
        
        prompt2();
        downPaymentPercent = s.nextInt();

        /*claculate the closing costs for 1st house */
        //does this in the upper function
        cashToClose = calculation(homePrice, downPaymentPercent);
        System.out.println(cashToClose);


        /*Prompting the user for info */
        prompt1(2);
        homePrice = s.nextInt();
        
        prompt2();
        downPaymentPercent = s.nextInt();
        
        /*claculate the closing costs for 1st house */
        //does this in the upper function
        cashToClose = calculation(homePrice, downPaymentPercent);
        System.out.println(cashToClose);
        // cashToClose = (homePrice * downPaymentPercent/100) + (homePrice * closingCostsPercents)


    }
}
