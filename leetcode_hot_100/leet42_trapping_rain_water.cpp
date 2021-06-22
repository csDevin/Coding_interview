#include<bits/stdc++.h>
using namespace std;

/* O(n), O(n)动态规划
*/

class Solution {
public:
    int trap1(vector<int>& height) {
        int len = height.size();
        int res=0;
        if(len<=2)
            return 0;
        vector<int> leftMax(len), rightMax(len);
        leftMax[0] = height[0];

        for(int i=1; i<=len-1; i++){  // 从左往右
            leftMax[i] = max(leftMax[i-1], height[i]);
            //***写成了max(height[i-1], height[i]);
        }

        rightMax[len-1] = height[len-1];
        for(int j=len-2; j>=0; j--){  //***从右往左，而不是从左往右
            rightMax[j] = max(height[j], rightMax[j+1]);
            //***写成了max(height[j], height[j+1])
        }

        for(int i=0; i<len; i++){
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return res;
    }
};



/* O(n), O(1)双指针
*/

class Solution {
public:
    int trap2(vector<int>& height) {
        int len = height.size();
        if(len<=2)
            return 0;
        int leftMax = 0, rightMax = 0;
        int left = 0, right = len-1;
        int res = 0;
        while(left != right){
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if(height[left] < height[right]){
                res += leftMax - height[left];
                left++;
            }
            else{
                res += rightMax - height[right];
                right--;  //***right--写成了right++
            }
        }
        return res;
    }
};