/* solutions
最后一个存活的人的下标为0，倒数第二轮这个人的下标为(0+m)%2
连续两轮，从后往前下标的递推公式为
某人上一轮的下标 = (某人这一轮的下标 + m)% 这一轮的人数总数
index = (index + m) % len
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if(n==0)
            return -1;
        if(n==1)
            return 0;
        int index = 0;
        for(int len=2; len<=n; len++){
            index = (index + m) % len;
        }
        return index;
    }
};