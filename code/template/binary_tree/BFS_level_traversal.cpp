char* Serialize(TreeNode *root) {
    if(root == NULL)
        return "# ";
    ostringstream out;
    queue<TreeNode*> q;
    q.push(root);
//         out<<q.front()->val<<" ";
    while(!q.empty()){
        TreeNode* p = q.front();
        if(p==NULL){  //***空节点不存在左右子节点
            out<<"# ";
        }
        else{
            out<<p->val<<" ";
            q.push(p->left);
            q.push(p->right);
        }
        q.pop();
    }
}