// 540: Single Element in a Sorted Array (Medium)
// 时间复杂度：O(logn)
// 空间复杂度：O(1)

#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int left=0, right=nums.size()-1;
    while(left<right)
    {
        int mid = (left+right)/2;
        if(nums[mid]==nums[mid-1])
        {
            if(mid%2==1)  //***写成了mid%2==0,因为忘记了程序中索引是从0开始，mid是奇，在右边
                        //也就是，mid是奇代表mid是第偶数个数 
                left=mid+1;
            else
                right=mid-2;//***mid-2写成了mid-1，因为需要跳过已经确定重复的元素
        }
        else if(nums[mid]==nums[mid+1])
        {
            if(mid%2==1)  // mid是奇，在左边
                right=mid-1;  
            else
                left=mid+2;
        }
        else
            return nums[mid];
    }
    return nums[left];
}


int main()
{
    vector<int> vec={2,2,3,3,6};
    cout<<singleNonDuplicate(vec);
    return 0;
}