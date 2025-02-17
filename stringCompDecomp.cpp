#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Compressed(string line)
{
    if (line.empty()) //checks if imput is empty
    {
        cout << ""; //returns an empty string if imput is empty
        return "";
    }
    string compressed = ""; //compressed string for answers
    int count = 1; //count variable that count the amount of the same character
    for (int i = 0; i < line.size(); i++) //for loops until the end of the string
    {
        /*if the next i will be the end of the string(aka curent i is the last character of the string)
         and the next character is the same as the current character, then increase count by 1
         this statement checks for the next character to be the same as the current character 
         aswell as i being within the limits of the line string size
        */
        if (i + 1 < line.size() && line[i] == line[i + 1]) count++;
        /*else add to the compressed string the current character and the count of the same character
         and set count to 1. This only happens when the if above is false, meaning current character line[i] is different
         to the next character line[i+1] and the i is within the line string limits, meaning its time to save the answer
         to the compressed string. Count needs to be reset back to 1, since we need to start a new count for the next character
        */
        else
        {
            compressed += line[i];
            compressed += to_string(count);
            count = 1;
        }
    }
    return compressed;//returns the compressed string
}
string Decompressed(string line)
{
    if (line.empty()) //checks if imput is empty
    {
        cout << ""; //returns an empty string if imput is empty
        return "";
    }
    string decompressed = ""; //decompressed string for answers
    int curCount; //curCount - current count of the character
    char curChar; //curChar - currect character
    /*for loops until it itirates over the whole line string
    */
    for (int i = 0; i < line.size(); i++)
    {
        curChar = line[i]; //sets curChar to the current character
        string countStr = ""; //countStr - string that holds the count of the current character (number chars)
        i++; // move to the count character (number char)
        /*while i is within the line string size and the current character is a digit,
         number chars are added to the countStr string and i is increased by 1.
         This while loop saves all the number chars in the countStr string, which later will be converted to a integer using
         a stoi function.
        */
        while (i < line.size() && isdigit(line[i]))
        {
            countStr += line[i];
            i++;
        }
        /*We move back to the position of i after the count. This is necessary because the while loop increments i by 1 everytime it
         saves a number char to the countStr string. Therefore, after all the numbers have been saved, i is increased by 1 one last time
         and so i will be at the position after the count. But then when the for loop goes to the next iteration, i will be at the
         at the position after the letter char, which we do not want. So we decrease i by 1, so when the next for loop iteration happens,
         i will be at the position right after the count, on the next letter char
        */
        i--;
        curCount = stoi(countStr); //converts countStr string to an integer
        /*Add current character to the decompressed string curCount times*/
        for (int j = 0; j < curCount; j++) decompressed += curChar;
    }
    return decompressed;//returns the decompressed string
}
int main()
{
    string line; //a string to read the imput;
    cin >> line;
    cout<<Compressed(line);
    cout<<Decompressed(line);
}