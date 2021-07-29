#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    double dResult = 0.0;
    vector<int> vSorted;
    
    auto iter1 = nums1.begin();
    auto iter2 = nums2.begin();

    while (iter1 != nums1.end() ||
           iter2 != nums2.end())
    {
        if (iter1 == nums1.end())
        {
            vSorted.push_back(*iter2);
            iter2++;
        }
        else if (iter2 == nums2.end())
        {
            vSorted.push_back(*iter1);
            iter1++;
        }
        else if (*iter1 >= *iter2)
        {
            vSorted.push_back(*iter2);
            iter2++;
        }
        else if (*iter1 < *iter2)
        {
            vSorted.push_back(*iter1);
            iter1++;
        }
    }

    int nSize = vSorted.size();
    int nHalf = nSize / 2;
    if (nSize > 0)
    {
        if (nHalf * 2 == nSize)
            dResult = (vSorted.at(nHalf) + vSorted.at(nHalf - 1)) / 2.0;
        else
            dResult = vSorted.at(nHalf);
    }


    return dResult;
}

int main(void)
{
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);     nums1.push_back(3);
    nums2.push_back(2);
    double d1 = findMedianSortedArrays(nums1, nums2);
    cout << d1 << endl;
    nums1.clear();          nums2.clear();

    nums1.push_back(1);     nums1.push_back(2);
    nums2.push_back(3);     nums2.push_back(4);
    d1 = findMedianSortedArrays(nums1, nums2);
    cout << d1 << endl;
    nums1.clear();          nums2.clear();

    nums1.push_back(0);     nums1.push_back(0);
    nums2.push_back(0);     nums2.push_back(0);
    d1 = findMedianSortedArrays(nums1, nums2);
    cout << d1 << endl;
    nums1.clear();          nums2.clear();

    nums2.push_back(1);
    d1 = findMedianSortedArrays(nums1, nums2);
    cout << d1 << endl;
    nums1.clear();          nums2.clear();

    nums1.push_back(2);
    d1 = findMedianSortedArrays(nums1, nums2);
    cout << d1 << endl;
    nums1.clear();          nums2.clear();


    return 0;
}