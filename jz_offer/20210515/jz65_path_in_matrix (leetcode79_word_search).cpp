#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
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
    
    bool hasPath(vector<vector<char> >& board, string word) {
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
};