/* this is a gay as pussy whipped bitch progam where i copy 
the code the teacher is writing, i have no idea what im doing */
import java.util.Scanner;
public class Notes2 {
    public static void main(String[] args){
        //first stuff is gonna collect some data from the student 
        //in the form of variables...
        Scanner s = new Scanner(System.in);

        String first;
        String last;
        String studID;
        String highSchool; //the way this var is writen out is 
        char lastGrade;    //called camelCase...
        int age;
        double gpa;

        System.out.print("wellcome to purgatory faggot \ngimme ur name boi:");
        first = s.next();
        System.out.print("alright retard, ur full name, whats ur last name:::");
        last = s.next();
        System.out.print("what was ur id again, lmao:");
        studID = s.next();
        System.out.print("ur highschool...?(enter that shit in snake_case, so spaces");
        highSchool = s.next();
        System.out.print("i shoulda asked this first, but how old are u? lol XD :)))");
        age = s.nextInt();
        System.out.print("ur last grade?");
        lastGrade = s.next().charAt(0);

        System.out.println("you look stupid "+first+" "+last+", and ur id "+studID+" is just dumb lookin");
        System.out.print("what is this shit, ur last grade was a " + lastGrade +"? jesus ur stupid, your litteraly "+age+" years old for pete sake");
    }
}
