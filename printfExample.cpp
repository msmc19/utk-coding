 /* Printf examples */
#include <cstdio>
#include <string>
using namespace std;

int main()
{
   printf ("Characters: %c %c \n", 'a', 65);          // Chars can be stored with single quotes or their numeric value (We will learn more about numeric char values with ASCII tables)
   printf ("Whole numbers: %d %ld\n", 1977, 650000L); // An int and a long
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Left justified: %-10d %d \n", 1977, 1978);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Floats Rounded to Two Decimal Places: %4.2f \n", 3.1416);
   printf ("Dynamic Formatting: %*d \n", 5, 10);     // Same as ("Dynamic Formatting: %5d \n", 10)
   printf ("%s \n", "A string");
   printf ("%50s \n", "A string right justified");
   string s = "A C++ String to be Converted to C-style";
   printf ("%50s \n", s.c_str());

   return 0;
}