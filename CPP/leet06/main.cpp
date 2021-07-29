#include <iostream>
#include <string.h>
using namespace std;

string convert(string s, int numRows)
{
    string strResult = "";
    int nLength = s.length();
    char** chArr = new char*[numRows];
    for (int i = 0; i < numRows; i++)
    {
        chArr[i] = new char[nLength];
        memset(chArr[i], 0, sizeof(char) * nLength);
    }

    int nXAdder = 0;
    int nYAdder = 0;
    int nX = 0;
    int nY = 0;
    bool bToggle = false;
    for (int i = 0; i < nLength; i++)
    {
        if (numRows - 1 == 0)
        {
            nXAdder = 1;
            nYAdder = 0;
        }
        else
        {
            if (i % (numRows - 1) == 0)
            {
                if (bToggle == false)
                {
                    nXAdder = 0;
                    nYAdder = 1;
                    bToggle = true;
                }
                else
                {
                    nXAdder = 1;
                    nYAdder = -1;
                    bToggle = false;
                }
            }
        }

        chArr[nY][nX] = s.at(i);
        nY += nYAdder;
        nX += nXAdder;  
    }

    for (int y = 0; y < numRows; y++)
    {
        for (int x = 0; x < nLength; x++)
        {
            if (chArr[y][x] != 0)
                strResult.push_back(chArr[y][x]);
        }
    }


    for (int i = 0; i < numRows; i++)
    {
        delete[] chArr[i];
        chArr[i] = nullptr;
    }
    delete[] chArr;

    return strResult;
}

int main(void)
{
    string strResult = convert("PAYPALISHIRING", 3);
    cout << "PAYPALISHIRING : " << strResult << endl;

    strResult = convert("PAYPALISHIRING", 4);
    cout << "PAYPALISHIRING : " << strResult << endl;

    strResult = convert("AAAVV", 1);
    cout << "A : " << strResult << endl;

    return 0;
}