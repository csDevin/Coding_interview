#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // 先对所有数进行异或，得到只出现一次的两个数字的异或结果
        int res1=0, res2=0, res3=0;
        for(auto &i: array){
            res1 ^= i;
        }
        // 从最低位开始找res1中第一个为1的位数，作为两组的分割标准
        int div = 1;
        while((div & res1) == 0){
            div <<= 1;
        }
        for(auto &i: array){
            if((i & div) == 0)  //***&或者^一定要加括号，因为这两个优先级低于==
                res2 ^= i;
            else
                res3 ^= i;
        }
        if(res2<res3)
            return vector<int>{res2, res3};
        else
            return {res3, res2};
    }
};