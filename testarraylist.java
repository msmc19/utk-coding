


import java.util.Scanner;
class testarraylist {
    public static void main(String[] args) {
        int i;
        int sz;
        double iv;
        testarraylist mal = new myarraylist();
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
        mValues = new double[size];
    }

    public myarraylist(int size, double defval) { // allows each index to hold the value of defval
        this(size); 
        for(int i = 0; i < this.size(); i++ ){
            mValues[i] = defval;
        }     
    }

    public void add(double val) { // adds inputted value to the last value within the array
        mValues = new double[size() + 1];
        for (int i = 0; i < size(); i++) {
            mValues[i] = get(i); 
        }
        mValues[size() + 1] = val;
    }

    public void add(int index, double val) { // user chooses a value to add to a specific index within the array
        mValues = new double[size() + 1];
        for (int i = 0; i < size() + 1; i++){
            mValues[i] = get(i);
        }
        set(index, val);
    }

    public void clear() {                   // all the elements within the array are cleared
        for (int i = 0; i < this.size(); i++) {
            mValues[i] = 0;
        }
    }

    public int indexOf(double val) {
        for(int i = 0; i < this.size(); i++){
            if(val == mValues[i] ){
                return i;
            }
        }
        return -1;
    }

    public boolean contains(double val) { // checks if value inputted by user within the array
        for(int i = 0; i < this.size(); i++) {
            if(val == mValues[i]){
                return true;
            }
        }
        return false;
    }

    public double get(int index) { // retrieves value of index inputted by user
        return mValues[index];
    }

    public boolean isEmpty() {      // If size of the array is 0 the array is empty 
        if(this.size() == 0){
            return true;
        }
        return false;
    }

    public void remove(int index) {  // removes entire element at index which is inputted by user
        int nSize = size();
        int i_last = 0;
        double array[] = new double[size()];
       
        if (index <= nSize) {
               for(int i=0;i<array.length;i++){
                   if (i != index) {
                      array[i] = mValues[i];
                   }
                   else {
                    i_last = i;
                    i = 999;
                   }
               }

               for (int a=i_last;a<array.length-1;a++) {
                       
                        array[a] = mValues[a+1];
               }           
               mValues = new double[size()-1];
               
               for (int j=0;j<array.length-1;j++) {
                    mValues[j] = array[j];
               }
       
        }
    }

    public void remove(double val) {  // removes first element that contains the value which is inputted by the user
        mValues = new double[size() - 1];
        for( int i = 0; i < size(); i--) {
            mValues[i] = get(i);
        }
        mValues[size() - 1] = val;
    }

    public void set(int index, double val) {
        mValues[index] = val; 
    }

    public int size() {  //return length of the array the user has inpuuted
        return mValues.length;
    }

    public double[] sub(int first, int last) { // returns sub-array which the user has inpuuted
        double arr[] = new double [last - first];
        for (int i = first; i < last; i++) {
            mValues[i] = arr [i-first];
        }
       return arr;
    }
    private double[] mValues;
}