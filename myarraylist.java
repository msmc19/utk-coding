/*
This program is intended to be a "user interface" prompting the user
a number of commands to use to not only create a an arraylist, but
modify, add, remove, etc. based on the user's input.
*/
// Aaron Marshall
// 5/10/2022

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

    /*
    This constructors is intended to create a new instance of 
    myarraylist
    */

    public myarraylist(int size) {
        mValues = new double[size];

    }

    /*
    This constructor is intended to take two parameters then input
    that into the array
    */

    public myarraylist(int size, double defval) {  
        this(size);
        
        for (int i = 0; i < this.size(); i++) {
            mValues[i] = defval;
        }
    }

    /* 
    Based on the input, it will add the passed value to the 
    end of the array
    */

    public void add(double val) {
        mValues = new double[size() + 1];

        for (int i = 0; i < size(); i++) {
            mValues[i] = get(i);

        }
        mValues[size() + 1] = val;

    }

    /* 
    This will add the passed value to the index which will this
    cause everything else to gain one to its index
    */

    public void add(int index, double val) {

        if (index >= size()) {
            add(val);

        } else {
            double[] mNewValues = new double[size() + 1];

            for (int i = 0; i < this.size(); i++) {
                mNewValues[i] = mValues[i];

            }
            mNewValues[index] = val;
            
            for (int i = index; i < size(); i++) {
                mNewValues[i + 1] = mValues[i];

            }
        }

    }

    /* 
    This will check the array and then set it to zero making
    it "empty"
    */

    public void clear() {
        
        for (int i = 0; i < this.size(); i++) {
                mValues[i] = 0;

        }
    }
       
    /* 
    This for loop will check if the array of mValues is equal
    to val. IF it is, then it will return the location of i, else
    it will return negative one
    */

    public int indexOf(double val) {
            
        for (int i = 0; i < this.size(); i++) {
            if (mValues[i] == val) {
                return i;

            }
        }
        return -1;
                    
    }

    /* 
    We can simply check if the indexOf(val) is returned as a positive number. If it is,
    then it will return true, else it will return false
    */
            
    public boolean contains(double val) {
            
        for (int i = 0; i < this.size(); i++) {
            if (indexOf(val) >= 0) {
                return true;

            }
        }
        return false;

    }
            
    /* 
    This will return the mValues at the passed index
    */

    public double get(int index) {
        return mValues[index];
            
    }
       
    /* 
    This will check if there are any elements in the array. If there is, then 
    it will return true, else it'll return false.
    */

    public boolean isEmpty() {
            
        if (this.size() == 0) {
            return true;

        }
        return false;

    }   

    /* 
    This will remove the correct elements at the passed index
    */
            
    public void remove(int index) {
        mValues = new double[size() - 1];
        
        for (int i = 0; i < size() - 1; i++) {
            mValues[i] = get(i);
        }
    }
        
    /* 
    This will check if the first element contains the passed value. If it is
    in the array, then it is removed, else it'll do nothing.
    */

    public void remove(double val) {
            
        for (int i = 0; i < size(); i++) {
            if (mValues[i] == val) {
                remove(i);
                break;
            }
        }
    }
        
    /* 
    This will overwrite the previous value at such index with a new
    passed value and index
    */

    public void set(int index, double val) {
        mValues[index] = val;

    }
           
    /* 
    The size of the array will be returned
    */

    public int size() {
        return mValues.length;

    }
     
    /* 
    A variable is created that hold the difference of the first
    and last. This will act a the new length of the returned array.
    The value, x, is created and used to iterate and set the new array
    in the for loop
    */

    public double[] sub(int first, int last) {
        int lengthValue = last - first;
        int x = 0;
        double subArr[] = new double[lengthValue];

        for (int i = first; i < last; i++) {
            subArr[x] = mValues[i];
            x++;

        }
        return subArr;

    }

    private double[] mValues;
}

    