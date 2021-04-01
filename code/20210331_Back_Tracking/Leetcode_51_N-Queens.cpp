// L51: N-Queens (Hard)
// 时间复杂度：
// 空间复杂度：


// 回溯法
// 关键问题：如何判断第n行的第i个位置是否与上面几行的任何一个皇后冲突，列冲突还好判断（使用一个01数组记录），对角线冲突很难判断。
// 使用三个集合进行判断
// auto columns = unordered_set<int>();  // 判断当前列是否使用，范围为[0,n-1]
// auto diagonals1 = unordered_set<int>();  // 判断与左对角线平行的斜线，同一左斜线的差值为唯一定值，从左到右的范围是n-1到 -(n-1);
// auto diagonals2 = unordered_set<int>();  // 判断与右对角线平行的斜线，同一右斜线的和为唯一定值，从左到右的范围是0到2(n-1);


void dfs(int n, int line, int x, unordered_set<int>& col, unordered_set<int>& diag1, unordered_set<int>& diag2, vector<string>& temp, vector<vector<string>>& result)
{
    if(col.count(x)==1 || diag1.count(line-x)==1 || diag2.count(line+x)==1)
        return;
    temp[line][x] = 'Q';
    if(line == n-1)
    {
        result.push_back(temp);
    }
    col.insert(x);
    diag1.insert(line-x);
    diag2.insert(line+x);
    for(int i=0; i<n; i++)
    {
        dfs(n, line+1, i, col, diag1, diag2, temp, result);
    }
    temp[line][x] = '.';
    col.erase(x);
    diag1.erase(line-x);
    diag2.erase(line+x);
    return;
}

vector<vector<string>> solveNQueens(int n) {
    unordered_set<int> col, diag1, diag2;
    vector<string> temp(n, string(n, '.'));
    vector<vector<string>> result;
    for(int i=0; i<n; i++)
    {
        dfs(n, 0, i, col, diag1, diag2, temp, result);
    }
    return result;
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> col, diag2;
    vector<int> diag1;
    vector<string> s(3, string(10, 'c'));
    // s.insert(0, 10, 'c');
    // cout << s;

    int aaa = 0;
}