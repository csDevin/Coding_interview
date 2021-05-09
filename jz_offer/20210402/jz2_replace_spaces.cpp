// jz2: 替换空格
// 时间复杂度：O(n)。遍历字符串s一遍。
// 空间复杂度：O(1)。没有额外创建字符数组。
// c++思路：使用str1.erase(pos, n)函数和str1.insert(pos, "%20")函数
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

string replaceSpace(string s) {
    // write code here
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i]==' ')
        {
            s.erase(i, 1);
            s.insert(i, "%20");
        }
    }
    return s;
}

// # python思路：使用s.replace(" ", "%20")函数
// def replaceSpace(self , s ):
//     s2 = s.replace(" ", "%20")
//     return s2