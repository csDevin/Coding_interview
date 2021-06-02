#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iostream>  //***忘记写iostream了
using namespace std;

// 自己的代码(双指针从前往后，并且没有利用额外空间)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // special
    if(m==0)
    {
        nums1 = nums2;  // 忘记加这一行了，否则将会返回一个空数组而不是返回nums2
        return;  //***void函数不需要return
    }
        
    if(n==0)  //***写成了(n)==0)
        return;

    nums1[m] = 1e9+1;  // 在nums1最后一个数后面插入一个极大数，便于排序(每插入一个数popback一次)
    int i=0, j=0;
    if(nums1[i] > nums2[j])  // 他是下面while情况的特例，所以操作应该一致，也要有pop_back()
    {
        nums1.insert(nums1.begin(), nums2[0]);
        nums1.pop_back();  //***忘记加pop_back()
        j++;
    }
    while(j<n)
    {
        if(nums1[i] <= nums2[j] && nums2[j] <= nums1[i+1])
        {
            nums1.insert(nums1.begin()+i+1, nums2[j]);
            nums1.pop_back();
            j++;
        }
        i++;
    }
    return;
}

// another code：双指针从前往后，使用额外空间存储nums1(使用vec.insert(pos,begin,end)方法)



// better code：双指针从后往前，不使用额外空间。index索引指针也应该从后往前（我写成了从前往后）
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // special
    if(m==0)
    {
        nums1 = nums2;
        return;
    }
    if(n==0)
        return;
    
    int i=m-1, j=n-1, index=m+n-1;
    while(index>=0)  //***边界错误，index>=0写成了index>0
    {       
        if(i==-1)
        {
            nums1[index] = nums2[j];
            j--;
        }
        else if(j==-1)
        {
            nums1[index] = nums1[i];
            i--;              
        }
        else if(nums1[i]>=nums2[j])  //***>=写成了<=，应该是大的优先
        // else if可以有效避免数组越界问题，把可能越界的情况放在else if前面即可
        {
            nums1[index] = nums1[i];
            i--;
        }
        else
        {
            nums1[index] = nums2[j];
            j--;           
        }
        index--;  // 每一步都有index--则可以放到最后简化代码
    }
    return;
}
// 上述从后往前代码简化版本
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1, j=n-1, index=m+n-1;
    while(index>=0)  //***边界错误，写成了index>0
    {       
        if(i==-1)
            nums1[index--] = nums2[j--];
        else if(j==-1)
            nums1[index--] = nums1[i--];
        else if(nums1[i]>=nums2[j])
            nums1[index--] = nums1[i--];
        else
            nums1[index--] = nums2[j--];
    }
    return;
}



// simplest code：用nums2填满nums1然后sort。
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int j=0, index=m;
    while(j<n)
    {
        nums1[m++] = nums2[j++];
    }
    sort(nums1.begin(), nums1.end());
    return;
}


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> nums3;
    nums3.insert(nums3.begin(), nums1.begin(), nums1.begin()+m);  //***nums3应该copy nums1写成了nums2
    int index=0;
    int i=0, j=0;
    while(i<n || j<m)
    {
        if(i==n)  //***这里写成了i==-1，正序扫描i++应该写成n
            nums1[index++] = nums3[j++];
        else if(j==m)
            nums1[index++] = nums2[i++];
        else if(nums2[i]<=nums3[j])
            nums1[index++] = nums2[i++];
        else
            nums1[index++] = nums3[j++];
    }
    return;
}


int main()
{
    vector<int> a = {2, 0};
    vector<int> b = {1};
    int m = 1, n = 1;
    merge(a, m, b, n);
    cout << a[0] << " " << a[1] << endl;
    return 0;
}