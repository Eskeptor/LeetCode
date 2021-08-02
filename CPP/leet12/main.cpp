#include <iostream>
using namespace std;

string intToRoman(int num)
{
    constexpr char ROMAN_CH[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    string strReturn = "";
    int nNum = num;
    int nTemp = num;

    int nDiv = 1000;
    int nChPoint = 0;
    do
    {
        nTemp = nNum / nDiv;
        if (nTemp > 0)
        {
            if (nNum >= nDiv * 5)
            {
                if (nNum >= nDiv * 9)
                {
                    strReturn.push_back(ROMAN_CH[nChPoint]);
                    strReturn.push_back(ROMAN_CH[nChPoint - 2]);
                }
                else
                {
                    strReturn.push_back(ROMAN_CH[nChPoint - 1]);
                    for (int i = 0; i < nTemp - 5; i++)
                        strReturn.push_back(ROMAN_CH[nChPoint]);
                }
            }
            else if (nNum >= nDiv * 4)
            {
                strReturn.push_back(ROMAN_CH[nChPoint]);
                strReturn.push_back(ROMAN_CH[nChPoint - 1]);
            }
            else
            {
                for (int i = 0; i < nTemp; i++)
                    strReturn.push_back(ROMAN_CH[nChPoint]);
            }

            
            if (nDiv > 0)
                nNum %= nDiv;
        }

        nDiv /= 10;
        nChPoint += 2;
        
        
    } while (nDiv != 0);
    
    return strReturn;
}

int main(void)
{
    int num = 3;
    string strRoman = intToRoman(num);
    cout << num << " : " << strRoman << endl;

    num = 4;
    strRoman = intToRoman(num);
    cout << num << " : " << strRoman << endl;

    num = 9;
    strRoman = intToRoman(num);
    cout << num << " : " << strRoman << endl;

    num = 58;
    strRoman = intToRoman(num);
    cout << num << " : " << strRoman << endl;

    num = 1994;
    strRoman = intToRoman(num);
    cout << num << " : " << strRoman << endl;

    return 0;
}