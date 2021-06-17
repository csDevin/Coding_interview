#include<bits/stdc++.h>
using namespace std;

// 本题有防溢出判断，当前仅当反转后的数字: INT_MIN/10<=rev<=INT_MAX/10的时候，才可以继续推入各位数字，当rev==INT_MIN/10或INT_MAX/10的时候，
// 说明仅仅剩下最后一位数字，因为输入数据需要满足带符号32位整数，所以最后一位数一定在{0,1,2}之间的，<7，所以INT_MIN/10<=rev<=INT_MAX/10的时候，
// rev一定可以再推入数字。
// int逆序：可以int转str然后使用*10+i的循环生成逆序int
class Solution {
public:
    /* 特殊情况
    1534236469 -> 966324351 个位数特别大，超过了2
    */
    stringstream ss;
    string str;
    int reverse(int x) {
        // if(x==INT_MIN+1)  //***错误，这道题不是正负转换，而是同符号数的逆序，不存在你说的这两种情况，你这是顺序+取负数
        //     return INT_MAX;
        // if(x==INT_MAX)
        //     return INT_MIN+1;        
        int x1;
        ss << x;
        ss >> str;
        std::reverse(str.begin(), str.end());
        ss.clear();
        ss << str;
        ss >> x1;
        if(x1==INT_MAX || x1==INT_MIN)  //***如果str超过了32位有符号整数范围，则stringstream转换后的整数为INT_MAX或者INT_MIN
            return 0;
        if(x<0)
            x1 *= -1;
        return x1;
    }
};