/* solution
使用公共前缀计算函数，两两计算公共前缀。
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string common_prefix_of_two(string a, string b){
        int len = min(a.size(), b.size());
        for (int i=0; i<len; i++){
            if(a[i] != b[i]){
                return a.substr(0, i);
            }
        }
        return a.substr(0, len);
    }

    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len==1)
            return strs[0];
        string common_str = common_prefix_of_two(strs[0], strs[1]);
        for(int i=2; i<len; i++){
            common_str = common_prefix_of_two(common_str, strs[i]);
        }
        return common_str;
    }
};