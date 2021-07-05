/* solutions
    括号问题使用栈解决。
*/

// while(){左括号进栈，直到遇到右括号，开始匹配出栈直到结束，栈为空则为true。如果中途遇到右括号不匹配，则return。}
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len<=1 || len%2!=0)  //***写成了%2!=1
            return false;
        stack<int> sta_l;
        for(int i=0; i<len; i++){
            while(s[i]=='(' || s[i]=='{' || s[i]=='['){
                sta_l.push(s[i]);  //***进栈
                i++;
            }
            if(!sta_l.empty() && (sta_l.top()=='(' && s[i]==')' || sta_l.top()=='[' && s[i]==']' || sta_l.top()=='{' && s[i]=='}')){  //***出栈要考虑栈是否为空
                sta_l.pop();  //***匹配则出栈
            }
            else
                return false;  //***不匹配则return false
        }

        if(sta_l.empty()){
            return true;
        }
        else{
            return false;
        }

    }
};