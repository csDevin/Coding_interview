/* solutions
对于一个数字可以分为:
若干空格 + [“+-”号 + 无符号整数 + 小数点'.' + 无符号整数] + [e/E + “+-”号 + 无符号整数]
    //1、小数点前面可以没有整数部分，如 .123
    //2、小数点后面可以没有数字，如 233.
    //3、小数点前后可以都有数字，如 233.123
    // e的前后必须有数字
    // 1、当e或E前面没有数字时，整个字符串不能表示数字，如 .e1、e1；
    // 2、当e或E后面没有整数时，整个字符串不能表示数字，如 12e、12e+5.4

两个变量：
index：记录当前扫描到了哪一个字符
numeric：扫描道当前字符为止，前面的所有字符组成的是否是一个数字

两个函数：
(1) scanInterger(s)用于扫描带'+', '-'符号的整数，扫描完成后index到达整数末尾
(2) scanUnsignedInterger(s)用于扫描无符号的整数，扫描完成后index到达整数末尾
注：scanInterger(s) = scan('+', '-') + scanUnsignedInterger(s)

终止条件：
if(numeric && (index == s.size()))
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int index = 0;
    bool isNumber(string s) {
        if(s.empty())
            return false;
        
        // 用index去掉字符串头部的空格
        while(s[index]==' ')
            index++;
        
        // 使用scanInterger扫描小数点前面整数部分
        bool numeric = scanInterger(s);
        // cout<<numeric;

        // 如果有小数点，扫描小数部分
        if(s[index] == '.'){
            ++index;
            numeric = scanUnsignedInterger(s) || numeric;
            //***错误写法，numeric || scanUnsignedInterger(s);numeric写在前面，导致scanInterger(s)不执行，被短路了，故与运算或运算不满足交换律。
        }
        cout<<index;

        // 如果有e/E，扫描指数部分
        if(s[index] == 'e' || s[index] == 'E'){
            index++;
            numeric = scanInterger(s) && numeric;
            //***错误写法，numeric = numeric && scanInterger(s);numeric写在前面，导致scanInterger(s)不执行，被短路了，故与运算或运算不满足交换律。
        }

        // 用index去掉字符串尾部空格
        while(s[index] == ' '){
            index++;
        }
        
        return numeric && (index == s.size());
    }

private:
    bool scanInterger(string s){
        if(s[index]=='+' || s[index]=='-')
            index++;
        return scanUnsignedInterger(s);
    }

    bool scanUnsignedInterger(string s){
        int previous = index;
        while(index != s.size() && s[index]>='0' && s[index]<='9'){  //***忘记判断越界index != s.size()
            index++;
        }
        return index > previous;
    }
};