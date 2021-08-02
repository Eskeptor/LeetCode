#include <iostream>
using namespace std;

int romanToInt(string s)
{
    int nResult = 0;

    for (int i = 0; i < s.length(); i++)
    {
        switch (s.at(i))
        {
            case 'M':
                nResult += 1000;
                break;
            case 'D':
                nResult += 500;
                break;
            case 'C':
                if (s[i + 1] == 'M')
                {
                    nResult += 900;
                    i++;
                }
                else if (s[i + 1] == 'D')
                {
                    nResult += 400;
                    i++;
                }
                else
                    nResult += 100;
                break;
            case 'L':
                nResult += 50;
                break;
            case 'X':
                if (s[i + 1] == 'C')
                {
                    nResult += 90;
                    i++;
                }
                else if (s[i + 1] == 'L')
                {
                    nResult += 40;
                    i++;
                }
                else
                    nResult += 10;
                break;
            case 'V':
                nResult += 5;
                break;
            case 'I':
                if (s[i + 1] == 'X')
                {
                    nResult += 9;
                    i++;
                }
                else if (s[i + 1] == 'V')
                {
                    nResult += 4;
                    i++;
                }
                else
                    nResult += 1;
                break;
        }
    }

    return nResult;
}

int main(void)
{
    string s = "III";
    int nOut = romanToInt(s);
    cout << s << " : " << nOut << endl;

    s = "IV";
    nOut = romanToInt(s);
    cout << s << " : " << nOut << endl;

    s = "IX";
    nOut = romanToInt(s);
    cout << s << " : " << nOut << endl;

    s = "LVIII";
    nOut = romanToInt(s);
    cout << s << " : " << nOut << endl;

    s = "MCMXCIV";
    nOut = romanToInt(s);
    cout << s << " : " << nOut << endl;

    return 0;
}