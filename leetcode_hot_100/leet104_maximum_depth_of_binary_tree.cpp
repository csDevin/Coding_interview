#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* p1, TreeNode* p2):val(x), left(p1), right(p2){}
};

// 难点：如何传递递归函数之间更新的树高。
// 重点，树高 = max(左子树的树高， 右子树的树高)
// 即深度优先搜索
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};