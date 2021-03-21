#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// 1 自己的解法，i是不可逆指针（只能往后扫描），j是循环指针，需要解决饼干重用的问题，使用了s_stat[]数据来标记已经使用过的饼干。
int findContentChildren1(vector<int>& g, vector<int>& s) {
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


// 2 更好的解法，i是不可逆指针，j是不可逆指针，解决了饼干重用问题。使用for(i,j)+while的结构。
// 结构while{if else},用while判断边界，用if else走(i++,j++)和j++。
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());  //*** 贪心算法开头忘记了要排序
    sort(s.begin(), s.end());
    int len_g = g.size(), len_s = s.size();
    int i = 0, j = 0, count = 0;
    while(i<len_g && j<len_s)  //*** len_s写成了len_g
    {
        if(g[i]<=s[j])
        {
            count++;
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return count;
}


// 3 更好的解法，i是不可逆指针，j是不可逆指针，解决了饼干重用问题。使用for(i,j)+while的结构。
// 结构for{while if},用if判断边界并走(i++, j++)，用while走j++。
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int len_g = g.size(), len_s = s.size();
    int count = 0;
    for(int i=0, j=0; i<len_g && j<len_s ;i++, j++)
    {
        while(j<len_s && g[i]>s[j])
            j++;
        if(j<len_s)
            count++;
    }
    return count;
}

int main(){
    vector<int> g = {1, 2, 3, 5, 2, 1, 54};
    vector<int> s = {1,1, 12, 234234, 1, 232};
    cout<<findContentChildren(g, s);
    return 0;
}