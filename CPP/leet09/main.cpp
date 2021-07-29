#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int x) 
{
    bool bResult = true;

    if (x >= 0)
    {
        string strX = to_string(x);
        int nLength = strX.length();

        if (nLength == 1)
            bResult = true;
        else
        {
            for (int i = 0; i < nLength / 2; i++)
            {
                if (strX[i] != strX[nLength - 1 - i])
                {
                    bResult = false;
                    break;
                }
            }
        }
    }
    else
        bResult = false;

    return bResult;
}


int main(void)
{
    int x = 121;
    bool bReturn = isPalindrome(x);
    cout << x << " : " << bReturn << endl;

    x = -121;
    bReturn = isPalindrome(x);
    cout << x << " : " << bReturn << endl;

    x = 10;
    bReturn = isPalindrome(x);
    cout << x << " : " << bReturn << endl;

    x = -101;
    bReturn = isPalindrome(x);
    cout << x << " : " << bReturn << endl;

    return 0;
}