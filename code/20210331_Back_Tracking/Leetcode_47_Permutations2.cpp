#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

/* solutions 1
对于不能包含重复结果的全排列，我们在不包含重复输入元素代码的基础上，将中间结果插入到result1中保存（set<vector<int>> result1），最后再将result1转化成vector result2
（result2.assign(result1.begin(), result1.end())）。
*/
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

