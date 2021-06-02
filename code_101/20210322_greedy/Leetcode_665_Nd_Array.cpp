/*
错误思路：直接判断是不是只出现了一次下降。
错误思路：从前往后扫描，当出现了nums[i]>nums[i+1]时，nums[i+1]=nums[i]（提升i+1），因为让nums[i]=nums[i+1]可能更好（降低i）
            所以可以把问题转换为什么点可以提升i+1（即当nums[i-1]>nums[i+1]时），什么点可以降低i（即当nums[i-1]<=nums[i+1]时或i=1时）。
正确思路：从前往后扫描，当出现了nums[i]>nums[i+1]时要分类讨论nums[i-1]，nums[i]，nums[i+1]这三个值之间的关系，确定到底是修改nums[i]还是nums[i+1]，
确保不破坏当前数组的单调性的同时，选择一个更小的值。
*/

#include<vector>
#include<string>
#include<iostream>
#include<numeric>
using namespace std;

// 自己的代码
bool checkPossibility(vector<int>& nums) {
    // 思路中忽略了要修改nums[i]的情况，默认都是修改nums[i+1]，应该改成改大的那个。
    //***忘记考虑，特殊情况能有效防止程序没考虑到的特殊情况，如数组越界等
    if(nums.size()==0 || nums.size()==1 || nums.size()==2)
        return true;
    int flag=1;  //***flag写到for循环里面了
    nums.insert(nums.begin(), min(nums[0], nums[1]));  //***初始位置增加一个元素防止越界，此元素的选择不能干扰到后续算法
    for(int i=1; i<nums.size()-1; i++)
    {   
        if(nums[i]<=nums[i+1])  //***没有考虑i+1越界
            continue;
        else if(flag==1)
        {
            //***当nums[i]>nums[i+1]时，到底修改谁是需要分类考虑的，此时需要判断nums[i-1]和nums[i+1]的大小。
            if(nums[i-1]<=nums[i+1])
            {
                nums[i] = nums[i+1] = min(nums[i], nums[i+1]);
            }
            else if(nums[i-1] > nums[i+1] && nums[i-1]<=nums[i])
                nums[i+1] = nums[i];
            flag=0;  //***单等于号=写成了双等于号==
        }
        else
            return false;
    }
    return true;
}


// better code
bool checkPossibility_better(vector<int>& nums) {
    // 特殊情况
    int count=0;  //***=写成了==
    if(nums.size()==0 || nums.size()==1)
        return true;
    if(nums[0]>nums[1])
    {
        nums[0]=nums[1];
        count++;
    }

    for(int i=1; i<nums.size()-1; i++)
    {
        if(nums[i]<=nums[i+1])
            continue;
        else if(nums[i-1]<=nums[i+1]) //***未考虑等于号，因为此种情况下nums[i]和nums[i+1]的值更小，更优。
        {
            nums[i]=nums[i+1];
            count++;
        }
        else
        {
            nums[i+1]=nums[i];
            count++;
        }
    }
    return count<=1;
}

int main()
{
    vector<int> nums = {4, 2, 3};
    cout<<checkPossibility(nums);
    return 0;
}