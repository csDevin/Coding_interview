// 154: Find Minimum in Rotated Sorted Array II (hard)
#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int nLen=nums.size();
    int left=0, right=nLen-1, min_num=INT_MAX;

    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(nums[left]==nums[mid])
        {
            min_num=min(min_num, nums[left]);  // 如果left==mid则尝试更新min_num
            left++;
            continue;
        }
        if(nums[left]<nums[mid])  // 左侧有序，则尝试更新min_num为左侧最小值
        {
            min_num=min(min_num, nums[left]);
            left=mid+1;
        }
        else  // 右侧有序，则尝试更新min_num为左侧最小值
        {
            min_num=min(min_num, nums[mid]);
            right=mid-1;
        }
    }
    return min_num; //***写成了return nums[left];
}

int main()
{
    vector<int> vec={1, 3, 4, 5};
    cout << findMin(vec);
    return 0;
}