#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i,j;
    int count = 0;
    vector<int> s_stat(s.size(), 1);
    
    for(i=0; i<g.size(); i++)
    {
        for(j=0; j<s.size(); j++)
        {
            if(s_stat[j]==1 && g[i]<=s[j])  // ***错误点"=="写成了"="
            {
                count++;
                s_stat[j] = 0;
                break;
            }
        }
    }
    return count;
}

int main(){
    vector<int> g = {1, 2, 3};
    vector<int> s = {3};
    findContentChildren(g, s);
    return 0;
}