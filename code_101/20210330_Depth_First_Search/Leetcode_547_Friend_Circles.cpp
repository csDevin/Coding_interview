// 547: Friend Circles (Medium)
// 547: Friend Circles (Medium)

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&isConnected, vector<int>&visited, int x)
{
    int m=isConnected.size();
    int n=isConnected[0].size();
    visited[x]=1;
    // for(int i=0; i<m; i++)  //***多加了for(int i=0; i<m; i++)这一层外循环
                            //***此时搜索的x这个省份的相邻省份，不需要遍历所有省份再找其邻接点
    for(int j=0; j<n; j++)
    {
        if(x==j)
            continue;
        if(isConnected[x][j]==1 && visited[j]==0)  //***visited[j]==0写成了visited[i]==0
            dfs(isConnected, visited, j);
    }
    return;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int x=isConnected.size();
    int y=isConnected[0].size();
    int provinces=0;
    vector<int> visited(x, 0);
    for(int i=0; i<x; i++)
    {
        if(visited[i]==0)
        {
            dfs(isConnected, visited, i);
            provinces++;
        }
    }
    return provinces;
}

int main()
{
    vector<vector<int>> vec{{1,1,0},{1,1,0},{0,0,1}};
    cout<<findCircleNum(vec);
    int a=1;
    return 0;
}