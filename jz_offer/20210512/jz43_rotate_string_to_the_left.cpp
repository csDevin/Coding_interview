/* solution
str1.erase(pos, n);
str1.append(str2, pos, n);
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        string tmp = str;
        str.erase(0, n);
        str.append(tmp, 0, n);
        return str;
    }
};