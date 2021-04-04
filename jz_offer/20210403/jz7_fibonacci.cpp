// jz7: Fibonacci数列
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int Fibonacci(int n) {
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int a=0, b=1, c;
    for(int i=2; i<=n; i++){
        c = a+b;
        a=b;
        b=c;
    }
    return c;
}



int fib(int number) {
    if(number==0)
        return 0;
    if(number==1)  //***不多余，虽然最后会返回vec[1]或者2的值，已经定义好了，但是当number=0或1的时候vec[2]会heap buffer overflow
        return 1;
    if(number==2)
        return 1;
        vector<int> vec(number+1);  //***定义成了vec(number)，造成vec[number]越界
        vec[1]=1;
        vec[2]=1;
        for(int i=3; i<=number; i++){
            vec[i]=(vec[i-2]+vec[i-1]) % 1000000007;
        }
        return vec[number];
}