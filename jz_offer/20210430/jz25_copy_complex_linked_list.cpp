/*
解题思路
如果数据结构为普通链表，直接遍历链表 + 创建新结点 + 调整前驱指针指向当前结点即可。但是这道题麻烦在于有一个random指针，
如果依旧使用遍历的方法可能导致random所指向的结点还没有被创建。因此我们需要一种方法，使得在一开始的时候就将所有的结点创建出来，
之后再调整指针的指向，这样就可以防止random指针指向的结点尚未被创建的情况。
开始时创建的所有结点需要存储在一个容器中。为了方便索引，将开始时创建的所有结点存储在一个哈希表中，将原链表的结点作为键，
新创建的结点作为值。创建哈希表需要遍历原始链表。哈希表创建完成后，开始为新创建的结点设置指针的指向。由于新创建的结点以对应的原结点为键，
因此再次遍历原始链表*，以将每个原始链表的next和random所指向的结点作为键，查找当前原始结点所对应的新结点的指针指向，逐一调整即可。

时间空间复杂度
由于创建哈希表和调整指针指向都需要遍历链表，因此时间复杂度为O(n)；由于创建哈希表的空间随问题的规模呈线性增长，因此空间复杂度为O(n)。
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        unordered_map<Node*, Node*> m;
        Node* p = head;
        while(p){
            Node* node1 = new Node(p->val);
            m[p] = node1;
            p = p->next;
        }
        
        p = head;
        
        while(p){
            Node* q = m[p];
            q->random = m[p->random];
            q->next = m[p->next];  //***写成了q->next = m[q->next]
            p = p->next;
        }
        return m[head];
    }
};