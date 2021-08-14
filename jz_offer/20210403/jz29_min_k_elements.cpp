#include<bits/stdc++.h>
using namespace std;

// jz29: 最小的K个数
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    int len = input.size();
    if(k>len)
        return {};
    sort(input.begin(), input.end());
    vector<int> result(input.begin(), input.begin()+k);
    return result;
}