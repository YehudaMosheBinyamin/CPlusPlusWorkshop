#include<iostream>
using namespace std;
#include "String.h"
//Yehuda Moshe Binyamin
/**
 * @brief Driver function that receives two strings from user input, and from what index should the first string be inserted into the second string.
 * The program will output if the first string is larger/smaller/equal lexicographically to the second string, and the new combined string.
 * @param  
 * @return 
*/
int main(void)
{
    char firstWord[MAX_WORD_LENGTH];
    char secondWord[MAX_WORD_LENGTH];
    int index;
    cout << "Enter two words, one after the other on separate lines, and an index from which the first word will be inserted into the second word from there onwards" << endl;
    cin.getline(firstWord, MAX_WORD_LENGTH-1);//minus one, because getline adds null byte at the end of string.
    cin.getline(secondWord, MAX_WORD_LENGTH-1);
    cin >> index;
    String firstString = String(firstWord);
    String secondString = String(secondWord);
    bool bigger = firstString > secondString;
    if (bigger==true) 
    {
        cout << "a>b" << endl;
    }
    else 
    {
        bool equal = firstString == secondString;
        if (equal == true) 
        {
            cout << "a=b" << endl;
        }
        else 
        {
            cout << "a<b" << endl;
        }
    }
    String combinedString=secondString.insert(index, firstString.getString());
    cout << combinedString << endl;
    return 0;
}
/**Enter two words, one after the other on separate lines, and an index from which the first word will be inserted into the second word from there onwards
Hello
World
8
a < b
ERROR

Enter two words, one after the other on separate lines, and an index from which the first word will be inserted into the second word from there onwards
Hello
World
0
a < b
HelloWorld
Enter two words, one after the other on separate lines, and an index from which the first word will be inserted into the second word from there onwards
World
Hello
5
a>b
HelloWorld
    
Enter two words, one after the other on separate lines, and an index from which the first word will be inserted into the second word from there onwards
Hello
World
2
a<b
WoHellorld
    
Enter two words, one after the other on separate lines, and an index from which the first word will be inserted into the second word from there onwards
Hello
Hello
2
a=b
HeHellollo
**/