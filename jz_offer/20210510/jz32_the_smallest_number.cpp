#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

/* solution
1. 将vector<int> numbers 放入vector<string> num (使用to_string(int))
2. 对num应用sort函数，cmp函数的判断标准为return s1+s2<s2+s1 (string s1, s2;)
3. 使用str.append(i)对排序后的string vector进行拼接

*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> num;
        string res;
        for(auto &i: numbers){
            num.push_back(to_string(i));
        }
        sort(num.begin(), num.end(), [](auto &a, auto &b){
            return a+b<b+a;  // 对于a，b两个字符穿，比较准则为两者按不同顺序相加，谁在前面相加更小，则谁就更小。
        });
        for(auto &i: num){
            res.append(i);
        }
        return res;
    }
};