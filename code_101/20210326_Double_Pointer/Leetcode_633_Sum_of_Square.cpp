// 题目：（Easy）
// 时间复杂度：O(√c)，根号c的时间复杂度，其中枚举left的时间复杂度为，一次线性扫描扫描√c次
// 空间复杂度：O(1)，没有额外存储空间
# include<algorithm>
# include<iostream>
# include<cmath>
using namespace std;

// 自己的代码：击败7%，使用cmath的fmod(a, b)
bool judgeSquareSum(int c) {
    int left=0;  // long left=0;
    double right=0;
    while(left<=sqrt(c))  // while(left*left<=c)
    {
        right = sqrt(c-pow(left,2));
        if(fmod(right,1)==0)
            return true;
        left++;
    }
    return false;
}

// 自己的代码：击败50%，使用right==int(right);
bool judgeSquareSum1(int c) {
    int left=0;
    double right=0;
    while(left<=sqrt(c))
    {
        right = sqrt(c-pow(left,2));
        if(right==(int)right)
            return true;
        left++;
    }
    return false;
}

int main()
{
    double a = 3.212125;
    cout << (int)a<<" "<<int(a)<< " "<<a;
    return 0;
}