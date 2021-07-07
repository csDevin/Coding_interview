#include<bits/stdc++.h>
using namespace std;

// 关键点：使用异或^运算。
// 异或运算性质：(1) 任何数与0做异或运算都为自己本身；(2) 任何书与自己做异或运算都为0；(3) 异或运算满足交换律和结合律
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return nums[0]; 
        int res = 0;
        for(auto x: nums){
            res ^= x;
        }
        return res;
    }
};