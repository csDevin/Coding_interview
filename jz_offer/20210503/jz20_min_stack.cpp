/* solution 1 辅助栈 + 定义虚栈头INT_MAX (使用无参数构造函数Solution(){min_stack.push(INT_MAX);})
遇到栈stack的题目，一般需要使用辅助栈。
辅助栈1：x_stack用于存储元素，并对其进行push，pop和top操作
辅助栈2：minstack用于存储当前入栈元素的后，当前栈中的最小值，也就是min(data_in, top(min_stack))，
        辅助栈初始化为INT_MIN。
*/
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

class Solution1 {
public:
    Solution1(){
        min_stack.push(INT_MAX);
    }
    stack<int> x_stack;
    stack<int> min_stack;
    void push(int value) {
        x_stack.push(value);
        int mtop = min_stack.top();
        if(value>mtop)
            min_stack.push(mtop);
        else
            min_stack.push(value);
    }
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    int top() {
        return x_stack.top();
    }
    int min() {
        return min_stack.top();
    }
};



/* solution 2 辅助栈 + 不使用虚栈头（需要判断一下min_stack是否为empty()）
*/
class Solution2 {
public:
    stack<int> x_stack;
    stack<int> min_stack;
    void push(int value) {
        x_stack.push(value);
        if(min_stack.empty()==true || value<=min_stack.top())
            min_stack.push(value);
        else
            min_stack.push(min_stack.top());
    }
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    int top() {
        return x_stack.top();
    }
    int min() {
        return min_stack.top();
    }
};

/* solution 3 单栈 + 最小值入栈
*/
class Solution3 {
public:
    stack<int> x_stack;
    int min_value = INT_MAX;
    void push(int value) {
        // 更新min_value
        if(value<min_value)
            min_value = value;
        x_stack.push(min_value);
        x_stack.push(value);
    }
    void pop() {
        x_stack.pop();
        x_stack.pop();
        // 更新min_value
        if(x_stack.empty()==true)
            min_value = INT_MAX;
        else{
            int tmp = x_stack.top();
            x_stack.pop();
            min_value = x_stack.top();
            x_stack.push(tmp);
        }
    }
    int top() {
        return x_stack.top();
    }
    int min() {
        return min_value;
    }
};


/* solution 4 单栈记录当前值与上一步最小值的差值 + 最小值min_value记录当前步骤最小值，
上一步的最小值 == max(min_value-x_stack.top(), min_value)
注意，此方法需要无脑long long
*/
class Solution4 {
public:
    stack<long long> x_stack;
       long long x_min;
//     int x_min = INT_MAX;  //***这样写会导致int溢出，如-3-INT_MAX就溢出了
    void push(int value) {
        if(x_stack.empty())
            x_min = value;
        // 1. 先记录当前value与上一步x_min的差值
        long long tmp = value - x_min;
        x_stack.push(tmp);
        // 2. 如果差值为负数，代表出现了新的x_min，则更新x_min
        if(tmp<0)
            x_min = value;
    }
    void pop() {
        if(x_stack.top()<0){  // 如果top()<0则需要更新x_min
            x_min = x_min-x_stack.top();
        }
        x_stack.pop();
    }
    int top() {
        if(x_stack.top() > 0)
            return x_stack.top() + x_min;
        else
            return x_min;
    }
    int min() {
        return x_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */