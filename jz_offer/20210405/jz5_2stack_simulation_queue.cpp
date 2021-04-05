// jz5: 用两个栈实现队列
// 思路：stack1用来专门push元素，当需要pop元素时，先将stack1的元素全部top+pop到stack2中，

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res = stack2.top();
        stack2.pop(); //***top()之后忘记pop()了
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};