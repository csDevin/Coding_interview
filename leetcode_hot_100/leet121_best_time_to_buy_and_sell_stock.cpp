#include<bits/stdc++.h>
using namespace std;

// 关键点：用一个变量记录一个历史最低价格minprice
// 我们需要找出给定数组中两个数字之间的最大差值（即，最大利润）。此外，第二个数字（卖出价格）必须大于第一个数字（买入价格）。
// 形式上，对于每组 i 和 j（其中j>i）我们需要找出 max(prices[j]−prices[i])。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len==1)
            return 0;
        int profit = 0;
        int min_price = prices[0];
        for(int i=1; i<len; i++){
            if(prices[i] - min_price > profit){
                profit = prices[i] - min_price;
            }
            else if(prices[i] < min_price)
                min_price = prices[i];
        }
        return profit;
    }
};