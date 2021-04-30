/* 
难点：f和sp的ij是错位的。f[i][j]==true，对应于s[i-1]和p[j-1]相等的时候+f[i-1][j-1]等于true。


我们用 f[i][j]表示 s 的前 i 个字符与 p 中的前 j 个字符是否能够匹配。在进行状态转移时，
我们考虑 p 的第 j 个字符的匹配情况：
其中 matches(x,y) 判断两个字符是否匹配的辅助函数。只有当 y 是 . 或者 x 和 y 本身相同时，这两个字符才会匹配。


状态转移方程：
f[i][j] = f[i-1][j-1]               p[j-1]!='*' && matches(s[i-1], p[j-1])
f[i][j] = false                     p[j-1]!='*' && !matches(s[i-1], p[j-1]) 

f[i][j] = f[i-1][j] or f[i][j-2]    p[j-1]=='*' && matches(s[i-1], p[j-1-1])
f[i][j] = f[i][j-2]                 p[j-1]=='*' && !matches(s[i-1], p[j-1-1])  // p[j]=='*'并且当前字符c匹配0次
对于matches下标的说明，因为在f[i][j]里，i代表字符串s的前i个字符，j代表字符串p的前j个字符。特别的，当i等于0时，代表空字符。
因为在f[i][j]里单位是个，所以对应到字符串s，p中的时候就变成了i-1和j-1，
对于f[i][j]如果，如果p中第j个元素p[j-1]为'*'时，并且p中第j-1个元素p[j-2]与s中第i个元素s[i-1]不匹配，即if(p[j-2]!=s[i-2])时,
则f[i][j] = f[i][j-2]


特例

空正则
true: 空串和空正则是匹配的，f[0][0] = truef[0][0]=true
false: 非空串和空正则必不匹配，f[1][0]=...=f[n][0]=falsef[1][0]=...=f[n][0]=false

非空正则，无法判断: 
空串和非空正则，不能直接定义 truetrue 和 falsefalse，必须要计算出来。（比如A=A= '' '' ,B=a*b*c*B=a∗b∗c∗）
非空串和非空正则，那肯定是需要计算的了。

*/



class Solution {
public:
    bool matches(char a, char b){
        if(a==b || b=='.')
            return true;
        return false;
    }
    
    bool isMatch(string s, string p)  {
        int m = s.size();
        int n = p.size();
        
        vector<vector<int>> f(m+1, vector<int>(n+1));
        
        // 特殊情况，对空字符进行匹配
        f[0][0] = true;  //***空串匹配空正则是true
        for(int i=1; i<=m; i++)
            f[i][0] = false;  //***非空串匹配空正则是false
        
        //???i和j代表什么意思，
        // 在f[i][j]里，i代表字符串s的前i个字符，j代表字符串p的前j个字符。特别的，当i等于0时，代表空字符。
        // 因为在f[i][j]里单位是个，所以对应到字符串s，p中的时候就变成了i-1和j-1
        for(int i=0; i<=m; i++){  //???为什么i从0开始，j从1开始
            for(int j=1; j<=n; j++){  // 答：因为非空正则时，无论是否是空串都无法判断
                if(p[j-1] != '*'){
                    // if(i-1>=0 && j-1>=0 && matches(s[i-1], p[j-1]))  //***别忘了matches的时候要判断边界条件
                    if(i-1>=0 && matches(s[i-1], p[j-1]))  // 因为j-1不可能越界，故简化
                        f[i][j] = f[i-1][j-1];
                    else
                        f[i][j] = false;
                }
                else{
                    // if(i-1>=0 && j-2>=0 &&matches(s[i-1], p[j-2]))  //***别忘了matches的时候要判断边界条件
                    if(i-1>=0 &&matches(s[i-1], p[j-2]))  // 因为j-2不可能越界，故简化
                        f[i][j] = (f[i-1][j] || f[i][j-2]);
                    else
                        f[i][j] = f[i][j-2];
                }
            }
        }
        return f[m][n];
    }
};

