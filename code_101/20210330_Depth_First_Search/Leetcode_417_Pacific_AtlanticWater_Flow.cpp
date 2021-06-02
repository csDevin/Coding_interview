// L417: Pacific AtlanticWater Flow (Medium)
// 时间复杂度 O(m∗n)，其中m,n 分别为 matrix 的行数和列数。地图上的每个点至多扩展一次。（不确定）
// 空间复杂度 O(m∗n)，其中m,n 分别为 matrix 的行数和列数。（不确定）

#include<bits/stdc++.h>
using namespace std;


// // 结果正确，但超时
// vector<int> dir={-1, 0, 1, 0, -1};

// vector<int> dfs(vector<vector<int>>&heights, int x, int y, vector<vector<int>> &visited)
// {
//     int a=0, b=0;
//     vector<int> temp(2, 0);
//     if(x==0 || y==0)
//         a=1;
//     if(x==heights.size()-1 || y==heights[0].size()-1)
//         b=1;
//     if(a==1&&b==1)
//         return {1, 1};
//     for(int i=0; i<4; i++)
//     {
//         if(x+dir[i]<0 || x+dir[i]>heights.size()-1 || y+dir[i+1]<0 || y+dir[i+1]>heights[0].size()-1)
//         continue;
//         if(visited[x+dir[i]][y+dir[i+1]]==0 && heights[x+dir[i]][y+dir[i+1]] <= heights[x][y])
//         {
//             visited[x][y]=1;
//             temp = dfs(heights, x+dir[i], y+dir[i+1], visited);
//             a = max(a, temp[0]);
//             b = max(b, temp[1]);
//             visited[x][y]=0;
//         }     
//     }
//     return {a, b};  //***直接return{a, b}干了很多重复劳动，比如a和b的初始化等-，导致超时，应该将a和b写到数组里面。
// }

// vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//     int xLen=heights.size();
//     int yLen=heights[0].size();
//     // vector<vector<int>>& pacific(xLen, vector(yLen, 0));
//     vector<vector<int>> visited(xLen, vector<int> (yLen, 0));  //***忘记加<int>了
//     vector<vector<int>> result;
//     for(int i=0; i<xLen; i++)
//     {
//         for(int j=0; j<yLen; j++)
//         {
//             visited[i][j]=1;
//             vector<int> vec = dfs(heights, i, j, visited);
//             visited[i][j]=0;
//             if(vec[0]==1 && vec[1]==1)
//                 result.push_back({i, j});
//         }
//     }
//     return result;
// }







// 优化后代码
// // 执行结果：通过
// // 执行用时：1500 ms, 在所有 C++ 提交中击败了5.17%的用户
// // 内存消耗：139.3 MB, 在所有 C++ 提交中击败了5.04%的用户
// vector<int> dir={-1, 0, 1, 0, -1};
// vector<int> dfs(vector<vector<int>>&heights, int x, int y, vector<vector<int>> &visited, vector<vector<int>> &a, vector<vector<int>> &b)
// {
//     // if(a[x][y]!=-1)  //***因为dfs是带visited的条件访问，单个点的中间搜索结果在每次遍历的时候并不一定相同。
//     //     return {a[x][y], b[x][y]};
//     // a[x][y]=0, b[x][y]=0;
//     vector<int> temp(2, 0);
//     if(x==0 || y==0)
//         a[x][y]=1;
//     if(x==heights.size()-1 || y==heights[0].size()-1)
//         b[x][y]=1;
//     if(a[x][y]==1&&b[x][y]==1)
//         return {1, 1};
//     for(int i=0; i<4; i++)
//     {
//         if(x+dir[i]<0 || x+dir[i]>heights.size()-1 || y+dir[i+1]<0 || y+dir[i+1]>heights[0].size()-1)
//         continue;
//         if(visited[x+dir[i]][y+dir[i+1]]==0 && heights[x+dir[i]][y+dir[i+1]] <= heights[x][y])
//         {
//             visited[x][y]=1;
//             temp = dfs(heights, x+dir[i], y+dir[i+1], visited, a, b);
//             a[x][y] = max(a[x][y], temp[0]);
//             b[x][y] = max(b[x][y], temp[1]);
//             visited[x][y]=0;
//         }     
//     }
//     return {a[x][y], b[x][y]};
// }

// vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//     int xLen=heights.size();
//     int yLen=heights[0].size();
//     // vector<vector<int>>& pacific(xLen, vector(yLen, 0));
//     vector<vector<int>> visited(xLen, vector<int> (yLen, 0));  //***忘记加<int>了
//     vector<vector<int>> result;
//     vector<vector<int>> a(xLen, vector<int>(yLen));
//     vector<vector<int>> b(xLen, vector<int>(yLen));
//     for(int i=0; i<xLen; i++)
//     {
//         for(int j=0; j<yLen; j++)
//         {
//             visited[i][j]=1;
//             vector<int> vec = dfs(heights, i, j, visited, a, b);
//             visited[i][j]=0;
//             if(vec[0]==1 && vec[1]==1)
//                 result.push_back({i, j});
//         }
//     }
//     return result;
// }



// 逆向查找，海洋到大陆
vector<int> dir={-1, 0, 1, 0, -1};
void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, vector<vector<int>>& record, int x, int y)
{
    record[x][y] = 1;
    visited[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int x_new = x+dir[i];
        int y_new = y+dir[i+1];
        if(x_new<0 || y_new<0 || x_new>heights.size()-1 || y_new>heights[0].size()-1)
            continue;
        if(visited[x_new][y_new]==0 && heights[x][y]<=heights[x_new][y_new])
        {
            dfs(heights, visited, record, x_new, y_new);
        }
    }
    return;
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int xLen = heights.size();
    int yLen = heights[0].size();
    vector<vector<int>> visited_pac(xLen, vector<int>(yLen));  //***vector<int>写成了vector
    //***error: no viable constructor or deduction guide for deduction of template arguments of 'vector'
    vector<vector<int>> visited_atl(xLen, vector<int>(yLen));
    vector<vector<int>> record_pac(xLen, vector<int>(yLen));
    vector<vector<int>> record_atl(xLen, vector<int>(yLen));
    vector<vector<int>> result;
    for(int i=0; i<xLen; i++)
    {
        dfs(heights, visited_pac, record_pac, i, 0);  // pac
        dfs(heights, visited_atl, record_atl, i, yLen-1);
    }
    for(int j=0; j<yLen; j++)
    {
        dfs(heights, visited_pac, record_pac, 0, j);  // pac
        dfs(heights, visited_atl, record_atl, xLen-1, j);
    }

    for(int i=0; i<xLen; i++)
        for(int j=0; j<yLen; j++)
            if(record_pac[i][j]==1 && record_atl[i][j]==1)
                result.push_back({i, j});
    return result;
}


int main(){
    vector<vector<int>> vec = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, {44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 13}, {43, 80, 81, 82, 83, 84, 85, 86, 87, 88, 55, 14}, {42, 79, 108, 109, 110, 111, 112, 113, 114, 89, 56, 15}, {41, 78, 107, 128, 129, 130, 131, 132, 115, 90, 57, 16}, {40, 77, 106, 127, 140, 141, 142, 133, 116, 91, 58, 17}, {39, 76, 105, 126, 139, 144, 143, 134, 117, 92, 59, 18}, {38, 75, 104, 125, 138, 137, 136, 135, 118, 93, 60, 19}, {37, 74, 103, 124, 123, 122, 121, 120, 119, 94, 61, 20}, {36, 73, 102, 101, 100, 99, 98, 97, 96, 95, 62, 21}, {35, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 22}, {34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23}};
    // vector<vector<int>> vec = {{0, 4},
    // {1, 3},
    // {1, 4},
    // {2, 2},
    // {3, 0},
    // {3, 1},
    // {4, 0}};
    vector<vector<int>> result;
    result = pacificAtlantic(vec);
    int a = 2;
    return 0;
}