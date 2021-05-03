/* solutions
考虑借用一个辅助栈 stackstack ，模拟 压入 / 弹出操作的排列。根据是否模拟成功，即可得到结果。
初始化： 辅助栈 stackstack ，弹出序列的索引 ii ；
遍历压栈序列： 各元素记为 numnum ；
元素 numnum 入栈；
循环出栈：若 stackstack 的栈顶元素 == 弹出序列元素 popped[i]popped[i] ，则执行出栈与 i++i++ ；
返回值： 若 stackstack 为空，则此弹出序列合法。
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty()==true)
            return true;
        stack<int> s;
        int i = 0;
        for(auto p:pushV){
            s.push(p);
            while(i<popV.size() && !s.empty() && popV[i] == s.top()){
            //***空vector不能索引，空栈不能top()
                s.pop();
                i++;
            }
        }
        if(s.empty()==true)
            return true;
        else
            return false;
    }
};