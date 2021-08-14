#include<bits/stdc++.h>
using namespace std;

int seed = time(0);
cout<< rand();

class Solution {
public:
    // dp[i]表示到i位置为止的最长上升子序列的长度，该子序列不一定以nums[i]为结尾。
    // 对于每个元素i判断他前面的元素j，首先i要大于j，其次如果dp[j]+1>dp[i]，则取前者。
    // 返回最长递增子序列的长度，并返回ascii码最小的，即字典序的最长子序列。
    int lengthOfLIS(vector<int>& nums) {
        int res=0;
        int len = nums.size();
        vector<vector<int>> seq;
        if(len==1)
            return 1;
        vector<int> dp(len, 1);
        for(int i=0; i<len; i++){
            seq.push_back({nums[i]});
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    // dp[i] = max(dp[i], dp[j]+1);
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        if(seq[j].size()+1 > seq[i].size()){
                            seq[i] = {nums[i]};
                            seq[i].insert(seq[i].begin(), seq[j].begin(), seq[j].end());
                        }
                    }
                }
            }
        }
        sort(seq.begin(), seq.end(), [](auto &a, auto &b){
            return a.size()>b.size() || (a.size()==b.size() && a<b);
        });
        return *max_element(dp.begin(), dp.end());
    }
};