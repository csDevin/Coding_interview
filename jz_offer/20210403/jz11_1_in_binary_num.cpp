// 二进制中1的个数
// 思路：重要思想：二进制数每次减1后与原数进行&运算会消去最右边的1。
// 如：101&100=100；100&011=000
int  NumberOf1(int n) {
    int cnt=0;
    while(n!=0){
        cnt++;
        n = n&(n-1);
    }
    return cnt;
}

/* python 代码
思想：使用十进制int转二进制str函数bin(int)+str1.count("1")字符串str计数函数
def NumberOf1(self, n):
    if(n<0):
        n = n & 0xffffffff  # 注意，对于负数需要先转化为16进制形式，再输入bin()函数才能得到正确的二进制原码表示
    return bin(n).count("1")
*/