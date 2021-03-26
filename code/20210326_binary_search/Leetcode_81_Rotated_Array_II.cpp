// L81: Search in Rotated Sorted Array II (Medium)

# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

// 使用find函数
bool search(vector<int>& nums, int target) {
    return find(nums.begin(), nums.end(), target)!=nums.end();
}

// better code
// 忽略了第一类情况
// 第一类
// 1011110111 和 1110111101 这种。此种情况下 nums[start] == nums[mid]，分不清到底是前面有序还是后面有序，此时 start++ 即可。相当于去掉一个重复的干扰项。
// 第二类
// 22 33 44 55 66 77 11 这种，也就是 nums[start] < nums[mid]。此例子中就是 2 < 5；
// 这种情况下，前半部分有序。因此如果 nums[start] <=target<nums[mid]，则在前半部分找，否则去后半部分找。
// 第三类
// 66 77 11 22 33 44 55 这种，也就是 nums[start] > nums[mid]。此例子中就是 6 > 2；
// 这种情况下，后半部分有序。因此如果 nums[mid] <target<=nums[end]。则在后半部分找，否则去前半部分找。
// 技巧：如果nums[left]==nums[mid];则left++;
//          nums[right]==nums[mid];则right--;
bool search(vector<int>& nums, int target) {
    int nLen = nums.size();
    int left=0, right=nLen-1;
    while(left<=right)  //***写成了left<right
    {
        int mid = left + (right-left)/2;
        if(nums[mid] == target)
            return true;
        else if(nums[left]==nums[mid])  //***忘记单独考虑10111
        {
            left++;
            continue;  // 节约时间
        } 
        else if(nums[right]==nums[mid])  //***忘记单独考虑10111
        {
            right--;
            continue;  // 节约时间
        } 
        else if(nums[left]<nums[mid] && (target>nums[mid] || target<nums[left]))  // 左边有序,在右边
        {
            left = mid + 1;
        }
        else if(nums[left]<nums[mid] && (target<nums[mid] && target>=nums[left]))  // 左边有序,在左边
        {
            right = mid - 1;
        }
        else if(nums[mid]<nums[right] && (target<nums[mid] || target>nums[right]))  // 右边有序,在左边
        {
            right = mid - 1;
        }
        else if(nums[mid]<nums[right] && (target>nums[mid] && target<=nums[right]))  // 右边有序,在右边
        {
            left = mid + 1;
        }
    }
    return false;
}


// 逻辑优化后代码
bool search(vector<int>& nums, int target) {
    int nLen = nums.size();
    int left=0, right=nLen-1;
    while(left<=right)  //***写成了left<right
    {
        int mid = left + (right-left)/2;
        if(nums[mid] == target)
            return true;
        else if(nums[left]==nums[mid])  //***忘记单独考虑10111
        {
            left++;
            continue;  // 节约时间
        } 
        else if(nums[right]==nums[mid])  //***忘记单独考虑10111
        {
            right--;
            continue;  // 节约时间
        } 
        else if(nums[left]<nums[mid])
        {
            if(target<nums[mid] && target>=nums[left])  // 左边有序,在左边
            {
                right = mid - 1;
            }
            else  // 左边有序,在右边
            {
                left = mid + 1;
            }
        }
        else if(nums[mid]<nums[right])
        {
            if(target>nums[mid] && target<=nums[right])  // 右边有序,在右边
            {
                left = mid + 1;
            }
            else  // 右边有序,在左边
            {
                right = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> vec = {2,5,6,0,0,1,2};
    int a = 3;
    cout<<search1(vec, a);
    return 0;
}