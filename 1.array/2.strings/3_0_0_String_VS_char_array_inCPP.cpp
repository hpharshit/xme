#include <iostream>
#include <string.h>  //for char array
#include <string>    //for for string class data type
#include <algorithm> //for sort function
using namespace std;

int main()
{
     //string data type n C++
     /* string in C++ is class
    // can use char aaray as string in c++ a well but char array not flexible    
    // so it is suggested to use string class for more ease */
     cout << endl
          << "String is a class of C++" << endl;
     // initialized same as constructor of class
     // 1.
     string s = "Assigning string class object"; //string is inbuilt class  //s is object of string class
                                                 /* or can initialize string as
     2.
     string s = string("Assigning string class object"); 
     or
     3. 
     string s("abcdefgh ijklmno pqrst uvwx yz");   //like constructor
     or
     4.
     string s ;
     s= "abcdefgh ijklmno pqrst uvwx yz";

     5.   char st[10]="harshit";
          string s=st;   //constructor argument is st here
          // or string s(st);   //constructor argument is st here
          // or string s=string(st);   //constructor argument is st here
          
     
     */
                                                 //finding in string
     cout << "Starting index of word 'class' is : " << s.find("class") << endl;

     //accesing string
     cout << "s[4]: " << s.at(4) << endl; //can use s[4]; to access
     cout << "Printing complete strong s: " << s << endl;

     //size of string
     cout << "Size of string s here: " << s.size() << endl; //size function in string class
     cout << "Size of string s here: " << s.length();

     //concatetion
     cout << endl
          << "Concatenation of s:   " << s + " adding"; //concatenate
     //no need to define size in string
     //but in char array for this a larger size array needed
     // to be defined that can fit it

     //append
     s += " ok"; //append i.e adding         $$$$ or
     cout << endl
          << "Appended of s:   " << s << endl;

     //getline            multiple words input
     cout << "Input s : ";
     getline(cin, s); //string is flexible can give different argument
     cout << "Printing New inputed string s: " << s << endl;

     //multiple letters
     string s1(10, 'p'); //prints p 10 times
     cout << "10 times p : " << s1;
     // cout<<s1.find("jpp");

     s.append(s1); // s+s1    //$$$$
     cout << endl
          << "s appended with s1 :" << s;

     //erase
     s.erase(3, 4);
     cout << endl
          << "Erasing 4 characters from index 3 : ";
     cout << s << endl;
     // or   cout<<s.erase(3,4);

     //substring
     cout << "Sustring: " << s.substr(2, 4);

     //freeing or clearing string
     s.clear();
     cout << endl
          << "cleared string stores :" << s << endl;

     //numeric string to int
     string s2 = "786";
     int x = stoi(s2);
     cout << "Numeric string is changed to int data type using stoi function : "
          << x + 2 << endl;

     //int data type to numeric string
     int q = 986;
     cout << to_string(q) << endl;

     //sorting function
     string s3 = "mnbvcxlkjhgf";
     cout << "s3: " << s3 << endl;
     sort(s3.begin(), s3.end());
     cout << "Sorted in ascending order : " << s3 << endl;
     sort(s3.begin(), s3.end(), greater<char>());
     cout << "Sorted in descending order : " << s3 << endl;

     // ************************************************************************************
     // ************************************************************************************
     //char array in C++
     cout << endl
          << "Char Array";
     char arr[] = "Assigning char array which is string in C language and not in C++";
     //char arr[50] = "abcdf gh"; can assign like this also //size of array is 66
     // arr[]="poiuytrewsxcvb";  can't assign new value to assigned array
     cout << endl
          << "arr[4]: " << arr[4]; //accessing char array
     cout << endl
          << "char array string: " << arr;
     cout << endl
          << "size of char aaray string: " << sizeof(arr) << endl; //
     cin >> arr;
     cout << "cin can't take multiple words: " << arr << endl;
     cout << endl
          << "size of char aaray string: " << sizeof(arr) << endl; 

     gets(arr);
     cout << "use gets() function of string.h to get multiple words : "<<arr << endl;

     return 0;
}
