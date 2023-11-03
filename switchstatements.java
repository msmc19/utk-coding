import java.util.Scanner;
public class switchstatements {
    public static void main(String[] args) {
        String sensorInput;
        Scanner myScanner = new Scanner(System.in);

        System.out.print("Enter your sensor: ");
        sensorInput = myScanner.next();
        System.out.println(sensorInput); // simple double-check that sensorInput worked

        /* We are going to assume that they will enter HR, Speed, Cadence, Power
        spelled this way */
        switch(sensorInput) (
            case "HR":
            case "Speed":
            case "Cadence":
            case "S":
            case "C":
                System.out.println("Speed/Cadence sensor added.");
                break;
            case "Power":
            case "P":
                System.out.println("Power sensor added.");
                break;
            default:
                System.out.println("Sensor not recognized.");
                break;
        )

    }
    
}
