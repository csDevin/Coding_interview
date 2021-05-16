/* solutions (set+遍历 或者 sort+遍历)
while(nums[i]!=0){
    1. 5个数不重复 (set or sort)
    2. 最大和最小牌差的绝对值<=4 (遍历)
}
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> nums ) {
        set<int> num_set;
        int min=14, max=0;
        for(auto p: nums){
            if(p==0)  //***忘记考虑p==0时的特殊情况所有条件都不适用
                continue;
            if(p<min)
                min = p;  //***写成了min = nums[i]
            if(p>max)
                max = p;
            if(num_set.find(p) != num_set.end())
                return false;
            else
                num_set.insert(p);
        }
        return max-min<=4;
    }
};