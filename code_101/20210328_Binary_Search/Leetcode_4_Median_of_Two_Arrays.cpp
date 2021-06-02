// 4: Median of Two Sorted Arrays (Hard)
// 时间复杂度：O(m+n)
// 空间复杂度：O(m+n)

#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    int m=nums1.size(), n=nums2.size();
    double result = 0.0;
    vector<int> nums3;
    while(i<m || j<n)  // 归并排序
    {
        if(i<m && j>=n)
        {
            nums3.push_back(nums1[i]);
            i++;
        }
        else if(i>=m && j<n)
        {
            nums3.push_back(nums2[j]);
            j++;                
        }
        else if(nums1[i]<=nums2[j])
        {
            nums3.push_back(nums1[i]);
            i++;
        }
        else
        {
            nums3.push_back(nums2[j]);
            j++;                
        }
    }
    if((m+n)%2 == 1)
    {
        result = nums3[(m + n) / 2];
        return result;
    }
    else
    {
        result = ( nums3[(m+n)/2-1] + nums3[(m+n)/2] ) / 2.0;  //***2.0写成了2，分子分母都是整数，结果也是整数
        return result;
    }     
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout<<findMedianSortedArrays(nums1, nums2);
    return 0;
}

