/* 错误思路：很自然的想到统计每个字母的开始结束区间，转化为区间问题，按照区间右侧排序，从前往后依次选择区间，
 如果区间i右侧<status，则continue，否则status==i右侧。
   问题：此思路往后思考会发现区间左侧完全没有用到，此时应该将问题简化。*/
/*
思路：首先确定当前的分割区间为(0, 第一个字母的最后一个索引)，status记录当前的右侧分割位置，
当当前字母的最后一个字母的位置pos<=status时，continue，否则status=pos，表示当前的分割区间必须往右挪。
当扫描指针i==status时，当前区间分割完成，status为i+1字母的last位置。
*/

// best code：使用数组来维护26个字母的最后出现的数组
vector<int> partitionLabels(string S) {
    int last[26]; // 与map相比此处修改为了int last[26];
    vector<int> divide;
    int status=0;
    for(int i=0; i<S.length(); i++)
    {
        last[S[i]-'a'] = i;  // 与map相比此处修改为了-'a'
    }
    for(int i=0; i<S.length(); i++)
    {
        if(status<last[S[i]-'a'])
            status=last[S[i]-'a'];
        if(i==status)
        {
            int sum = accumulate(divide.begin(), divide.end(), 0);
            divide.push_back(i-sum+1);
            status = i+1;
        }
    }
    return divide;
}

// better code：使用map来维护26个字母的最后出现的数组
vector<int> partitionLabels(string S) {
    map<char, int> last;
    vector<int> divide;
    int status=0;
    for(int i=0; i<S.length(); i++)
    {
        last[S[i]] = i;  //***map名last写成了类名map
    }
    for(int i=0; i<S.length(); i++)
    {
        if(status<last[S[i]])
            status=last[S[i]];
        //***此处多此一举加了一个else continue，导致后面的语句无法执行。
        if(i==status)
        {
            int sum = accumulate(divide.begin(), divide.end(), 0);
            divide.push_back(i-sum+1);
            status = i+1; //***status忘记更新
        }
    }
    return divide;
}

// better code：不使用map，不维护26个字母最后出现的数组，使用string的rfind()函数查找字符的last位置
#include<vector>
#include<string>
#include<iostream>
#include<numeric>
using namespace std;


vector<int> partitionLabels(string S) {
    int len=S.length();
    int status=S.rfind(S[0]);
    
    vector<int> divide;
    for(int i=0; i<len; i++)  //***必须从0开始，否则会漏掉第一个字符是单字符的情况
    {
        int right = S.rfind(S[i]);
        if(right < status)
            continue;
        else
        {
            status = right; 
        }
        if(i == status)  //***必须放在最后，否则会漏掉最后一个字符是单字符的情况。
            divide.push_back(status - accumulate(divide.begin(), divide.end(), 0) + 1);  //***这里是减去求和值，而不是减去vector最后一个值
    }
    return divide;
}

int main()
{
    string s = "eaaaabaaec";
    cout<<partitionLabels(s).size();
    return 0;
}
