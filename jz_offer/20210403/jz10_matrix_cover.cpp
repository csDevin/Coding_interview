// 思路：fibonacci sequence
// 1、情况等价于情形1中阴影部分的n-1块矩形有多少种覆盖方法，为f(n-1);
// 2、情况等价于情形2中阴影部分的n-2块矩形有多少种覆盖方法，为f(n-2);
// 所以，f(n) = f(n-1) + f(n-2)，还是一个斐波那契数列。。。。且f(1) = 1, f(2) = 2。

int rectCover(int number) {
    if(number==0)  //***不多余，虽然最后会返回vec[1]或者2的值，已经定义好了，但是当number=0或1的时候vec[2]会heap buffer overflow
        return 0;
    if(number==1)  //***不多余，虽然最后会返回vec[1]或者2的值，已经定义好了，但是当number=0或1的时候vec[2]会heap buffer overflow
        return 1;
    if(number==2)
        return 2;
    vector<int> vec(number+1);  //***定义成了vec(number)，造成vec[number]越界
    vec[1]=1;
    vec[2]=2;
    for(int i=3; i<=number; i++){
        vec[i]=vec[i-2]+vec[i-1];
    }
    return vec[number];
}


