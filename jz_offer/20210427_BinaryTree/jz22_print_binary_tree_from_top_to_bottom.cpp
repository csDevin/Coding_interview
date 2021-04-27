// just a level travesal (BFS) using queue、
// 先进root，root->left, root->right，然后打印root，pop(root)
// 即对于每个点，进left和right，然后pop这个点重复这个过程

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

/*
特例处理： 当树的根节点为空，则直接返回空列表 [] ；
初始化： 打印结果列表 res = [] ，包含根节点的队列 queue = [root] ；
BFS 循环： 当队列 queue 为空时跳出；
出队： 队首元素出队，记为 node；
打印： 将 node.val 添加至列表 tmp 尾部；
添加子节点： 若 node 的左（右）子节点不为空，则将左（右）子节点加入队列 queue ；
返回值： 返回打印结果列表 res 即可。
*/


class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> vec1;
        if(root==NULL)
            return vec1;
        queue<TreeNode*> q1;
        TreeNode* p=root;
        q1.push(root);
        while(!q1.empty()){
            p = q1.front();
            //***多写了这一段，主要想法是先push(root)，再push root的left和right，
            // 问题在于，你所谓的push的root，其实就是上一步或者几步已经push过的left或者right，这其实是重复劳动
            // if(p!=root)
            //    q1.push(root)
            if(p->left!=NULL)
                q1.push(p->left);
            if(p->right!=NULL)
                q1.push(p->right);
            vec1.push_back(q1.front()->val);
            q1.pop();            
        }
        return vec1;
    }
};