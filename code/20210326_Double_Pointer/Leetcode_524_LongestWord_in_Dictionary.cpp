// 题目：（Medium）
// 时间复杂度：
// 空间复杂度：


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