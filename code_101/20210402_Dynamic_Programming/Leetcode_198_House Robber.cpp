// 198: House Robber (Easy)
// 时间复杂度：O(n)
// 空间复杂度：O(n)

int rob(vector<int>& nums) {
    int len = nums.size();
    if(len==0)
        return 0;
    if(len==1)
        return nums[0];
    if(len==2)
        return max(nums[0], nums[1]);
    vector<int> max_m(len);
    max_m[0] = nums[0];
    max_m[1] = max(nums[0], nums[1]);
    // max_m[2] = max(max_m[1], max_m[0]+nums[2]);
    for(int n=2; n<len; n++)
        max_m[n] = max(max_m[n-1], max_m[n-2]+nums[n]);
    return max_m[len-1];
}