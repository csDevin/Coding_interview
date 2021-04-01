// 79: Word Search (Medium)
// 时间复杂度：
// 空间复杂度：

// 自己的代码：先判断，符合条件再dfs
#include <bits/stdc++.h>
using namespace std;

vector<int> dir = {-1, 0, 1, 0, -1};
void dfs(vector<vector<char>> &board, string word, vector<vector<int>> &visited, bool &result, int x, int y, int depth)
{
    if (depth == word.size() - 1) //***word.size()-1写成了word.size()
    {
        result = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int x_new = x + dir[i];
        int y_new = y + dir[i + 1];
        if (x_new < 0 || x_new >= board.size() || y_new < 0 || y_new >= board[0].size())
            //***x_new>=board.size()写成了x_new>board.size()
            continue;
        if (visited[x_new][y_new] == 0 && board[x_new][y_new] == word[depth + 1])
        //***visited[x_new][y_new]==0写成了visited[x_new][y_new]=0;
        {
            visited[x_new][y_new] = 1;
            dfs(board, word, visited, result, x_new, y_new, depth + 1);
            visited[x_new][y_new] = 0;
        }
    }
    return;
}
bool exist(vector<vector<char>> &board, string word)
{
    int xLen = board.size();
    int yLen = board[0].size();
    bool result = false;
    vector<vector<int>> visited(xLen, vector<int>(yLen));
    for (int i = 0; i < xLen; i++)
    {
        for (int j = 0; j < yLen; j++)
        {
            if (board[i][j] == word[0])
            {
                visited[i][j] = 1;
                dfs(board, word, visited, result, i, j, 0);
                visited[i][j] = 0;
                if (result == true)
                    return true;
            }
        }
    }
    return false;
}







// another code：先进dfs，进去了再在开头判断是否符合条件，使用多条if
// 主函数
bool exist(vector<vector<char>> &board, string word)
{
    if (board.empty())
        return false;
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    bool find = false;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            backtracking(i, j, board, word, find, visited, 0);
        }
    }
    return find;
}
// 辅函数
void backtracking(int i, int j, vector<vector<char>> &board, string &word, bool &find, vector<vector<bool>> &visited, int pos)
{
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())  // 越界放第一个判断
    {
        return;
    }
    if (visited[i][j] || board[i][j] != word[pos])
    {
        return;
    }
    if (pos == word.size() - 1)
    {
        find = true;
        return;
    }
    visited[i][j] = true; // 修改当前节点状态
    // 递归子节点
    backtracking(i + 1, j, board, word, find, visited, pos + 1);
    backtracking(i - 1, j, board, word, find, visited, pos + 1);
    backtracking(i, j + 1, board, word, find, visited, pos + 1);
    backtracking(i, j - 1, board, word, find, visited, pos + 1);
    visited[i][j] = false; // 回改当前节点状态
}





int main()
{
    vector<vector<char>> board =
        {{'A', 'B', 'C', 'E'},
         {'S', 'F', 'C', 'S'},
         {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    exist(board, word);
    int a = 2;
    return 0;
}