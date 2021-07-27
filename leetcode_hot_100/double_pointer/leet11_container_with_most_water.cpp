#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if(len<=1){
            return 0;
        }
        int l=0, r=len-1;
        int max_capacity = INT_MIN, tmp_capacity;
        while(l<r){
            if(height[l] < height[r]){
                tmp_capacity  = (r-l)*height[l];
                l++;
            }
            else{
                tmp_capacity  = (r-l)*height[r];
                r--;
            }
            if(tmp_capacity > max_capacity){
                max_capacity = tmp_capacity;
            }
        }
        return max_capacity;
    }
};