// 暴力法，使用count_if(v.begin(), v.end(), [&data, &i](int num){
    // return  num>data[i];
// })
int InversePairs(vector<int> data) {
    int len = data.size();
    long long cnt=0;
    int j;
    for(j=1; j<len; j++){
        if(data[j]<data[j-1])
            break;
    }
    for(int i=j; i<len; i++){
        cnt+=count_if(data.begin(), data.begin()+i, [&data, &i](const auto &num){
            return num>data[i]; 
        });
    }
    return cnt%1000000007;
}


// 暴力法，使用for循环
int InversePairs(vector<int> data) {
    int len = data.size();
    long long cnt=0;
    int j;
    for(j=1; j<len; j++){
        if(data[j]<data[j-1])
            break;
    }
    for(int i=j; i<len; i++){
        for(int c=0; c<i; c++){
            if(data[c]>data[i])
                cnt++;
        }
    }
    return cnt%1000000007;
}


// 正确代码：使用归并排序
