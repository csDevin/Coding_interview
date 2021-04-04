// jz51: 构建乘积数组
// 时间复杂度：O(n)
// 空间复杂度：O(n)
vector<int> multiply(const vector<int>& A) {
    int len=A.size();
    vector<int> left(len), right(len), ans(len);
    left[0]=1;
    right[len-1]=1;
    for(int i=1; i<len; i++)
    {
        left[i] = left[i-1] * A[i-1];  // 计算上三角矩阵
        right[len-i-1] = right[len-i] * A[len-i];  // 计算下三角矩阵
    }
    for(int i=0; i<len; i++)
    {
        ans[i] = left[i] * right[i];  // 上三角矩阵乘下三角矩阵即为结果
    }
    return ans;
}