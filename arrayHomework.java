import java.util.ArrayList;
public class arrayHomework {
    public static void main(String[] args) {

    
        // Declaring an array
        // type[] variableName;
        // type variableName[];
        int[] cardDeck;
        int cardDeck2[];


        // Pitfalls of arrays: isnt a pitfall but it's tricky. When we allocate the space
        // for an array, we use the size. But we will never use the size in braces
        // again to access a member of the array, because its out of bounds since it's
        // zero indexed.
        cardDeck = new int[52];

        // Once you set the size of an array it's fixed! There's no turning back. 
        // No adding more. 
        cardDeck2 = new int[54];

        // One last tricky thing to remember, is that when we are using arrays
        // with Objects that we make, we have to create space for the array and the 
        // Object. That means we need to use the "new" keyword teice

        // another pitfall is this waste space when we need to make a new arrat
        // To avoid that, we can use an ArrayList

        ArrayList<Dog> myDogs;
        myDogs = new ArrayList<>(4);
        for (int i = 0; i < 4; i++) {
            myDogs.add(new Dog(30));
        }
    }
}
