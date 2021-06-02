// L451: Sort Characters By Frequency (Medium)
// 时间复杂度：设m为s.size()，O(n)。首先，遍历一遍数组统计元素的频率，这一系列操作的时间复杂度是 O(n)；
// 桶的数量为 n+1，所以桶排序的时间复杂度为 O(n)；
// 空间复杂度：O(n)

#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    map<char, int> m_freq;
    vector<vector<char>> r_freq(1e5, vector<char>(0));
    string result;
    for(const auto &p:s)
        m_freq[p]++;

    for(const auto &p:m_freq)  // 将m_freq反转到r_freq
        r_freq[p.second].push_back(p.first);

    for(int i=1e5-1; i>=0; i--)
    {
        if(r_freq[i].size()!=0)
        {
            if(r_freq[i].size()==1)
                result.insert(result.size(), i, r_freq[i][0]);
            else
            {
                for(int j=0; j<r_freq[i].size(); j++)
                {
                    result.insert(result.size(), i, r_freq[i][j]);
                }
            }
        }
    }
    return result;
}


int main()
{
    map<char, int> m;
    vector<char> v(1e5, 0);
    int a = 2;
    return 0;
}