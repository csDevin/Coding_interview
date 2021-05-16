#include<bits/stdc++.h>
using namespace std;

/* solutions (时空复杂度次优)
优先级队列存储pair<pos, val>,所以优先级队列的top一定是最大值，但是，可能不在滑动窗口中，故我们解决这个问题，通过判断pos和窗口左侧的位置关系，若不在，则pop()
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& num, int size) {
        if(num.size() < size || num.size()==0 || size==0)  //***遇到段错误，请先排除特殊情况。
            return {};
        vector<int> res;
        priority_queue<pair<int, int>> q;  //***优先级队列先对第一个元素排序，再对第二个元素排序
        int l=0, r=size;  // 左闭右开
        for(int i=0; i<size; i++){
            q.emplace(num[i], i);  //***q.emplace(i, num[i]);这么写是个重大错误，优先级队列先对第一个元素排序，再对第二个元素排序
        }
        res.push_back(q.top().first);  //***放进去会造成越界
        l++, r++;
            
        while(r <= num.size()){  //***忘记左闭右开，写成了r<num.size()
            q.emplace(num[r-1], r-1);  //***当r=num.size()的时候，r++，此处会越界
            while(q.top().second < l){
                q.pop();
            }
            res.push_back(q.top().first);
            l++, r++;  //***r++，l++一般写在最后，避免了数组越界等问题，加完之后，立即判断即可。
        }
        return res;
    }
};