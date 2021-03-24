// 最小覆盖子串（滑动窗口）（hard）
/*
解题思路
map<char, int>：维护B串中每个字符的所需数量
count：维护当前还有多少个所需的字符（count解决了每一次移动窗口，都要去遍历map确定窗口中是否所有字符都满足）

步骤一
不断增加j使滑动窗口增大，直到窗口包含了T的所有元素

步骤二
不断增加i使滑动窗口缩小，因为是要求最小字串，所以将不必要的元素排除在外，使长度减小，直到碰到一个必须包含的元素，
这个时候不能再扔了，再扔就不满足条件了，记录此时滑动窗口的长度，并保存最小值

步骤三
让i再增加一个位置，这个时候滑动窗口肯定不满足条件了，那么继续从步骤一开始执行，寻找新的满足条件的滑动窗口，如此反复，
直到j超出了字符串S范围。
*/


#include <algorithm>
#include <vector>
#include <numeric>
#include <map>
#include <unordered_map>
#include <string>
#include <iostream>  //***忘记写iostream了
using namespace std;


// 自己的代码：使用map
string minWindow(string s, string t) {
    map<char, int> m;
    int left=-1, right=s.length(); //***致命错误，j=0，则j-i=0，right-left永远不可能小于j-i，所以最后的
                                    //结果永远为return "";
    int count=t.length();  // 还需要满足多少个元素
    for(int i=0; i<t.length(); i++)  // m维护当前窗口need的元素个数，-2代表多2个，0代表正好有一个
        m[t[i]] = 0;
    for(int i=0; i<t.length(); i++)  // m维护当前窗口need的元素个数，-2代表多2个，0代表正好有一个
        m[t[i]]++;
    int i = 0, j = 0;

    while(j < s.length() && i < s.length())  //***写成了t.length()
    {
        if(count>0)  // 还有元素未满足，滑动j
        {
            if(m.find(s[j])!=m.end())
            {
                m[s[j]]--;
                if(m[s[j]]>=0)  //***写成了m[s[j]]==0
                    count--;  // 当count==0时，j就应该停住了
            }
            if(count>0)
                j++;  //***j++放到了if前面，这样会错误地跳过第一个元素
        }
        else if(count == 0)  //***写成了==0，导致只执行一次，滑动i,排除多余元素
        {
            // 执行完，m[s[i]]要等于0，i要停在m[s[i]]==0处
            // i--;  //***因为当m[s[i]]==0时，i多加了一步
            // 此处需要在i恰好停在m[s[i]]==0处才执行
            while(m.find(s[i])==m.end() || m[s[i]] < 0)
            {
                if(m.find(s[i])==m.end())
                {
                    i++;
                }
                else
                {
                    m[s[i]]++;
                    i++;
                }
            }
            // 此时m[s[i]] == 0
            if(j-i < right-left)
            {
                left = i;
                right = j;
            }
            m[s[i]]++;
            i++;
            count++;
            j++;
        }
    }
    if(left==-1)
        return "";
    else
        return s.substr(left, right - left + 1); //***从下标为left开始截取长度为r-l+1位。
                                                 // 错误地以为是从left截取到right，写成了s.substr(left, right);
}

// another code：使用大小为128的vector统计字符个数
string minWindow(string s, string t) {
    // map<char, int> m;
    vector<int> m(128, 1e5+1);
    int left=-1, right=s.length(); //***致命错误，j=0，则j-i=0，right-left永远不可能小于j-i，所以最后的
                                    //结果永远为return "";
    int count=t.length();  // 还需要满足多少个元素
    for(int i=0; i<t.length(); i++)  // m维护当前窗口need的元素个数，-2代表多2个，0代表正好有一个
    {
        if(m[t[i]]==1e5+1)
            m[t[i]]=0;
        m[t[i]]++;
    }
    int i = 0, j = 0;

    while(j < s.length() && i < s.length())  //***写成了t.length()
    {
        if(count>0)  // 还有元素未满足，滑动j
        {
            if(m[s[j]]!=1e5+1)
            {
                m[s[j]]--;
                if(m[s[j]]>=0)  //***写成了m[s[j]]==0
                    count--;  // 当count==0时，j就应该停住了
            }
            if(count>0)
                j++;  //***j++放到了if前面，这样会错误地跳过第一个元素
        }
        else if(count == 0)  //***写成了==0，导致只执行一次，滑动i,排除多余元素
        {
            // 执行完，m[s[i]]要等于0，i要停在m[s[i]]==0处
            // i--;  //***因为当m[s[i]]==0时，i多加了一步
            // 此处需要在i恰好停在m[s[i]]==0处才执行
            while(m[s[i]]==1e5+1 || m[s[i]] < 0)  // 此处写得很精妙
            {
                if(m[s[i]]==1e5+1)
                {
                    i++;
                }
                else
                {
                    m[s[i]]++;
                    i++;
                }
            }
            // 此时m[s[i]] == 0
            if(j-i < right-left)
            {
                left = i;
                right = j;
            }
            m[s[i]]++;
            i++;
            count++;
            j++;
        }
    }
    if(left==-1)
        return "";
    else if(left==right)
        return t;
    else
        return s.substr(left, right-left+1);
}



int main()
{
    string a = "ADOBECODEBANC";
    string b = "ABC";
    cout<<minWindow1(a, b);
    return 0;
}


