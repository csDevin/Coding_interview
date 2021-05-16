#include<bits/stdc++.h>
using namespace std;

// 牛客网解法
class Solution {
public:
    int StrToInt(string str) {
        int res;
        stringstream s;
        s<<str;
        s>>res;
        if(str[0]=='+')  //***忘记判断+123的特殊情况
            str.erase(0, 1);  //***写成了str.erase(0)导致删除了str的所有元素。
        if(to_string(res) == str)  //***忘记判断如果是非法的数值，则返回0
            return res;
        else
            return 0;
    }
};

/* 特殊输入
+123
1a34
*/


// leetcode解法
// solution 1: stringstream ，细节更多
class Solution {
public:
    int strToInt(string str) {
        // 删除str中的空格
        int i=0;
        while(i<str.size()){
            if(str[i]==' '){  //***写成了str[i]==0
                i++;
                continue;
            }
            else
                break;
        }
        str.erase(0, i);
        // 如果字符串为空则返回0
        if(str.size()==0)
            return 0;
        // 开始转换
        int res;
        stringstream s;
        s<<str;
        s>>res;
        return res;
    }
};


// leetcode解法
// solution 2: 标准
/*
注意空格、符号位、数字、非数字的处理；
注意数字越界处理；
注意题目中要求只能存储32位的有符号整数（不能用long来判断越界）

分步骤计算：
1 过滤掉前置空格，直到不为空格的字符。
2 如果结束了，返回0.
3 提取+，-符号。
4 如果结束了，返回0.
5 如果当前字符不是数字，返回0.
6 提取整数部分。累加过程中，如果正数 > INT_MAX时，返回INT_MAX. 如果负数 < INT_MIN时，返回INT_MIN.
7 为累加和，带上符号.
。
*/
class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        //1. 过滤掉前置空格，直到不为空格的字符。
        while(i < str.size() && str[i] == ' '){
            ++i;
        }
        if(i>=str.size()){
            return 0;
        }
        bool sign=false;
        //提取+，-符号。
        if(str[i] == '-'){
            sign=true;
            ++i;
        }else if(str[i] == '+'){
            ++i;
        }
        //
        if(i >= str.size()){
            return 0;
        }
        if(!isdigit(str[i])){
            return 0;
        }
        long long ans = 0;
        //提取整数部分。累加过程中，如果正数 > INT_MAX时，返回INT_MAX. 如果负数 < INT_MIN时，返回INT_MIN.
        while(i < str.size() && isdigit(str[i])){
            ans = ans*10 +(str[i] - '0');
            if(!sign && ans > INT_MAX){
                return INT_MAX;
            }else if(sign && -ans < INT_MIN){
                return INT_MIN;
            }
            ++i;
        }

        return sign ? -ans : ans;
    }
};


int main(){
    Solution s1;
    string str = " ";
    cout<<s1.strToInt(str);
    return 0;
}