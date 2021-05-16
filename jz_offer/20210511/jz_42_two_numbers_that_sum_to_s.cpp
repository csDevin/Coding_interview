#include<bits/stdc++.h>
using namespace std;

/* solution 1: 前后双指针法 (因为有序，所以可以使用双指针法)
l指针和r指针，若nums[l]+nums[r]<target，则l++，否则，r--，若l>=target,return {};
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            int tmp = nums[l]+nums[r];
            if(tmp == target){
                return {nums[l], nums[r]};
            }
            else if(tmp < target){
                l++;
            }
            else{
                r--;
            }
        }
        return {};
    }
};


/* solution 2: hashmap输出乘积最小的一对，先建表，再查找
hashmap save the num of (target-nums[i])， if(target-nums[i]) no in hashmap，insert，else return。
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;  //***记住m中存储的是nums的值，查询m中查询的是target-nums[i]的值
        for(int i=0; i<nums.size(); i++){
            m[nums[i]] = i;  //***写成了m[target-nums[i]] = i，记住m中存储的是nums的值，查询m中查询的是target-nums[i]的值
        }
        for(int i=0; i<nums.size(); i++){
            auto it =  m.find(target-nums[i]);  //***find是查找map->first索引，map是m.find()，不然报错
            if(it != m.end())
                return {nums[i], it->first};
        }
        return {};
    }
};


/* solution 3: hashmap输出任意一对，边建表，边查找
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;  //***记住m中存储的是nums的值，查询m中查询的是target-nums[i]的值
        for(int i=0; i<nums.size(); i++){
            auto it =  m.find(target-nums[i]);  //***find是查找map->first索引，map是m.find()，不然报错
            if(it != m.end())
                return {it->first, nums[i]};
            m[nums[i]] = i;  //***写成了m[target-nums[i]] = i，记住m中存储的是nums的值，查询m中查询的是target-nums[i]的值
        }
        return {};
    }
};