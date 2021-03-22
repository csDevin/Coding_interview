#include<vector>
#include<iostream>
using namespace std;

/*
方法1：从低到高排序，定义一个大小确定的容器，因为最低的人可以确定他前面绝对只有k个空位（或者是和他一样高的人），
这样递推下去。

方法2：从高到低排序，k从低到高排序，定义一个大小动态的容器，因为低的人的插入位置的变化不会影响高的人，所以先放高的人，
k从低到高是因为是从前往后遍历先确定k小的人才能确定k大的人，这样可以直接将第i个人插入到people[i][k]位置处。

思想：通过一个特殊的人来确定这个人在队伍中的相对位置或者绝对索引位置，这个人可以是最高的人（k大或k小），
或者是最矮的人（k大或k小）。
k可以确定这个人前面有几个比他高的人，当这个人是最矮的时候，那前面就一定只有k个人。
*/



// 方法1：从低到高排序（自己的代码）（放好位置，然后一个一个选位置）
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> new_queue(people.size(), vector<int>(2,-1));
    sort(people.begin(), people.end());
    // special
    if(people.size()==1)
        return people;
    int status = people[0][1];
    new_queue[status] = people[0];
    for(int i=1; i<people.size(); i++)
    {
        status = people[i][1];  // 放到第status+1个空位上面，身高相等视作一个空位
        int j=0;
        while(status>=0)
        {
            if(new_queue[j][0]==-1 || people[i][0]==new_queue[j][0])  // 是否是空格
            {
                j++;
                status--;
            }
            else
                j++;
        }
        new_queue[j-1]=people[i];
    }
    return new_queue;
}

int main()
{
    vector<int> num;
    cout << num.empty() << endl;
    return 0;
}


// 从高到低排序（参考的代码）（一个一个地插入到队伍中）
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> new_queue;
    sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b)
    {return a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]);});
    // special
    if(people.size()==1)
        return people;
    new_queue.push_back(people[0]);
    for(int i=1; i<people.size(); i++)
    {
        if(new_queue.size()==people[i][1])
            new_queue.push_back(people[i]);
        else
            new_queue.insert(new_queue.begin()+people[i][1], people[i]);
    }
    return new_queue;
}