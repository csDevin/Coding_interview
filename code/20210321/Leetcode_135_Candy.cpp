#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 问题1：右规则为什么一定要逆向扫描？左规则为什么一定要正向扫描？
// 答：右规则是先确定i+1的值再确定i的值，所以适用于从右向左递推，左规则反之。
// 左规则(i大于左手边i-1,则i要比i-1多一个糖果)，右规则(i大于右手边i+1,则i要比i+1多一个糖果)
// 左规则：从左往右扫描，对于i-1和i，只改变右边i的值（只管ratings[i-1]<ratings[i]的情况,>的情况由右规则来管），形成递推效果。
// 右规则：从右向左扫描，对于i和i+1，只改变左边i的值（只管rating[i]>rating[i+1]的情况，因为rating[i]<rating[i+1]的情况左规则已经确保rating[i+1]更大了）。

// 自己的代码
int candy(vector<int>& ratings) {
    // 初始化为1，并且从前往后扫描，左右满足即可。
    vector<int>divid(ratings.size(), 1);
    
    for(int i=0; i < ratings.size()-1; i++)  // 正向扫描，即考虑了ratings[i-1]<ratings[i]又考虑了ratings[i-1]>ratings[i],其实只需要考虑前者
    {
        if(ratings[i] < ratings[i+1] && divid[i] >= divid[i+1])
            divid[i+1]=divid[i]+1;
        if(ratings[i] > ratings[i+1] && divid[i] <= divid[i+1])
            divid[i]=divid[i+1]+1;
    }
    for(int i=0; i < ratings.size()-1; i++)  // 逆向扫描也考虑了两种情况，其实只需要考虑左边ratings[i]>ratings[i+1]的值即可。
    {·········
        if(ratings[i] < ratings[i+1] && divid[i] >= divid[i+1])
            divid[i+1]=divid[i]+1;
        if(ratings[i] > ratings[i+1] && divid[i] <= divid[i+1])
            divid[i]=divid[i+1]+1;
    }
    int sum = accumulate(divid.begin(), divid.end(), 0);
    return sum;
}


// 更好的代码
int candy(vector<int>& ratings) {
    int size = ratings.size();
    vector<int>div(size,1);
    // 左规则，正向扫描，只考虑ratings[i]>ratings[i-1]的情况
    for(int i=1; i < size; i++)
        if(ratings[i-1]<ratings[i])
            div[i]=div[i-1]+1;
    // 右规则，逆向扫描，只考虑ratings[i]>ratings[i+1]的情况
    for(int i=size-2; i >= 0; i--)
        if(ratings[i]>ratings[i+1])
            div[i]=max(div[i+1]+1, div[i]);  // !!! 问题，当前div[i+1]+1可能小于div[i],也就是满足右规则的值可以能小于满足左规则的值。所以最终值是取左规则和有规则中较大者。
            // ***将这一行写成了div[i]=div[i+1]+1;
    // 取左规则
    int sum = accumulate(div.begin(), div.end(), 0);
    return sum;
}