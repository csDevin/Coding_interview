/* solution: sliding windows 滑动窗口 (l和r只能右移，l和r组成左闭右开的区间)
想通了何时缩小窗口，合适扩大窗口，就能解决滑动窗口问题。
本题应该以和sum和target的关系来确定收缩还是扩张，以及存储res。
1. sum<target：扩大窗口，r右移一位，sum+=nums[r+1]；
2. sum>target: 缩小窗口，l右移一位，sum-=nums[l]；
3. sum==target: 保存[l,r)中的元素到res中，并且l右移一位，sum-=nums[l]。

停止条件： while (i <= target / 2)，因为求和的数大于等于两个，所以两个数中开始数字一定是<=target/2的。
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int target) {
        int l=1, r=1, sum=0; 
        vector<vector<int>> res;
        vector<int> tmp;
        while(l<=target/2){
            if(sum < target){
                r++;
                sum += r-1;  //***忘记了滑动窗口是左闭右开的区间，写成了sum+=r
            }
            else if(sum > target){
                sum -= l;
                l++;
            }
            else{
                for(int i=l; i<r; i++){
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                //***忘记tmp添加到res后要l++了
                sum -= l;
                l++;
                tmp.clear();  //***每次找到一个符合条件的序列tmp时，将tmp加入到res中后，需要清空tmp
                              //***或者把tmp定义为else中的局部变量，每次运行时会重新定义一个新的tmp
            }
        }
        return res;
    }
};