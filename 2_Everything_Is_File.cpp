
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/****************************************/ /*MERGE TWO FILES IN ONE FILE*/ /*******************************************************/

/*Create two  files file1 ,file2

File1 contains :
   Mumbai is financial capital of India


File2 contains :
   Also it is capital of Maharastra

*/

/*Create file3.
   Merge contents of file1 and file2 in file 3 .

*/

int main()
{
   ifstream in;
   ofstream out;

   out.open("file1.txt"); // Write data in file1
   out << "Mumbai is finicial capital of India";
   out.close();

   out.open("file2.txt"); // Write data in file2
   out << "Also it is capital of Maharastra";
   out.close();

   out.open("file3.txt"); // Write data in file3

   in.open("file1.txt"); // Read input file1

   string st; // Create a output string

   while (in >> st)
   {
      out << st << ' ';
   }
   out << endl;
   in.close();
   in.open("file2.txt"); // Read input file2

   while (in >> st)
   {
      out << st << ' ';
   }
}
