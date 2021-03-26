// L34: Find First and Last Position of Element in Sorted Array (Medium)
// 时间复杂度：直观的思路肯定是从前往后遍历一遍。用两个变量记录第一次和最后一次遇见target 的下标，
// 但这个方法的时间复杂度为 O(n)，没有利用到数组升序排列的条件。
// 空间复杂度：O(1)

// 方法1：使用find函数配合正向迭代器iterater和反向迭代器reverse_iterator,
// 从前往后和从后往前分别搜索targe。
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>::iterator it1 = find(nums.begin(), nums.end(), target);
    vector<int>::reverse_iterator it2 = find(nums.rbegin(), nums.rend(), target);
    if(it1==nums.end())
        return {-1, -1};
    int dis1 = distance(nums.begin(), it1);
    int dis2 = distance(it2, nums.rend())-1;
    return {dis1, dis2};
}

// 方法2：使用二分查找（考虑left可能超出右边界，right可能超出左边界）
// 时间复杂度：O(logn)
// 空间复杂度：O(1)

// 搜索左侧边界，当nums[mid]==target时，不return，而是另right=mid-1，向左搜索，直到right超出左边界，
// 此时left处一定为最左边一个target的所在处。
// 注意：最后判断nums[right]==target的时候，一定要先判断left是否超出右边界。
vector<int> searchRange(vector<int>& nums, int target) {
    int nLen = nums.size();
    int b_left=-1, b_right=nLen;
    int left=0, right=nLen-1;
    while(left<=right)  // 找左边界
    {
        int mid = left+(right-left)/2;
        if(nums[mid] >= target)
        {
            right=mid-1;  // 向左收缩
        }
        else if(nums[mid] < target)
            left = mid+1;
    }
    if(left!=nLen && nums[left]==target)  // 防止left越右界
        b_left=left;
    
// 搜索右侧边界，当nums[mid]==target时，不return，而是另left=mid-1，向右搜索，直到left超出右边界，
// 此时right处一定为最右边一个target的所在处。
// 注意：最后判断nums[right]==target的时候，一定要先判断right是否超出左边界。
    left=0, right=nLen-1;
    while(left<=right)  // 找右边界
    {
        int mid = left+(right-left)/2;
        if(nums[mid] > target)
        {
            right=mid-1;  // 向左收缩
        }
        else if(nums[mid] <= target)
            left = mid+1;
    }
    if(right!=-1 && nums[right]==target)  // 防止left越右界
        b_right=right;

    if(b_left!=-1)
        return {b_left, b_right};
    else
        return {-1, -1};
}