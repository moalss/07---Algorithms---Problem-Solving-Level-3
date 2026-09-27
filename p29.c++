#include <iostream>
#include <string>
#include <string>

using namespace std;

enum enWhatToCount
{
    lowerLatters = 1,
    upperLatters = 2,
    all = 3
};

short CountLetters(string text, enWhatToCount whatToCount=enWhatToCount::all)
{

    if (whatToCount == enWhatToCount::all)
    {
        return text.length();
    }
    short count = 0;
    for (short i = 0; i < text.length(); i++)
    {
        if (whatToCount == enWhatToCount::lowerLatters && islower(text[i]))
        {
            count++;
        }
        if (whatToCount== enWhatToCount::upperLatters && isupper(text[i]))
        {
            count++;
        }
        
    }

    return count;
}

bool IsLatterLower(char letter)
{

    return islower(letter) ? true : false;
}

void printCountLatters(string text)
{
    int countLower = 0;
    int countUpper = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (IsLatterLower(text[i]) && text[i] != ' ')
        {
            countLower++;
        }
        else if (!IsLatterLower(text[i]) && text[i] != ' ')
        {
            countUpper++;
        }
    }

    cout << "Text length: " << text.length() << ", Lower: " << countLower << ", Upper: " << countUpper;
}

int main()
{

    // PrintLowerLatters("Hello World") ;
    // PrintUpperLatters("Hello World");
    //printCountLatters("Hello World");
    cout << CountLetters("Hello World");
    return 0;
}