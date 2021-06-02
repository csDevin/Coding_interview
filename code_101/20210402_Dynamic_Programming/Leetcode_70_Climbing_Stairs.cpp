// L70: Climbing Stairs (Easy)
// 时间复杂度：O(n)
// 空间复杂度：O(n) or can O(1)

int climbStairs(int n) {
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    vector<int> nums(n);
    nums[n-1] = 1;
    nums[n-2] = 2;
    for(int i=n-3; i>=0; i--)
        nums[i] = nums[i+1] + nums[i+2];
    return nums[0];
}


// 代码优化，使用滚动数组，将空间复杂度降为O(1)，即不使用vector数组
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：5.7 MB, 在所有 C++ 提交中击败了92.37%的用户

int climbStairs(int n) {
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    int p = 1;
    int q = 2;
    int curr = 0;
    for(int i=n-3; i>=0; i--)
    {
        curr = p + q;
        p=q;
        q=curr;
    }
    return q;
}

