/* solution 1: dp
https://leetcode-cn.com/problems/integer-break/solution/zheng-shu-chai-fen-by-leetcode-solution/
其中dp[i]表示将正整数 i 拆分成至少两个正整数的和之后，这些正整数的最大乘积。特别地，0 不是正整数，1 是最小的正整数，0 和 1 都不能拆分，
因此 dp[0]=dp[1]=0。
当 i≥2 时，假设对正整数 i 拆分出的第一个正整数是 (1≤j<i），则有以下两种方案：
将 i 拆分成 j 和 i−j 的和，且 i−j 不再拆分成多个正整数，此时的乘积是 j×(i−j)；
将 i 拆分成 j 和 i−j 的和，且 i−j 继续拆分成多个正整数，此时的乘积是 j×dp[i−j]。
状态转移方程：
dp[i] = max{i*(i-j), j*dp[i-j]} (1<=j<=i)
*/

class Solution {
public:
    // 状态转移方程dp[i]表示长度为i的绳子至少分成两段的最大乘积
    // 虽然越界，但是可以假设，dp[0]=0, dp[1]=0
    // i代表绳子长度，j代表i减去一次的长度，1<=j<=i
    // dp[i] = max(j*(i-j), j*dp[i-j]) (1<=j<i)
    int cutRope(int number) {
        vector<int> dp(number+1);  // 需要加一，因为下标与长度相对应
        //***写成了dp[number]
        for(int i=2; i<=number; i++){  //***写成了i<number
            int curMax = INT_MIN;
            for(int j=1; j<i; j++){
//                 dp[i] = max(j*(i-j), j*dp[i-j]);
                   //***错误写法1，dp[i]等于长度[1,i)范围中多种剪断中的最大值
//                 curMax = max(j*(i-j), j*dp[i-j]);  //***错误写法2，为达成目标
                curMax = max(curMax, max(j*(i-j), j*dp[i-j]));
            }
            dp[i] = curMax;
        }
        return dp[number];
    }
};



/* solution 1: mathematical analysis (Greedy)
如果 n == 2，返回1，如果 n == 3，返回2，两个可以合并成n小于4的时候返回n - 1
如果 n == 4，返回4
如果 n > 4，分成尽可能多的长度为3的小段，每次循环长度n减去3，乘积res乘以3；最后返回时乘以小于等于4的最后一小段
以上2和3可以合并
*/

class Solution {
public:
    int cutRope(int number) {
        if(number < 4)
            return number - 1;
        if(number == 4)
            return 4;
        int res = 1;
        while(number > 4){
            res *= 3;
            number -= 3;
        }
        return res * number;
    }
};