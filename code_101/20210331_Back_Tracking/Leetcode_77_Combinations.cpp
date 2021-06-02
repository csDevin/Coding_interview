// L77: Combinations (Medium)
// 时间复杂度：O((n k)*k),注(n k)为n上，k下，代表从n个选择k个数的复杂度，*k代表存储一次排列的复杂度
// 空间复杂度：O(n+k)=O(n)，即递归使用栈空间的空间代价和临时数组 \rm temptemp 的空间代价。

#include<bits/stdc++.h>
using namespace std;
// 稍显复杂：带visited的写法
void dfs(int n, int k, int i, vector<int>& visited, vector<int>& temp, vector<vector<int>>& result)
{
    temp.push_back(i);
    if(temp.size() == k)  // ==k就应该return不然会导致无用的搜索，如temp.size()>k的搜索。
    {
        result.push_back(temp);
        temp.pop_back();
        return;
    }
    for(int j=i+1; j<=n; j++)
    {
        if(visited[j]==0)
        {
            visited[j]=1;
            dfs(n, k, j, visited, temp, result);
            visited[j]=0;
        }
    }
    temp.pop_back();
    return;
}

vector<vector<int>> combine(int n, int k) {
    vector<int> visited(n+1);
    //***范围是[1, n]左闭右闭的区间，visited(n+1)写成了visited(n)。
    vector<int> temp;        
    vector<vector<int>> result;
    for(int i=1; i<=n; i++)  // 因为是递增序列，无需遍历i=n;
    // 范围是[1, n]左闭右闭的区间，i=1写成了i=0。
    {
        visited[i] = 1;
        dfs(n, k, i, visited, temp, result);
        visited[i] = 0;
    }
    return result;
}





// 代码优化（不带visited的写法）
// 上述代码你去仔细思考是不需要带visited的，因为每次dfs你都选择了i+1到n的数，
// 每次选择都是比i大的数，也就是说i不在选择区间内，也就不存在重复问题。
void dfs(int n, int k, int i, vector<int>& temp, vector<vector<int>>& result)
{
    temp.push_back(i);
    if(temp.size() == k)  // ==k就应该return不然会导致无用的搜索，如temp.size()>k的搜索。
    {
        result.push_back(temp);
        temp.pop_back();
        return;
    }
    for(int j=i+1; j<=n; j++)
        dfs(n, k, j, temp, result);
    temp.pop_back();
    return;
}
vector<vector<int>> combine(int n, int k) {
    vector<int> temp;        
    vector<vector<int>> result;
    for(int i=1; i<=n; i++)  // 因为是递增序列，无需遍历i=n;
    // 范围是[1, n]左闭右闭的区间，i=1写成了i=0。
    dfs(n, k, i, temp, result);
    return result;
}





// 组合型枚举(回溯枚举)（不带visited的写法）
// 思路：对于每一个属于[1,n]的元素i，考虑选择i和不选择i这两种情况，分别递归，直到temp.size()==k;
void dfs(int n, int k, int x, vector<int>& temp, vector<vector<int>>& result)
{
    if(temp.size() == k)  //***应该先判断size==k再判断越界>n，顺序很重要，写反了
    {
        result.push_back(temp);
        return;
    }
    if(x>n)  //***应该先判断size==k再判断越界>n，顺序很重要，写反了
        return;
    temp.push_back(x);
    dfs(n, k, x+1, temp, result);  // 枚举中包含x元素
    temp.pop_back();
    dfs(n, k, x+1, temp, result);  // 枚举中不包含x元素
    return;
}

vector<vector<int>> combine(int n, int k) {
    vector<int> temp;
    vector<vector<int>> result;
    dfs(n, k, 1, temp, result);
    return result;
}

int main()
{
    // vector<int> vec = {1, 2, 3};
    int n = 4, k = 2;
    combine(n, k);
    int a = 2;
    return 0;
}