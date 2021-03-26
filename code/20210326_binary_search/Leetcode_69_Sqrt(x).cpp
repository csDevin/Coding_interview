// Sqrt(x) (Easy)
/*
定义ans变量，当mid*mid<=x时，记录ans=mid，并且right左移；
否则，left右移。
*/
#include<iostream>
using namespace std;

int mySqrt(int x) {
    int left=0;
    long long right=(long long)x+1;
    long long mid=0;  // 左闭右开
    int ans=0;
    while(left<right)
    {
        mid=left+(right-left)/2;
        if(mid*mid<=x)
        {
            ans=mid;
            left = mid+1;
        }
        else
            right = mid;
    }
    return ans;
}

int main()
{
    int x = INT_MAX;
    long long right = (unsigned int)x + 1;
    cout << right;
    return 0;
}