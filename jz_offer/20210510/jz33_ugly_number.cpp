/* solution 1: dp
a, b, c分别记录当前*2，*3，*5已经分别乘到dp中的哪个元素了，因为dp中任何一个元素*2,*3,*5都是一个丑数。
dp[0] = 1; // 1是第一个丑数
*/
class Solution {
public:
    int GetUglyNumber_Solution(int n) {
        int a=0, b=0, c=0;  // 记录当前*2，*3，*5已经分别乘到dp中的哪个元素了，因为dp中任何一个元素*2,*3,*5都是一个丑数。
        int n2, n3, n5;  // 记录*2，*3，*5对应的下一个值。
        vector<int> dp(n+1);  //***写成了dp(n)为什么会报数组越界？牛客网bug，（报数组越界就把数组开大点，总没错）
        dp[0] = 1;
        for(int i=1; i<n; i++){
            n2 = dp[a]*2;
            n3 = dp[b]*3;
            n5 = dp[c]*5;
            dp[i] = min(min(n2, n3), n5);
            if(dp[i] == n2)
                a++;
            if(dp[i] == n3)
                b++;
            if(dp[i] == n5)
                c++;
        }
        return dp[n-1];
    }
};