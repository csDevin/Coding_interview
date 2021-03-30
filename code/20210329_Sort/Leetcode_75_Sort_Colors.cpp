// L75: Sort Colors (Medium)
// 时间复杂度：O(n)
// 空间复杂度：O(n)


#include<bits/stdc++.h>
using namespace std;


void sortColors(vector<int>& nums) {
    map<int, int> freq;  // 使用map
    vector<int> result;
    // 一次线性扫描统计频率
    for(const auto &p: nums)
        freq[p]++;
    // 生成结果
    for(int i=0; i<3; i++)
        result.insert(result.end(), freq[i], i);
    nums = result;
}

void sortColors1(vector<int>& nums) {
    vector<int> freq(3,0);  // 使用vector
    vector<int> result;
    // 一次线性扫描统计频率
    for(const auto &p: nums)
        freq[p]++;
    // 生成结果
    for(int i=0; i<3; i++)
        result.insert(result.end(), freq[i], i);
    nums = result;
}

int main()
{
    vector<int> vec = {7, 6, 5, 4, 3, 2, 14};
    vec.insert(vec.end(), 1, 10);
    int a = 2;
    return 0;
}