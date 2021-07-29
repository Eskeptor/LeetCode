#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int reverse (int x)
{
    int nResult = 0;
    bool bIsMinus = x < 0 ? true : false;

    string str = "";
    if (x % 10 == 0)
        str = to_string(abs(x / 10));
    else
        str = to_string(abs(x));

    ::reverse(str.begin(), str.end());
    try
    {
        nResult = stoi(str);
    }
    catch(const std::exception& e)
    {
        nResult = 0;
    }
    
    if (bIsMinus)
        nResult *= -1;

    return nResult;
}

int main(void)
{
    int x = 123;
    cout << x << " : " << reverse(x) << endl;

    x = -123;
    cout << x << " : " << reverse(x) << endl;

    x = 120;
    cout << x << " : " << reverse(x) << endl;

    x = 0;
    cout << x << " : " << reverse(x) << endl;

    x = 1534236469;
    cout << x << " : " << reverse(x) << endl;

    return 0;
}
