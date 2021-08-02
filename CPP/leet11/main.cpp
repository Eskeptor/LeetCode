#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height)
{
    int nStart = 0;
    int nEnd = (int)height.size() - 1;
    int nTemp = 0;
    int nMax = 0;

    while (nStart < nEnd)
    {
        nTemp = (nEnd - nStart) * min(height[nEnd], height[nStart]);

        if (nTemp > nMax)
            nMax = nTemp;
        
        if (height[nStart] < height[nEnd])
            nStart++;
        else
            nEnd--;
    }

    return nMax;
}

int main(void)
{
    vector<int> height;
    height.push_back(1);
    height.push_back(1);
    cout << maxArea(height) << endl;

    height.clear();
    height.push_back(4);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(4);
    cout << maxArea(height) << endl;

    height.clear();
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);
    cout << maxArea(height) << endl;

    height.clear();
    height.push_back(1);
    height.push_back(8);
    height.push_back(6);
    height.push_back(2);
    height.push_back(5);
    height.push_back(4);
    height.push_back(8);
    height.push_back(3);
    height.push_back(7);
    cout << maxArea(height) << endl;

    return 0;
}