/*
难点1：如果节点的val值为负数
难点2：return类型为char*和string的写法是有一定的区别的，char*转string，直接等。string转char* (char*)str.data()。
难点3：有DFS和BFS两种写法，都需要掌握。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

/* solution 1: 牛客char* + DFS
DFS序列化不需要外部函数，反序列化需要一个外部函数。因为递归deserialize(char* str)无法改变str的值，所以需要写成deseri(char *&s)
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(!root)
            return "#";
        string str = to_string(root->val) + "!";
        char* str_c = (char*)str.data();
        char* left = Serialize(root->left);
        char* right = Serialize(root->right);
        char* series = new char[strlen(str_c) + strlen(left) + strlen(right)];
        strcpy(series, str_c);
        strcat(series, left);
        strcat(series, right);
        return series;
    }
    
    TreeNode* Deserialize(char *str) {
        return deseri(str);
    }
    
    TreeNode* deseri(char* &s){
        // 1. 如果为空则返回空节点
        if(*s == '#')
        {
            ++s;  //***忘记写++s，导致s不往后走，后面全为空。
            return NULL;   
        }
        // 2.1 否则得到当前节点的val
        int num = 0;
        while(*s != '!'){  //***这里是感叹号!
            num = num * 10 + (*s-'0');
            ++s;
        }
        ++s;
        // 2.2 构建当前节点的left和right子树
        TreeNode* root = new TreeNode(num);
        root->left = deseri(s);
        root->right = deseri(s);
        return root;
    }
};
*/




/* solution 2: 牛客char* + BFS + o&i stringstream
// BFS层次遍历 (level order traversal)写法
class Solution {
public:
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
        char* new_out = new char[out.str().size()];
        strcpy(new_out, (char*)out.str().data());
        return new_out;
    }

    // 将string存入vector
    TreeNode* Deserialize(char *str) {
        vector<TreeNode*> vec;
        string str1 = str;
        string tmp;
        istringstream s(str1);
        while(s>>tmp){
            if(tmp=="#"){
                vec.push_back(NULL);
            }
            else{
                TreeNode* node = new TreeNode(stoi(tmp));
                vec.push_back(node);
            }
        }

        int j=1;
        int len = vec.size();
        for(int i=0; i<len; i++){
            if(vec[i]==NULL){
                continue;
            }
            else{
                if(j<len)
                    vec[i]->left = vec[j++];
                if(j<len)
                    vec[i]->right = vec[j++];               
            }
        }
        return vec[0];
    }
};
*/






/* solution 3.1: leetcode string + DFS
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";
        string val = to_string(root->val);
        val = val + ",";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return val + left + right;
    }

    TreeNode* deseri(string & data, int &p){
        // 特殊情况，空结点
        if(data[p]=='#'){
            ++p;
            return NULL;
        }
        // 否则，得到val的值
        int num=0;
        int flag = 0;  //***忘记了需要处理符号，使用flag来处理负号
        while(data[p]!=','){
            if(data[p]=='-'){
                flag = 1;
                ++p;
            }
                
            num = num*10 + data[p]-'0';  //***字符转数字，忘记减'0'
            ++p;
        }
        if(flag==1)
            num*=-1;
        flag == 0;
        ++p;  // 跳过逗号
        // 最后，递归地构造左右子树
        TreeNode* root = new TreeNode(num);
        root->left = deseri(data, p);
        root->right = deseri(data, p);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int p = 0;
        return deseri(data, p);  //***p必须传引用，否在在多层递归中无法值同步
    }
};
*/



/* solution 3.2: leetcode string + DFS + istringstream
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";
        string val = to_string(root->val);
        string left = serialize(root->left);
        string right = serialize(root->right);
        return val+ " " + left + " " + right; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        return deseri(s);
    }

    TreeNode* deseri(istringstream & s){  //***istringstream写成了string
        string str;
        s >> str;  // str为一个val
        if(str == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        root->left = deseri(s);
        root->right = deseri(s);
        return root;
    }
};
*/


/* solution 4.1: leetcode string + BFS + ostringstream + istringstream
class Codec {
public:
    // 使用ostringstream将vals压入out中，然后deserialize的时候使用istringstream将vals读出，并通过快慢指针i，j来重构二叉树。
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);
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
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        // 1. 先将序列解析到vector中，然后使用vector来构造树
        vector<TreeNode*> vec;
        string tmp;
        while(s>>tmp){
            if(tmp=="#"){
                vec.push_back(NULL);
            }
            else{
                TreeNode* root = new TreeNode(stoi(tmp));
                vec.push_back(root);
            }
        }

        // 2. 使用vector来构造二叉树，i指向当前节点，j指向i节点的左子节点，当i为空时候，
        // 说明i不存在左右子节点，所以j不是i的左子节点，i++;
        int len = vec.size();
        int j=1;
        for(int i=0; i<len; i++){
            if(vec[i] == NULL)  //***vec写成了vector
                continue;
            if(j < len)  //***忘记考虑j会越界的问题，因为i走一步，j走两步，所以一定是j先到达边界
                vec[i]->left = vec[j++];
            if(j < len)
                vec[i]->right = vec[j++];
        }
        return vec[0];
    }
};
*/




/* solution 4.2: leetcode string + BFS + istringstream
class Codec {
public:

    // 层次遍历压入ostringstream out;
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "#";
        string s;
        // ostringstream out;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){  //***NULL也要进队列，不然无法序列化NULL
            TreeNode* p = que.front();
            if(p){  // 非空节点存在左右子节点
            //***巨大bug，!p代表p为空时候执行，此时需要非空执行，写成了if(!p)
                s.append(to_string(p->val));  //***字符串加法全部改成str1.append(str2)
                s.push_back(' ');
                que.push(p->left);  //***写成了que.push(root->left)造成了死循环
                que.push(p->right);
            }
            else{  // 空节点不存在左右子节点
                s.append("# ");
            }
            que.pop();
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        // 1. 先将序列解析到vector中，然后使用vector来构造树
        vector<TreeNode*> vec;
        string tmp;
        while(s>>tmp){
            if(tmp=="#"){
                vec.push_back(NULL);
            }
            else{
                TreeNode* root = new TreeNode(stoi(tmp));
                vec.push_back(root);
            }
        }

        // 2. 使用vector来构造二叉树，i指向当前节点，j指向i节点的左子节点，当i为空时候，
        // 说明i不存在左右子节点，所以j不是i的左子节点，i++;
        int len = vec.size();
        int j=1;
        for(int i=0; i<len; i++){
            if(vec[i] == NULL)  //***vec写成了vector
                continue;
            if(j < len)  //***忘记考虑j会越界的问题，因为i走一步，j走两步，所以一定是j先到达边界
                vec[i]->left = vec[j++];
            if(j < len)
                vec[i]->right = vec[j++];
        }
        return vec[0];
    }
};

*/


