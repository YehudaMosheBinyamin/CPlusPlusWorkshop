#include <iostream>
using namespace std;
#include<string>
/**
 * Yehuda Moshe Binyamin
 * Thanks to Matanya Goharian for his help on this exercise.
 * @brief Takes a sentence from user, replaces each space with a star, replaces last word with "#!!@1234", and iteratively deletes each word.
 * @param  
 * @return 
*/
int main(void)
{
    int numWords = 4;
    int spaceNumber=0;//For indexing space locations in spacesArray
    char space = ' ';
    int lastSpaceIndex = 2;
    int spacesArray[3];
    string str;
    cout << "Enter a string" << endl;
    getline(cin,str);
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i]==space)
        {
            str.replace(i,1,"*");
            spacesArray[spaceNumber] = i; 
            spaceNumber++;
        }
    }
    cout << str << endl;
    str.replace(spacesArray[lastSpaceIndex]+1, string::npos, "#!!@1234");
    cout << str << endl;
    /*Erase all words*/
    for (int i = 0; i < numWords; ++i)
    {   cout << str << endl;
        int nextStar = str.find("*");
        str.erase(0,nextStar+1);   
    }

    return 0;
}
/** Sample Execution:
Enter a string
aaa bbb ccc ddd
aaa* bbb* ccc* ddd
aaa * bbb * ccc * #!!@1234
aaa * bbb * ccc * #!!@1234
bbb * ccc * #!!@1234
ccc * #!!@1234
#!!@1234
**/
