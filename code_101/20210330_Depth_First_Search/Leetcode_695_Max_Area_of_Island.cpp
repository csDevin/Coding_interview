// L695: Max Area of Island (Easy)
// 时间复杂度：O(R×C)。其中 R 是给定网格中的行数，C 是列数。我们访问每个网格最多一次。
// 空间复杂度：O(R×C)，递归的深度最大可能是整个网格的大小，因此最大可能使用 O(R×C) 的栈空间。

#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& grid, int x, int y)  // 计算当前点(x, y)所在的岛屿的陆地有多少个点
{
    int m = grid.size();  // 长
    int n = grid[0].size();  // 宽
    if(x<0 || x>m-1 || y<0 || y>n-1 || grid[x][y]==0)
        return 0;
    else
    {
        grid[x][y] = 0;
        int points = dfs(grid, x-1, y)+dfs(grid, x, y-1)+dfs(grid, x, y+1)+dfs(grid, x+1, y)+1;
        grid[x][y] = 1;  // 为什么不要恢复成1
        // 为了避免多次访问同一个土地的问题，当扫描同一个岛屿的时候，B土地(为正方形顶角)
        // 当正方形ABCD四点均为陆地时，在A和C(两条边)土地之间，B土地将会被A和C土地分别计算一次（A置0时，C置1，A认为B连了两个，
        // C也认为B连了两个，B被算了两次），所以当计算D点时候，统计A和B的连接点个数，这种情况下会重复计算同一片土地。
        // 1 1 1
        // 1 1 0
        if(points==9)
            cout << x << " " << y << " "<<endl;
        return points;
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int h=grid.size(), w=grid[0].size();
    int result=0;
    for(int i=0; i<h; i++)  //***为了匹配xy坐标轴的可视化，将w作为了x，h作为了y。为什么不能i指向w，j指向h？
    // 因为grid[w, h]会将很二维数组的一二维坐标颠倒，导致越界问题。所以，ij要匹配grid的第一维和第二维的尺寸。
    {
        for(int j=0; j<w; j++)
        {
            if(grid[i][j]==1)
            {
                result = max(result, dfs(grid, i, j));                    
            }

        }
    }
    return result;        
}

int main()
{
    vector<vector<int>> vec =
        {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
         {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
         {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout<<maxAreaOfIsland(vec);
    int a = 2;
    return 0;
}