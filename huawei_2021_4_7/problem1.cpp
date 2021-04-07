
#include<bits/stdc++.h>
using namespace std;


void dfs(set<string> &mem, map<string, set<string>> &map1, map<string, int> &visited, string p){
    visited[p]=1;
    for(string i: map1[p]){
        if(visited[i]==0){
            dfs(mem, map1, visited, i);
        }
    }
    return;
}


int main(){
    // 读取数据
    int N;
    cin>>N;
    vector<vector<string>> wants(N, vector<string>(2));
    map<string, set<string>> map1;
    set<string> mem;
    int lenx=wants.size();
    int leny=wants[0].size();
    map<string, int> visited;
    for(int i=0; i<lenx; i++){
        for(int j=0; j<2; j++){
            cin>>wants[i][j];
        }
    }
    string temp;
    // 建二维连接矩阵
    for(int i=0; i<lenx; i++){
        for(int j=0; j<2; j++){
            map1[wants[i][0]].insert(wants[i][1]);
            map1[wants[i][1]].insert(wants[i][0]);
            visited[wants[i][0]] = 0;
            mem.insert(wants[i][0]);
        }
    }
    // int x=1;
    // 遍历并标记每个人
    int num=0;
    // for(const string &p:mem){
    //     if(visited[p]==0){
    //         visited[p]=1;
    //         num++;
    //         for(string x:map1[p]){
    //             visited[x]=1;
    //         }
    //     }
    // }
    // cout<<num;
    for(const string &p:mem){
        if(visited[p]==0){
            dfs(mem, map1, visited, p);
            num++;
        }
    }
    cout<<num;
    return 0;
}