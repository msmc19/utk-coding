/* Dylan DelRosa
   11/15/21
   Crumpton
   ArrayList program */
import java.util.Scanner;
class myarraylist {
    public static void main(String[] args) {
        int i;
        int sz;
        double iv;
        myarraylist mal = new myarraylist();
        Scanner s = new Scanner(System.in);
        boolean running = true;

        do {
            System.out.print("Enter command: ");
            switch (s.next()) {
                case "new":
                    if (s.hasNextInt()) {
                        sz = s.nextInt();
                        if (s.hasNextDouble()) {
                            iv = s.nextDouble();
                            mal = new myarraylist(sz, iv);
                        }
                        else {
                            mal = new myarraylist(sz);
                        }
                    }
                    else {
                        mal = new myarraylist();
                    }
                break;
                case "get":
                    i = s.nextInt();
                    if (i < 0 || i >= mal.size()) {
                        System.out.println("Index " + i + " does not exist.");
                    }
                    else {
                        System.out.println(mal.get(i));
                    }
                break;
                case "index":
                    iv = s.nextDouble();
                    System.out.println(mal.indexOf(iv));
                break;
                case "set":
                    i = s.nextInt();
                    iv = s.nextDouble();
                    if (i < 0 || i >= mal.size()) {
                        System.out.println("Index " + i + " does not exist.");
                    }
                    else {
                        mal.set(i, iv);
                    }
                break;
                case "rem":
                    if (s.hasNextInt()) {
                        i = s.nextInt();
                        if (i < 0 || i >= mal.size()) {
                            System.out.println("Index " + i + " does not exist.");
                        }
                        else {
                            mal.remove(i);
                        }
                    }
                    else {
                        iv = s.nextDouble();
                        mal.remove(iv);
                    }
                break;
                case "size":
                    System.out.println(mal.size());
                break;
                case "add":
                    if (s.hasNextInt()) {
                        mal.add(s.nextInt(), s.nextDouble());
                    }
                    else {                    
                        mal.add(s.nextDouble());
                    }
                break;
                case "clear":
                    mal.clear();
                break;
                case "contains":
                    System.out.println(mal.contains(s.nextDouble()));
                break;
                case "sub":
                    i = s.nextInt();
                    double[] v = mal.sub(i, s.nextInt());
                    for (i = 0;i < v.length;i++) {
                        System.out.println(v[i]);
                    }
                break;
                case "list":
                    if (mal.isEmpty()) {
                        System.out.println("ArrayList is empty.");
                    }
                    for (i = 0;i < mal.size();i++) {
                        System.out.format(" [%2d] = %.4f%n", i, mal.get(i));
                    }
                break;
                case "quit":
                    running = false;
                break;
                default:
                    System.out.println("Invalid command!");
                    s.nextLine();
                case "h":
                case "?":
                case "help":
                    System.out.println("Help:");
                    System.out.println(" add <val>       - Add the value <val>.");
                    System.out.println(" add <idx> <val> - Add the value <val> at index <idx>.");
                    System.out.println(" clear           - Clears all elements of the list.");
                    System.out.println(" contains <val>  - Checks if the list contains <val>.");
                    System.out.println(" get <idx>       - Get the value of the element at index <idx>.");
                    System.out.println(" index <val>     - Get the index of the first element that has value <val>.");
                    System.out.println(" list            - Lists all elements in the list.");
                    System.out.println(" rem <val>       - Remove the first element that contains <val>.");
                    System.out.println(" rem <idx>       - Remove the element at index <idx>.");
                    System.out.println(" set <idx> <val> - Set the value at index <idx> to <val>.");
                    System.out.println(" size            - Get the number of elements in the list.");
                    System.out.println(" sub <f> <t>     - Get a sub-array from [<f>, <t>).");
                    System.out.println(" quit            - Quit the program.");
                break;
            }
        } while (running);
        s.close();
    }
    public myarraylist() {
        this(0); // Call the constructor with a size of 0
    }

    public myarraylist(int size) {
        /* Constructor helps create a new instance of myarraylist*/
        mValues = new double[size];
    }

    public myarraylist(int size, double defval) {  
       /* Constructor that takes 2 parameters and fill in the array */   
        this(size);  
        for (int i = 0; i < this.size(); i++) {
            mValues[i] = defval;
        }
    }

    public void add(double val) {
       /* adds the value passed to the end of the array */
        mValues = new double[size() + 1];
        for (int i = 0; i < size() + 1; i++) {
            mValues[i] = get(i);
        }
        mValues[size() + 1] = val;
        
    }

    public void add(int index, double val) {
       /* Adds the value passed to the index passed evrything after
       gains 1 on its index */
        if (index >= size()) {
            add(val);
        }
        else {
            mValues = new double[size() + 1];
            for (int i = 0; i < size(); i++) {
                mValues[i] = get(i);
            }
            set(index, val);
        }
    }

    public void clear() {
        /* Creates the array with a length of zero making it
        essentialy empty */
        mValues = new double[0];
    }

    public int indexOf(double val) {
        /* made a for loop to go through each value in the array
        and see if it matches val. If it does return that location i
        if none match return -1 */
        
        for (int i = 0; i < size(); i++) {
            if (mValues[i] == val) {
                return i;
            }
        }
        return -1;
    }

    public boolean contains(double val) {
        /* By calling the indexOf method all I needed to do was check if 
        it returned a positive number and if so this method will return true
        if not method returns false */
        for (int i = 0; i < size(); i++) {
            if (indexOf(val) >= 0) {
                return true;
            }

        }
        return false;
    }

    public double get(int index) {
        /* simply returns the value at the passed index */
        return mValues[index];
    }

    public boolean isEmpty() {
        /* checks to see if there are any elements in the array
        if so returns false
        if not returns true*/
        if (this.size() == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    public void remove(int index) {
       /* removes the element at the value passed */
        
       mValues = new double[size() - 1];
        for (int i = 0; i < size() - 1; i++) {
            mValues[i] = get(i);
        }
    }

    public void remove(double val) {
       /* removes the first element that contains the value
       passed if the value passed is not in the array nothing happens*/
        
        for (int i = 0; i < size(); i++) {
            if (mValues[i] == val) {
                remove(i);
                break;
            }
        }
    }

    public void set(int index, double val) {
        /* Takes a passed index and value and overwrites the previous 
        value at that index with the passed value */
        mValues[index] = val;
    }

    public int size() {
        /* simply returns the size of the array */
        return mValues.length;
    }

    public double[] sub(int first, int last) {
       /* Started by creating a variable that is the difference of 
       last - first which acts as the new length of the returned array
       created a variable f which iterators and sets the new array
       equal at the location in the for loop */
       int len = last - first; 
       int f = first;
       double subArr[] = new double[len]; 
       for (int i = 0; i < len; i++) {
           subArr[i] = get(f);
           f++;
       }
       return subArr;
    }
    private double[] mValues;
}
