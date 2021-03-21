// 自己的解法：首位添加零解决了首尾元素特殊的边界问题，然后从第二个元素开始遍历种花，直到倒数第二个元素。
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count=0;
    // 特殊情况
    if(n==0)
        return true;
    // 首尾插入元素0
    flowerbed.push_back(0);
    flowerbed.insert(flowerbed.begin(), 0);
    // 从第二个元素开始检查是否可以种花
    for(int i=1; i<flowerbed.size()-1; i++)  //***i<flowerbed.size()-2忘记了写-2
    {
        if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0)
        {
            flowerbed[i]=1;  //***等号=写成了==号
            count++;
        }   
    }
    if(count<n)
        return false;
    else
        return true;
}