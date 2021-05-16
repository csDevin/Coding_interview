/* dfs and backtracking
dfs: only need to count
backtracking: the order of the count is needed
*/

/* template 1: permutations
leetcode46, leetcode47, jz27 (string)
*/
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        vector<int> visited(len);
        vector<int> temp;
        set<vector<int>> result;
        vector<vector<int>> result1;
        
        for(int i=0; i<len; i++)
        {
            visited[i]=1;
            dfs(nums, i, visited, temp, result);
            visited[i]=0;

        }
        result1.assign(result.begin(), result.end());
        return result1;
    }

    void dfs(vector<int>& nums, int x, vector<int>& visited, vector<int>& temp, set<vector<int>>& result)
    {
        temp.push_back(nums[x]);  //***nums[x]写成了x
        if(temp.size() == nums.size())
        {
            result.insert(temp);
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                dfs(nums, i, visited, temp, result);
                visited[i]=0;
            }  
        }
        temp.pop_back();
        return;
    }
};
