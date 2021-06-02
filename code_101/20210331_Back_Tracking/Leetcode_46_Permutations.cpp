// L46: Permutations (Medium) 全排列的结果是n!
// 时间复杂度分析
// 1. backtrack（dfs函数） 的调用次数是O(n!)级别的。
// 2. 对于 backtrack 调用的每个叶结点（共 n!个），我们需要将当前答案使用 O(n) 的时间复制到答案数组中，相乘得时间复杂度为 O(n×n!)。
// 因此综合1，2，两者取其小者，时间复杂度为 O(n×n!)。
// 空间复杂度：O(n×n!)，全排列个数n！，每个全排列所占空间为n，结果n*n!

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

// 自己的代码：较为复杂
// 思路：递归深度有且只有nums.size()层，使用一个深度为nums.size()的栈，每次dfs一个元素时，将这个元素压入栈中。
// 当temp存储的元素个数达到nums.size()个时，我们将temp push_back到result中，作为一种排列情况。
// 记住，在此次dfs结束之前需要使用pop_back()函数取出栈顶元素，以便上一层递归去寻找其他可能的答案。
// 回溯法总结：有visited[i]=1,在dfs之后就要有，visited[i]=0；有temp.push_back(nums[x]),就要有temp.popback()。
// 只有这样，才能达到回溯的效果，从而去回到上一层递归的状态！从而可以去寻找其他的可能的结果。
void dfs(vector<int>& nums, vector<int>& visited, vector<vector<int>>& result, vector<int>& temp, int x)
{
    vector<int> v;
    temp.push_back(nums[x]);  // nums[x]写成了x
    if(temp.size()==nums.size())
    {
        result.push_back(temp);
    }
    for(int i=0; i<nums.size(); i++)  //***此函数中的所有的i全部写成了x！！！
    {
        if(visited[i]==1)
            continue;
        visited[i]=1;
        dfs(nums, visited, result, temp, i);
        visited[i]=0;
    }
    temp.pop_back();  //***只记得要push_back()了，忘记pop_back了
    return;
}

vector<vector<int>> permute(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> result;
    vector<int> visited(len);
    vector<int> temp;
    for(int i=0; i<nums.size(); i++)
    {
        visited[i]=1;
        dfs(nums, visited, result, temp,i);  // 主函数dfs前后没有加visited
        visited[i]=0;
    }
    return result;
}



// better code
// visited + depth + result
// visited记录已经访问过的元素，depth记录当前递归的深度，result记录栈中元素，在此题中depth==result.size()
// 执行结果：通过
// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：7.4 MB, 在所有 C++ 提交中击败了80.59%的用户

void dfs(vector<int>& nums, int x, vector<int>& visited, vector<int>& temp, vector<vector<int>>& result)
{
    temp.push_back(nums[x]);  //***nums[x]写成了x
    if(temp.size() == nums.size())
    {
        result.push_back(temp);
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

vector<vector<int>> permute(vector<int>& nums) {
    int len = nums.size();
    vector<int> visited(len);
    vector<int> temp;
    vector<vector<int>> result;
    
    for(int i=0; i<len; i++)
    {
        visited[i]=1;
        dfs(nums, i, visited, temp, result);
        visited[i]=0;

    }
    return result;
}

int main()
{
    vector<int> vec = {1, 2, 3};
    permute(vec);
    int a = 2;
    return 0;
}