/*
hashmap map_val[i]代表i是否存在于数组nums中。
对于每个数字i in nums，如果i-1存在，则continue，否则，不断往后遍历i+1,直到i+1不存在，并用j-i+1来更新最大值。
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        unordered_map<int, int> map_val;
        int res = 1;
        for(auto &p: nums)
            map_val[p] = 1;
        for(int i=0; i<nums.size(); i++){
            if(map_val[nums[i]-1]==1)
                continue;
            int j = nums[i]+1;
            while(map_val[j]==1){
                j++;  // j跳出循环的时候是map_val[j]==0的时候，所以有效区间为[nums[i], j-1]
            }
            if(j-nums[i] > res)
                res = j-nums[i];
        }
        return res;
    }
};