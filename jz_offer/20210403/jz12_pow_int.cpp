// 数值的整数次方
/* 思路：
1. x的负数n次方等于1/x的-n次方
3. n&1（与操作）： 判断n二进制最右一位是否为1；
3. n>>1（移位操作）：n右移一位（可理解为删除最后一位）。
4. 快速幂解析（二进制角度），正数x的n次方，n转化为二进制为dn dn-1...d3 d2 d1, n = 1*d1+2*d2+4*d3+8*d4+...+2^(n-1)*dn
   x^n = x^(1*d1+2*d2+4*d3+8*d4+...+2^(n-1)*dn) = x^(1*d1) * x(2*d2) * x(4*d3) *...* x(2^(n-1)*dn)
   从而可以转化为
   double res = 1.0;
    while(n!=0){
        if(n&1==1)  // 如果di位存在，则di=1，将x(2(i-1)*1)的值即当前x的值*给res
            res*=x;
        x*=x;  // 二进制每位的差距是平方关系，计算下一位x的指数值，即x(2^(i-1))*1的值
        n>>=1;  // n右移一位，删除最后一位
    }
    return res;
*/

double myPow(double x, long long n) {
    if(x==0)  // or INF
        return 0;
    if(n<0){
        x = 1/x;
        n *= -1;
    }  
    double res = 1.0;
    while(n!=0){
        if(n&1==1)  // 如果di位存在，则di=1，将x(2(i-1)*1)的值即当前x的值*给res
            res*=x;
        x*=x;  // 二进制每位的差距是平方关系，计算下一位x的指数值，即x(2^(i-1))*1的值
        n>>=1;  // n右移一位，删除最后一位
    }
    return res;
}



/* python代码
def Power(self, x, n):
    if(x==0):
        return 0;
    res=1.0
    if n<0:
        x=1/x
        n=-n
    while(n!=0):
        if(n&1==1):
            res*=x;
        x*=x
        n>>=1
    return res
*/