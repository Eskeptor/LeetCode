#include <iostream>
using namespace std;

int myAtoi(string s)
{
    int nResult = 0;
    string strPros = "";
    int nLength = s.length();

    bool bFirst = true;
    bool bIsMinus = false;
    for (int i = 0; i < nLength; i++)
    {
        if (s[i] >= '0' &&
            s[i] <= '9')
        {
            if (bFirst)
                bFirst = false;
            strPros.push_back(s[i]);
        }
        else if (s[i] == '-')
        {
            if (bFirst)
            {
                bIsMinus = true;
                bFirst = false;
                strPros.push_back(s[i]);
            }
            else
                break;
        }
        else if (s[i] == '+')
        {
            if (bFirst)
                bFirst = false;
            else
                break;
        }
        else
        {
            if (s[i] != ' ')
                break;
            else if (bFirst == false)
                break;
        }
    }

    try
    {
        nResult = stoi(strPros);
    }
    catch(const std::exception& e)
    {
        if (strPros[0] == '-' &&
            strPros.length() > 1)
            nResult = INT32_MIN;
        else if (strPros.length() <= 1 && (s[0] > '9' || s[0] < '0'))
            nResult = 0;
        else
            nResult = INT32_MAX;
    }

    return nResult;
}

int main(void)
{
    string s = "42";
    int a = myAtoi(s);
    cout << s << " : " << a << endl;

    s = "      -42";
    a = myAtoi(s);
    cout << s << " : " << a << endl;

    s = "4193 with words";
    a = myAtoi(s);
    cout << s << " : " << a << endl;

    s = "words and 987";
    a = myAtoi(s);
    cout << s << " : " << a << endl;

    s = "-91283472332";
    a = myAtoi(s);
    cout << s << " : " << a << endl;

    s = "91283472332";
    a = myAtoi(s);
    cout << s << " : " << a << endl;

    s = ".1";
    a = myAtoi(s);
    cout << s << " : " << a << endl;

    s = "+-1";
    a = myAtoi(s);
    cout << s << " : " << a << endl;

    s = "-+1";
    a = myAtoi(s);
    cout << s << " : " << a << endl;

    s = "    +11191657170";
    a = myAtoi(s);
    cout << s << " : " << a << endl;

    return 0;
}
