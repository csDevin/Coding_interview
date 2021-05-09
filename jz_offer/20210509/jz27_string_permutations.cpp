#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string s) {
        int len = s.size();
        vector<int> visited(len, 0);
        string tmp;
        set<string> res;
        for(int i=0; i<len; i++){
            visited[i] = 1;
            dfs(s, i, visited, tmp, res);
            visited[i] = 0;
        }
        vector<string> res1(res.begin(), res.end());
        return res1;
    }
    
    void dfs(string &s, int x, vector<int> &visited, string &tmp, set<string> &res){  //***1. 忘记加&
        tmp.push_back(s[x]);  //***2. 要先push_back再判断，假如剩下全排列的最后一个元素，当先判断时，会少一个元素，然后push_back
                              // 后会满足条件，但是此时本次递归已经结束了，res并没有把tmp给加入进去，所以最后得到一个空结果。
        int len = s.size();
        if(len == tmp.size()){
            res.insert(tmp);
        }
        for(int i=0; i<len; i++){
            if(visited[i] == 0){  //***3. ==写成了=
                visited[i] = 1;
                dfs(s, i, visited, tmp, res);
                visited[i] = 0;                
            }            
        }
        tmp.pop_back();
    }
};