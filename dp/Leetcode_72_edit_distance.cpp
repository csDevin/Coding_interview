// 72. 编辑距离
/*
### 计算原理：leetcode72编辑距离

https://leetcode-cn.com/problems/edit-distance/solution/edit-distance-by-ikaruga/

`dp[i][j]`表示word1的第i个字符变换到word2的第j个字符所需要的最少操作数。 `vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));` 二维数组的维度为(word1.size()+1, word2.size()+1)，`dp[0][0]`表示空字符串转化为空字符串的最少操作次数。

`dp[0][j]`的值为j，因为word1此时截取的长度为[0-0]，word2截取的长度为[1-j]，word1转化为word2最少需要插入j次。

`dp[i][0]`的值为i，因为word1此时为[1-i]，word2此时为[0-0]，word1转化为word2最少需要删除i次。

**状态转移方程**

- 相同，无需操作：当`word1[i]==word2[j]`时，`dp[i][j]=dp[i-1][j-1]`

- 插入：i元素与j元素不同，在i元素后面插入一个j元素`dp[i][j]=dp[i][j-1]+1`
- 删除：i元素与j元素不同，我们删除i元素，假设i-1元素与j元素相同`dp[i][j]=dp[i-1][j]+1`
- 替换：i元素与j元素不同，我们替换i元素为j元素`dp[i][j]=dp[i-1][j-1]+1`
*/

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

int minDistance(string word1, string word2) {
    vector<vector<int >> dp(word1.size()+1, vector<int>(word2.size()+1, 0));  //***忘记初始化为0
    int Len1=dp.size();
    int Len2=dp[0].size();
    for(int j=1; j<Len2; j++){
        dp[0][j]=j;
    }
    for(int i=1; i<Len1; i++){
        dp[i][0]=i;
    }
    for(int i=1; i<Len1; i++){
        for(int j=1; j<Len2; j++){
            dp[i][j]=min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
            }
        }
    }
    // return dp[Len1-1][Len2-1];  //***写成了dp[Len1][Len2]导致overbuffer
    return dp.back().back();
}