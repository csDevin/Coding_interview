// 题目：（Easy）
// 时间复杂度：时间复杂度：O(n)，其中 n 是字符串的长度。判断整个字符串是否是回文字符串的时间复杂度是 O(n)，遇到不同字符时，
// 判断两个子串是否是回文字符串的时间复杂度也都是 O(n)。
// 空间复杂度：O(1)，只需要维护有限的常量空间。

// 自己的代码
bool palind(int left, int right, const string &s)
{
    while(left < right)
    {
        if(s[left]==s[right])
        {
            left++;
            right--;
        }
        else
            return false;
    }
    return true;
}

bool validPalindrome(string s) {
    int left=0, right=s.size()-1;
    while(left < right)
    {
        if(s[left]==s[right])
        {
            left++;
            right--;
        }
        else if(palind(left+1, right, s)==true || palind(left, right-1, s)==true)
            return true;
        else
            return false;
    }
    return true;
}