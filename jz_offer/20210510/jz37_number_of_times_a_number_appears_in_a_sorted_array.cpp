/* solutions: 二分查找
*/
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> nums ,int target) {
        int lbound = 0, rbound = 0;
        // 寻找左侧下界
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        lbound = l;  // 通过举例子，大约三种，就可以确定，边界任何情况下都在l处，应为mid是>=l的mid是<r的，mid==r的时候循环已经停止了。
        // 寻找右侧上界
        l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] <= target)
                l = mid+1;
            else
                r = mid-1;
        }
        rbound = l;
        return rbound - lbound;        
    }
};