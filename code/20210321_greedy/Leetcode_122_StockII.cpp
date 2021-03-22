// 自己错误的解法：想拿max-min，这忽略了在max和min之间的小涨小跌也能带来收益。
// max-min在问题是一次购买一次卖出的情况下最大收益。
int maxProfit(vector<int>& prices) {
    vector<int>::iterator max = max_element(prices.begin(), prices.end());
    vector<int>::iterator min = min_element(prices.begin(), prices.end());
    max_index = distance(prices.begin(), max);
    min_index = distance(prices.begin(), min);
    return *max-*min;
}

// 自己的解法
// 涨了就加到count中，并且要计算当前利润，更新statu，降了就更新status
int maxProfit(vector<int>& prices) {
    int count = 0, status=prices[0];
    for(int i=1; i<prices.size(); i++)
    {
        if(prices[i]>status)  // 涨了
        {
            count+=prices[i]-status;
            status=prices[i];  //***在涨的情况下忘记更新status了
        }
        else  // 跌了
        {
            status=prices[i];
        }
    }
    return count;  //***return错了东西，return成了status
}

// 更好的解法：收集所有上坡值，不需要status变量
int maxProfit(vector<int>& prices) {
    int count = 0;
    for(int i=1; i<prices.size(); i++)
    {
        if(prices[i]>prices[i-1])
        {
            count+=prices[i]-prices[i-1];
        }
    }
    return count;
}