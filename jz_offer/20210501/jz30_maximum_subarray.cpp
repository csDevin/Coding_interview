class Solution {
public:
    // dp[i]代表以元素nums[i]为结尾的连续子数组最大和
    // 状态转移方程，如果dp[i-1]>0，则dp[i] = dp[i-1]+array[i];，否则dp[i] = array[i];
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> dp(array.size());
        dp[0] = array[0];
        int res = dp[0];
        for(int i=1; i<array.size(); i++){
            if(dp[i-1]>0)
                dp[i] = dp[i-1] + array[i];
            else
                dp[i] = array[i];
            if(dp[i] > res)
                res = dp[i];
        }
        return res;
    }
};