#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 思想：一棵树是镜像的，那么它对应的左右子树的结构和对应值是相同的。
// 关键问题：如何判断一个树的左右子树的结构是相同的，并且对应位置的值也是相同的。
// 正确解法：使用指向树节点的双指针，同步镜像移动，保证了树的结构是相同的，此外使用p1->val==p2->val的判断，保证了值是相同的。
class Solution {
public:
    bool isSymmetric(TreeNode *root){
        TreeNode* p1 = root->left;
        TreeNode* p2 = root->right;
        return isSym(p1, p2);
    }

    bool isSym(TreeNode* p1, TreeNode *p2){
        if(p1==nullptr && p2==nullptr)  // (!p && !q)
            return true;
        if(p1==nullptr && p2!=nullptr || p1!=nullptr && p2==nullptr)  // 高级写法(!p || !q)
            return false;
        return p1->val==p2->val && isSym(p1->left, p2->right) && isSym(p1->right, p2->left);
    }
};



//***错误解法，此解法能通过大部分结果，但是无法通过1222null2的测试用例。
//***该代码的错误是只能判断两个中序和逆中序遍历的值是否相当，无法判断结构相同。
// 暴力：res1记录preorder traversal的结果，res2记录re-preorder traversal的结果。顺序遍历res1和res2，判断是否全部相等。
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        vector<int> res1;
        vector<int> res2;
        isSym1(root, res1);
        isSym2(root, res2);
        for (int i = 0; i < res1.size(); i++)
        {
            if (res1[i] != res2[i])
                return false;
        }
        return true;
    }

    void isSym1(TreeNode *root, vector<int> &res)
    { // 前序遍历
        if (root == nullptr)
        {
            return;
        }
        isSym1(root->left, res);
        res.push_back(root->val);
        isSym2(root->right, res);
    }

    void isSym2(TreeNode *root, vector<int> &res)
    { // 逆前序遍历
        if (root == nullptr)
        {
            return;
        }
        isSym2(root->right, res);
        res.push_back(root->val);
        isSym1(root->left, res);
    }
};

