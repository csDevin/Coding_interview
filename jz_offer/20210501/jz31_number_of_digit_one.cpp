class Solution {
public:
    /*
        digit: 1表示个位，10表示十位，100表示百位
        curr: 当前位的值，分为3类：{0}，{1}，{2，3，4，5，...，9}，curr==0可以代表当前位为0，
              也可以代表遍历结束。每次循环计算当前位curr为0时，在当前数的范围内，curr位出现1的次数。
        low: 低位的数值，low==0代表空
        high: 高位的数值，high==0代表空
        循环边界: curr==0 && high==0
    */
    
    int NumberOf1Between1AndN_Solution(int n) {
        long long digit = 1;  //***优化点
        int curr = n%10;
        int low = 0;
        int high = n/10;
        int res = 0;
        while(!(high==0 && curr==0)){  //***写成了high!=0 &&  curr!=0，应该写成||，为了达到两者都为0才停止循环的条件
                                    // 写成high!=0 || curr!=0或者!(high==0 && curr==0)
            if(curr==0)
                res += high * digit;
            else if(curr==1)
                res += high * digit + low + 1;
            else
                res += (high+1) * digit;
            
            low += curr*digit;  //***注意四者的顺序
            curr = high%10;
            high /= 10;
            digit*=10;  //***digit不是++而是*=10，因为我们用10的倍数表示位数
        }
        return res;
    }
};