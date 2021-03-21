// 问题：为什么要选择区间右侧排序，不选择区间左侧排序？
// 答：本题为无重叠区间可以转化为最少无重叠区间，假如区间是从左往右选择的话，区间会从左往右占用空间，区间右侧越小，给剩下的区间留下的空间就越大，就越能容纳更多的区间。排序的优先级为（右侧小->大, 左侧小->大），右侧小->大表示右区间越小的越先选择，左侧小->大没有问题，即当右侧区间相同的时候，先选左侧区间小的和先选左侧区间大的不会影响最终结果。
// 自己的解法（好）
static bool cmp(const vector<int> &a, const vector<int> &b) //***忘记添加引用，添加引用能极大的减少计算和内存开销。const保证了a和b的值不允许被修改。
// static全局变量：限制了其作用域只能在定义了该变量的文件内，在其他文件中不能使用它。
// 静态函数：在函数的返回类型上加上关键字static，函数就被定义成静态函数，函数的作用域被限制在当前文件下。
{
    if(a[1] < b[1])
        return true;
    else if(a[1] == b[1])
    {
        if(a[0]>a[1])  // >代表先选左区间大的，<代表先选左区间小的，结果都对。
            return true;
        else
            return false;
    }
    else
        return false;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int m = intervals.size();
    if(m==0 || m==1)  // ***没有考虑特殊情况0和1
        return 0;
    sort(intervals.begin(), intervals.end(), cmp);  //***排序选择了区间左侧，应该选择区间右侧。
    vector<int> record={intervals[0][0], intervals[0][1]};  //***在排序之前就把第一个区间当成初始值，非常有问题。
                                                            //此外，record[0]没有用到，这里改成record=intervals[0][1]更精简。
    int count = 0;
    for(int i=1; i<m; i++)
    {
        if(record[1] > intervals[i][0])  // 区间i-1和当前维护的空间重叠
        {
            count++;  // ***count++写到了else那里
            continue;
        }
        else
            record[1] = intervals[i][1];
    }
    return count;
}


//更好的代码
// sort函数写的很精简
sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
    return u[1] < v[1];
});
// 也可以写成
[](const vector<int>& u, const vector<int>& v){});
// also
sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b)
{
    if(a[1] < b[1])
        return true;
    else if(a[1] == b[1])
    {
        if(a[0]>a[1])
            return true;
        else
            return false;
    }
    else
        return false;
});