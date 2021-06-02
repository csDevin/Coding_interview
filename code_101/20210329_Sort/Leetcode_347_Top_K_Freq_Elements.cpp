// L347: Top K Frequent Elements (Medium)
// 时间复杂度：设m为nums.size()，O(m)。首先，遍历一遍数组统计元素的频率，这一系列操作的时间复杂度是 O(n)；
// 桶的数量为 n+1，所以桶排序的时间复杂度为 O(n)；
// 空间复杂度：O(m)

#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> fre_map;
    vector<vector<int>> vec(1e5+1, vector<int>(0));
    vector<int> result;
    for(int i=0; i<nums.size(); i++)  // 统计频率
        fre_map[nums[i]]++;
    
    // 反转
    for(const auto &p: fre_map)
    {
        vec[p.second].push_back(p.first);
    }

    for (int i=vec.size()-1; i>=0; i--)  //***写成了正向迭代，因为索引是频率，是从小到大排列的，所以要找最大k个索引应该逆向搜索。
    {
        if(result.size()<k)
        {
            result.insert(result.end(), vec[i].begin(), vec[i].end());
        }            
    }
    return result;
}