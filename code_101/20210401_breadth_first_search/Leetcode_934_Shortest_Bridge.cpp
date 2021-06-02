// 934: Shortest Bridge (Medium)
#include<queue>
#include<map>
#include<iostream>
using namespace std;


vector<int> dir={-1, 0, 1, 0, -1};
// dfs
void dfs(vector<vector<int>>& A, int x, int y, queue<pair<int, int>>& points)
{
    A[x][y] = 2;
    points.emplace(x, y);
    for(int i=0; i<4; i++)
    {
        int x_new = x+dir[i];
        int y_new = y+dir[i+1];
        if(x_new<0 || y_new<0 || x_new>=A.size() || y_new>=A[0].size())  // 越界
            continue;
        if(A[x_new][y_new]==1)
            dfs(A, x_new, y_new, points);
    }
    return;
}

// 主函数
int shortestBridge(vector<vector<int>>& A) {
    int xLen=A.size();
    int yLen=A[0].size();
    bool flag = false;
    queue<pair<int, int>> points;
    for(int i=0; i<xLen; i++)
    {
        if(flag==true)  //***忘记跳出双重for循环，需要使用flag
            break;
        for(int j=0; j<yLen; j++)
        {
            if(A[i][j]==1)
            {
                dfs(A, i, j, points);
                flag = true;
                break;  //***break无法跳出双重for循环
            }
        }
    }
    // while(!points.empty())
    // {
    //     cout<<points.front().first<<" "<<points.front().second<<endl;
    //     points.pop();
    // }
    // cout<<points.empty();
    // cout<<A[1][4];

    // bfs
    int steps=-1;
    while(!points.empty())
    {
        steps++;  // 正在第step步幅内寻找岛屿
        int q_size = points.size();
        // cout<<q_size<<endl;
        // points.pop();  //***pop放错地方了，应该是一个元素四个方向找完后，立即pop，然后找另一个元素的四个方向
        while(q_size!=0)
        {
            q_size--;
            pair<int, int> curr = points.front();
            points.pop();  //***pop放错地方了，应该是一个元素四个方向找完后，立即pop，然后找另一个元素的四个方向
            for(int i=0; i<4; i++)
            {
                int x_new = curr.first+dir[i];
                int y_new = curr.second+dir[i+1];
                if(x_new<0 || y_new<0 || x_new>=A.size() || y_new>=A[0].size())  // 越界
                    continue;
                if(A[x_new][y_new]==2)
                    continue;
                else if(A[x_new][y_new]==1)
                    return steps;                    
                else
                {
                    points.emplace(x_new, y_new);
                    A[x_new][y_new] = 2;
                }
            }
            
        }
    }
    return steps;
}


int main()
{
    queue<pair<int, int>> q;
    pair<int, int> x = {1, 2};
    q.emplace(x);
    q.emplace(3,4);
    q.emplace(7, 8);
    q.pop();
    cout << q.back().first;
    int a = 0;
    return 0;
}