public class practiceQs {
    public static void main(String[] args) {
        // Converting ints to doubles, and doubles to ints
        // double d = 12.5;
        // int i = d;
        // System.out.println(i);
        // Error output is ... Type mismatch: cannot convert form double to int

        // How do I fix this? I tell Java - "hey, FORCE this to be an int"
        double d = 12.555555;
        int i = (int)d;
        System.out.println(i);
        // (int)d ---- this is called type casting
        // If we are type casting a double (takes up more memory) to an int,
        // that is called narrowing.
        // When we type casting the double to an int, the decimals get TRUNCATED.
        // d will stay the same. 
        System.out.println(d);

        // Trying to convert an int into a double (the other direction)
        // int takes up less space in memory compared to a double
        int x = 10;
        double y = x;
        System.out.print(y);
        // This will work WITHOUT any (double) in front 
        // And it's because we have enough room to store than int in the space of a double

        System.out.print(11/2);

        int x = 100;
        System.out.println(++val);
    }
    
}
