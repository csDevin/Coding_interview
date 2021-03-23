#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// 自己的代码：最后一个测试样例会超时
// 思路i从0到size-2，j从i到size-1，如果遇到num[j]==target-num[i],则return。
vector<int> twoSum(vector<int>& numbers, int target) {
    int i=0, j;
    for(i=0; i<numbers.size()-1; i++)
        for(j=i+1; j<numbers.size(); j++)  //***忘记j要从i+1开始了，写成了j=i;
        {
            if(numbers[j]==target-numbers[i])
                return {i+1, j+1};
        }
    return {i+1, j+1};
}

// better code：使用find函数，最后一个样例会超时
vector<int> twoSum(vector<int>& numbers, int target) {
    int i=0;
    int index;  //***变量作用域忽略了，导致debug30分钟。
    for(i=0; i<numbers.size()-1; i++)
    {
        vector<int>::iterator iter=find(numbers.begin()+i+1, numbers.end(), target-numbers[i]);
        if(iter!=numbers.end())
        {
            index=distance(numbers.begin(), iter);
            return {i+1,index+1};
        }
    }
    return {i+1,index+1};  //***变量定义成了for循环中的局部变量
}

// best code：使用双指针，一前一后，缩小搜索范围。
vector<int> twoSum(vector<int>& numbers, int target) {
    int i=0, j=numbers.size()-1;
    while(i<j)  //***写成了i>j
    {
        if(numbers[i]+numbers[j]==target)
            return {i+1, j+1};
        else if(numbers[i]+numbers[j]<target)
            i++;
        else
            j--;  //***写成了j++
    }
    return {i+1, j+1};
}

int main()
{
    int b = 3;
    vector<int> a = {2, 7, 11, 15};
    int tar = 9;
    // twoSum_better(a, tar);
    vector<int>::iterator iter = find(a.begin(), a.end(), 11);
    cout << *iter << endl;
    int index = distance(a.begin(), iter);
    cout << &index << endl;
    return 0;
}