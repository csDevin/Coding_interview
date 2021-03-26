// 题目：（Medium）
// (better code分析)
// 时间复杂度： O(n⋅xlogn+n⋅x) 。这里， n 表示列表 d 中字符串的数目，x 表示字符串的平均长度。
// 排序需要花费 O(nlogn) 的时间， isSubsequence 函数需要花费 O(x)的时间去检查一个字符串是否是另一个字符串的子序列。
// 空间复杂度： O(logn) 。排序平均需要 O(logn) 的空间。


#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 自己的代码
string findLongestWord(string s, vector<string>& dictionary) {
    string long_word = "";
    int sp=0, dp=0;
    for(int i=0; i<dictionary.size(); i++)
    {
        while(sp<s.size() && dp<dictionary[i].size())
        {
            if(s[sp] == dictionary[i][dp])
            {
                sp++;
                dp++;
            }
            else
                sp++;
        }
        if(dp==dictionary[i].size())
        {
            if(dictionary[i].size() > long_word.size())
            {
                long_word=dictionary[i];
            }
            else if(dictionary[i].size() == long_word.size() && dictionary[i]<long_word)
            {
                long_word=dictionary[i];
            }
        }
        sp=0;
        dp=0;
    }
    return long_word;
}


// better code：代码优化，先将字符串数组进行排序，长度较长的字符串靠前，长度相等则字典序较小的字符串靠前。
string findLongestWord(string s, vector<string>& dictionary) {
    string long_word = "";
    int sp=0, dp=0;

    sort(dictionary.begin(), dictionary.end(), [](const auto &a, const auto &b)
    {
        return a.size() == b.size()? a<b: a.size()>b.size(); 
    });

    for(int i=0; i<dictionary.size(); i++)
    {
        while(sp<s.size() && dp<dictionary[i].size())
        {
            if(s[sp] == dictionary[i][dp])
            {
                sp++;
                dp++;
            }
            else
                sp++;
        }
        if(dp==dictionary[i].size())
        {
            if(dictionary[i].size() > long_word.size())
            {
                long_word=dictionary[i];
            }
            else if(dictionary[i].size() == long_word.size() && dictionary[i]<long_word)
            {
                long_word=dictionary[i];
            }
            return long_word;
        }
        sp=0;
        dp=0;
    }
    return "";
}


int main()
{
    string s = "abpcplea";
    vector<string> vec = {"ale", "apple", "monkey", "plea"};
    cout<<findLongestWord1(s, vec);
    return 0;
}