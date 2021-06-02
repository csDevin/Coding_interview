// L215: Kth Largest Element in an Array (Medium)
// 时间复杂度：平均情况下O(n)，最坏情况下O(n^2)
// 空间复杂度：O(1)

#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
    return;
}

// int partition(vector<int> &nums, int left, int right)  // 单向扫描版本，pivot为nums[r]
// // 枢轴pivot为最后一个区间元素。j从前往后扫描，不包括枢轴，如果遇到小于枢轴的值，则将其放到前面去（i++），
// // 当j扫描完时，完成最后一次交换，swap(nums[r], nums[i])
// {
//     int pivot_index = right;
//     int pivot = nums[pivot_index];  //***枢轴写成了索引，应该是一个数值
//     int i = left-1;  //***哨兵i初始化成了i=-1;
//     for (int j = left; j < right; j++) //***j初始化成了j=0;
//     {
//         if(nums[j] < pivot && i!=j)
//             swap(nums[++i], nums[j]);
//     }
//     swap(nums[++i], nums[right]);  //***此处为什么要写++i
//     return i;
// }

int partition(vector<int> &nums, int l, int r)  // 单向扫描版本，pivot为nums[l]
//***nums忘了加引用
{
    int i=l;
    int pivot = nums[l];
    for(int j=l+1; j<=r; j++)  //***分号写成了逗号
    {
        if(nums[j] < pivot)  //***小于写成了大于，j应该是遇到大的continue，遇到小的放到前面去
        {
            swap(nums[++i], nums[j]);
        }
    }
    swap(nums[l], nums[i]);  //***nums[i]写成了i-1
    return i;
}


int quick_select(vector<int> &nums, int left, int right, int index)
//***nums忘了加引用
{
    int j = partition(nums, left, right);
    if(j==index)
        return nums[j];
    else if(j<index)
    {
        return quick_select(nums, j+1, right, index);
    }
    else
        return quick_select(nums, left, j-1, index);
}

int findKthLargest(vector<int>& nums, int k) {
    //***把main()函数写到这里了
    //***忘记写quick_select函数了，居然直接递归调用partition函数了
    int nLen = nums.size();
    int left=0, right=nLen-1;  //***right=nums.size()-1写成了right=nums.size()
    return quick_select(nums, left, right, nLen-k);  //***nLen-k写成了k
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec = {7, 6, 5, 4, 3, 2, 14};
    int a = 2;
    cout<<findKthLargest(vec, a);
    return 0;
}