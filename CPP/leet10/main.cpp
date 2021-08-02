#include <iostream>
using namespace std;

// 아직 못품 ㅠㅠㅠㅠ

bool isMatch(string s, string p)
{
    bool bResult = true;
    int nSLength = s.length();
    int nPLength = p.length();

    if (nSLength > nPLength)
        return false;
    else
    {
        if (p[0] == '*')
        {
            int nRemoveIdx = 0;
            for (int i = 0; i < nPLength; i++)
            {
                if (p[i] == '*')
                    nRemoveIdx++;
                else
                    break;
            }
            p = p.substr(nRemoveIdx);
            nPLength = p.length();
        }

        int nIdx = 0;
        string strNew = "";
        for (int i = 0; i < nSLength; i++)
        {
            if (s[i] == p[nIdx])
                strNew.push_back(p[nIdx]);
            else if (p[nIdx] == '.')
                strNew.push_back(s[i]);
            else if (p[nIdx] == '*')
            {
                if (p[nIdx - 1] == s[i])
                    strNew.push_back(s[i]);
                else
                    return false;
            }
            else // s[i] != p[nIdx]
            {
                if (nIdx )
                if (s[i] == p[])
            }
            nIdx++;
        }
        if (nIdx + 1 != nPLength)
            return false;
        
    }
    
    return bResult;
}

int main(void)
{
    string s = "aa";
    string p = "a";
    bool bResult = isMatch(s, p);
    cout << s << ", " << p << " : " << bResult << endl;

    s = "aa";
    p = "a*";
    bResult = isMatch(s, p);
    cout << s << ", " << p << " : " << bResult << endl;

    s = "ab";
    p = ".*";
    bResult = isMatch(s, p);
    cout << s << ", " << p << " : " << bResult << endl;

    s = "aab";
    p = "c*a*b";
    bResult = isMatch(s, p);
    cout << s << ", " << p << " : " << bResult << endl;

    s = "mississippi";
    p = "mis*is*p*.";
    bResult = isMatch(s, p);
    cout << s << ", " << p << " : " << bResult << endl;

    s = "ab";
    p = ".*c";
    bResult = isMatch(s, p);
    cout << s << ", " << p << " : " << bResult << endl;

    return 0;
}