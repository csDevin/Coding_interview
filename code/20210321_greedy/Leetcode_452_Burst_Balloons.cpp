'''
思想：按照区间右侧从小到大排序，右侧排序保证了保留区间的右边界record更好确定，因为重叠与保留区间的右侧关系最大，
如果重叠，则record一定是不变的。record记录当前保留区间的最右侧，如果保留区间与当前区间重叠，则保留区间更新为重叠部分，
如果不重叠则count++，record=points[i][1]
'''
// 自己的代码
int findMinArrowShots(vector<vector<int>>& points) {
    if(points.size()==0)  // 特殊情况
    // ***size没加()
        return 0;
    if(points.size()==1)
        return 1;
    int count=1;
    sort(points.begin(), points.end(), [](const auto& a, const auto& b)
    {return a[1]<b[1];});
    int record=points[0][1];
    for(int i=1; i<points.size(); i++)
    {
        if(record>=points[i][0])  // 重叠
        //***没有看清题意，忘记加=号
            continue;
        else
        {
            count++;
            record = points[i][1];
        }
    }
    return count;
}