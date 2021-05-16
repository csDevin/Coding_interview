/* solutions
vector<int>中异或只能是只出现一次或者两次，
所以本题使用哈希表解决这个问题。
string str存储当前的字符串
map m存储每一个字符出现的次数，
每一次查询时，遍历字符串，查看当前字符串出现次数是否为1。
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string str;
    map<char, int> m;  //***map的定义都给搞忘了
  //Insert one char from stringstream
    void Insert(char ch) {
         str.push_back(ch);
         m[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for(int i=0; i<str.size(); i++){
            if(m[str[i]] == 1){
                return str[i];
            }
        }
        return '#';
    }

};

