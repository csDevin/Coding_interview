/* solution 哈希表
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> m;
        for(auto i: numbers){
            m[i]++;
        }
        int half = floor(numbers.size()/2.0);
        for(auto i: m){
            if(i.second > half)  //***写ceil(size/2.0) && i.second>=half是不行的
                                 // 因为当size为偶数时，如6，得到的结果为>=3次，不符合
                                 // 题意，因为题目要求超过长度的一半，等于是不可以的。
                return i.first;
        }
        return 0;
    }
};