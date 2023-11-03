import javax.crypto.AEADBadTagException;

/* Blueprint File - Main is NOT here
    This will only be used if we create a Dog object in main */
/* Dog Class */
/* A class is a BLUEPRINT for an object. An object is kind of 
like type that we can make on steroids. 
- What things or data points do we want to store about a dog? (what fields should be make?)
    Age, breed, name, owner's name, weight, etc <-- these are VARIABLES but specifically member variables of the class Dog
    Member variables should be private
- What actions do we want to do with a dog object or on dat related to the dog object? (what methods should we make?)
    weight conversion, age conversion, etc
*/
public class dog {
    // we put m in front of age to remind us that it's a member variable 
    private int mAge; // All member variables should be PRIVATE. This keeps our data safe.
    // m is not required behind the variables for it ot work
    private int mWeight; // private DATA_TYPES MEMBER_VARIABLES_NAME

    private String mName;

    // the constructor - this gets called when we make a new object of type Dog
    // Bark will be printed, but Java is also assigning a spot in memory for mAge and weight.
    // Right now, nothing is stored in mAge and weight, Java will have a default value of 0 there. 
    public Dog() { 
        System.out.println("bark");
    }

    public Dog(int defaultWeight, int defaultAge, String defaultName) {
        mWeight = defaultAge;
        mAge = defaultAge;
        mName = defaultName;
    }

    // Getters and Setters 
    // Change member variables but by OUR rules or access variables by OUR rules.
    // You'll want to have a getter/setter pair for every private member variable that you'll allow for main.
    public void setWeight(int weightFromMain) {
        if (weightFromMain > 0) {
            mWeight = weightFromMain;
        }
        else {
            System.out.println("Weight must be a positive integer.");
        }
    }


    /* This might seem silly to just return weight, but this allows us to keep it
        private, and not allow users to SET weight in a weird way */
    public int getWeight() {
        return mWeight;
    }

    public void setName(String mName) {
        // Remember, the member variable to store a dog's name is called "name"
        // Here, we also have the argument for setName called "name"
        // The keyword "this" is used with naming conflicts, and we put it in front of hte member variable
        // to tell them apart
        this.name = mName;
    }

    public String getName() {
        return this.name;
    }

    // We could write this where you could call this in main , or just in Dog class.
    // If it's a public method, then you'll be able to call this in main. 
    public int convertLBStoKGS() {
        double returnVal;

        returnVal = mWeight / 2.205; // weight in kilograms silvie is 50lbs...
        return returnVal;
    }

}