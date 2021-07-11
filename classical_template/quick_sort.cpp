#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
    return;
}

int partition(vector<int> &nums, int l, int r)  // 单向扫描版本，pivot为nums[l]
//***nums忘了加引用
{
    int i=l;
    int pivot = nums[l];
    for(int j=l+1; j<=r; j++)  //***分号写成了逗号
    {
        if(nums[j] < pivot)  //***小于写成了大于，j应该是遇到大的continue，遇到小的放到前面去
        {
            swap(nums[++i], nums[j]);  // 这里的++i写的妙
        }
    }
    swap(nums[l], nums[i]);  //***nums[i]写成了i-1
    return i;
}


void quick_sort(vector<int> &nums, int left, int right)
{
    //!!!快速选择转换为快速排序的关键一步，删除下面的if(j==index) return nums[j];，改成if(left>=right) return;
    if(left>=right)  //***quick_sort的停止条件写成了left==right，left始终增加陷入了死循环
        return;
    int j = partition(nums, left, right);
    // if(j==index)
    //     return nums[j];
    quick_sort(nums, j+1, right);
    quick_sort(nums, left, j-1);
    return;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec = {99};
    int a = 2;
    int nLen = vec.size();
    int left=0, right=nLen-1;
    quick_sort(vec, left, right);
    return 0;
}