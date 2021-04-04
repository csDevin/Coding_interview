// jz9: 跳台阶扩展问题
/* 思路：a[n]代表从0级台阶跳到n级台阶所需的次数
a[n] = a[n-1] + a[n-2] + ... + a[2] + a[1] (1)
       a[n-1] = a[n-2] + ... + a[2] + a[1] (2)
(2)式代入(1)式可得：a[n] = 2*a[n-1]
*/

// 代码
int jumpFloorII(int number) {
    int a = 1;  // a[1]=1;
    int b = 0;
    if(number==0)
        return 0;
    if(number==1)
        return 1;
    for(int i=2; i<=number; i++){
        b = 2*a;
        a = b;
    }
    return a;
}