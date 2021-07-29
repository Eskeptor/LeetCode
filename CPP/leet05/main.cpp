#include <iostream>
#include <time.h>
using namespace std;

string longestPalindrome(string s)
{
    int nLength = s.length();
    int nStart = 0;
    int nEnd = 0;
    int nCurStart = 0;
    int nCurEnd = 0;
    int nNext = 1;
    bool bIsFind = false;
    
    for (int i = 0; i < nLength; i++)
    {
        nCurStart = i;
        for (int j = nLength - 1; j > i; j--)
        {   
            if (nCurStart == j ||
                nCurStart > j)
            {
                bIsFind = true;
                nCurStart = i;
                break;
            }
            else if (s[nCurStart] == s[j])
            {
                nCurStart++;
                if (nCurEnd == 0)
                    nCurEnd = j;
                bIsFind = true;

                if (j - 1 <= i)
                    nCurStart = i;
            }
            else if (bIsFind)
            {
                bIsFind = false;
                nCurStart = i;
                nCurEnd = 0;
                j = nLength - nNext++;
            }
        }

        if (nEnd - nStart <= nCurEnd - nCurStart &&
            bIsFind)
        {
            nStart = nCurStart;
            nEnd = nCurEnd;
        }
        nNext = 0;
        nCurEnd = 0;
    }

    return s.substr(nStart, nEnd - nStart + 1);
}

int main(void)
{
    string s = "babad";
    clock_t start = clock();
    string output = longestPalindrome(s);
    clock_t end = clock();
    cout << s << " : " << output << endl;
    cout << (double)(end - start) / CLOCKS_PER_SEC << " Sec" << endl;

    s = "cbbd";
    start = clock();
    output = longestPalindrome(s);
    end = clock();
    cout << s << " : " << output << endl;
    cout << (double)(end - start) / CLOCKS_PER_SEC << " Sec" << endl;

    s = "a";
    start = clock();
    output = longestPalindrome(s);
    end = clock();
    cout << s << " : " << output << endl;
    cout << (double)(end - start) / CLOCKS_PER_SEC << " Sec" << endl;

    s = "bacabab";
    start = clock();
    output = longestPalindrome(s);
    end = clock();
    cout << s << " : " << output << endl;
    cout << (double)(end - start) / CLOCKS_PER_SEC << " Sec" << endl;

    
    s = "xaabacxcabaaxcabaax";
    start = clock();
    output = longestPalindrome(s);
    end = clock();
    cout << s << " : " << output << endl;
    cout << (double)(end - start) / CLOCKS_PER_SEC << " Sec" << endl;

    s  = "aaabaaaa";
    start = clock();
    output = longestPalindrome(s);
    end = clock();
    cout << s << " : " << output << endl;
    cout << (double)(end - start) / CLOCKS_PER_SEC << " Sec" << endl;


    return 0;
}