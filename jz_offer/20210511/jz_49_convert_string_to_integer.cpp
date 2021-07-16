#include <bits/stdc++.h>
using namespace std;

// 牛客网解法
class Solution
{
public:
    int StrToInt(string str)
    {
        int res;
        stringstream s;
        s << str;
        s >> res;
        if (str[0] == '+')         //***忘记判断+123的特殊情况
            str.erase(0, 1);       //***写成了str.erase(0)导致删除了str的所有元素。
        if (to_string(res) == str) //***忘记判断如果是非法的数值，则返回0
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
class Solution
{
public:
    int strToInt(string str)
    {
        // 删除str中的空格
        int i = 0;
        while (i < str.size())
        {
            if (str[i] == ' ')
            { //***写成了str[i]==0
                i++;
                continue;
            }
            else
                break;
        }
        str.erase(0, i);
        // 如果字符串为空则返回0
        if (str.size() == 0)
            return 0;
        // 开始转换
        int res;
        stringstream s;
        s << str;
        s >> res;
        return res;
    }
};

// leetcode解法
// solution 2: 标准
/*
注意空格、符号位、数字、非数字的处理；
注意数字越界处理；
注意题目中要求只能存储32位的有符号整数（不能用long来判断越界）

_ _ _ + @ 1 2 3 4 5 _ _ a _
分步骤计算：
1 过滤掉前置空格，直到不为空格的字符.如果结束了，返回0.
2 提取+，-符号sign.如果结束了，返回0.
3 如果当前字符不是数字，返回0.
4 提取整数部分，如果不是isdigit则返回。累加过程中，如果正数 > INT_MAX时，返回INT_MAX. 如果负数 < INT_MIN时，返回INT_MIN.
5 过滤后置空格，直到不为空格的字符，如果是是字母字符则返回0.
6 为累加和带上符号.
*/

class Solution
{
public:
    int StrToInt(string str)
    {
        int i = 0;
        //1. 过滤掉前置空格，直到不为空格的字符。
        while (i < str.size() && str[i] == ' ')
        {
            ++i;
        }
        if (i >= str.size())
        {
            return 0;
        }
        bool sign = false;
        //提取+，-符号。
        if (str[i] == '-')
        {
            sign = true;
            ++i;
        }
        else if (str[i] == '+')
        {
            ++i;
        }
        //
        if (i >= str.size())
        {
            return 0;
        }
        if (!isdigit(str[i]))
        {
            return 0;
        }
        long long ans = 0;
        //提取整数部分。累加过程中，如果正数 > INT_MAX时，返回INT_MAX. 如果负数 < INT_MIN时，返回INT_MIN.
        while (i < str.size() && isdigit(str[i]))
        {
            int num = (str[i] - '0');
            if (!sign && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && num > INT_MAX % 10)))
                return INT_MAX;
            if (sign && (-ans < INT_MIN / 10 || (-ans == INT_MIN / 10 && num < INT_MIN % 10)))
                return INT_MIN;
            ans = ans * 10 + num;
            // if(!sign && ans > INT_MAX){
            //     return INT_MAX;
            // }else if(sign && -ans < INT_MIN){
            //     return INT_MIN;
            i++;  //***忘记i++导致最后结果未11111111
        }
        while(i<str.size() && str[i]==' ')  // 去除后置空格
            i++;
        if(i<str.size() && !isdigit(str[i]))  // 如果最后存在非空格，非数字的非法字符，则返回0。
            return 0;
            
        // 如果不用long long的话使用res和INT_MAX去比较，
        // (1) res>INT_MAX/10 || (res==INT_MAX/10 && (s[i]-'0'>INT_MAX%10))，则return INT_MAX
        // (1) resI<NT_MIN/10 || (res==INT_MIN/10 && (s[i]-'0'<INT_MIN%10))，则return INT_MIN

        // if(res > Integer.MAX_VALUE/10 || (res == Integer.MAX_VALUE/10&&num>Integer.MAX_VALUE%10)){
        //     return Integer.MAX_VALUE;
        // }
        // if(res < Integer.MIN_VALUE/10 || (res == Integer.MIN_VALUE/10&&-num<Integer.MIN_VALUE%10)){
        //     return Integer.MIN_VALUE;
        // }
        
        return sign ? -ans : ans;
    }
};


int main()
{
    Solution s1;
    string str = " ";
    cout << s1.strToInt(str);
    return 0;
}