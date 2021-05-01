/* solutions
记住：不用加法的加法运算 = 不进位加法 + 只进位加法 = 异或运算 + 与运算后向左进一位。
又为了消除上式中的进位carry，需要用一个while循环来判断，当不再进位时跳出循环。
*/

class Solution {
public:
    int Add(int num1, int num2) {
        while(num2!=0){
            int not_carry = num1^num2;
            int carry = (unsigned int)(num1&num2)<<1;  //***忘了加括号，写成了num1&num2<<1
            // c++不支持负数的移位，需要加上unsigned int转换为非负数后操作，用unsigned表示负数，没有信息损失，照样能printf出来。
            // unsigned int跟有符号的运算，就转化成有符号类型的了，这是隐式转换。
            num1 = not_carry;
            num2 = carry;
        }
        return num1;
    }
};