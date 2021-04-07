// 删除链表中重复的结点{1,2,3,3,4,4,5} -> {1,2,5}
// 重点：删除链表的节点一般需要使用pre和curr两个双指针

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x), next(nullptr){}
};

// 方法1：一次遍历使用Hashmap统计元素个数，两次遍历删除>=1的元素 (删除的方法使用虚拟头结点+单指针)
ListNode* deleteDuplication1(ListNode* pHead) {
    if(pHead==nullptr)
        return nullptr;
    ListNode* vHead = new ListNode(1);
    ListNode* p = pHead, *q = vHead;
    map<int, int> m;
    // 使用p遍历链表，统计每个元素的个数，记录在map<int, int>中                    
            vHead->next = pHead;
    while(p!=NULL){
        m[p->val]++;
        p=p->next;
    }
    // 使用q再次遍历，删除重复节点
    while(q->next!=nullptr){
        if(m[q->next->val]>1){
            q->next=q->next->next;
            continue;
        }
        q=q->next;
    }
    return vHead->next;
}



// 基础变种：删除链表中值为val的节点
ListNode* deleteNode2(ListNode* head, int val) {
    ListNode virtual_node = {1};
    ListNode* virtual_head = &virtual_node, *p;
    virtual_head->next=head;  // 定义虚头，指向头指针
    p=virtual_head;
    while(p->next!=nullptr && p!=nullptr){
        if(p->next->val == val){
            p->next=p->next->next;
            return virtual_head->next;  //***写成了return head
                                        // 应该是返回return 虚头->next
        }
        p=p->next;
    }
    return virtual_head->next;
}




// 变种：将repeating elements转化为individual elements
// {1,2,3,3,4,4,5} -> {1,2,3,4,5}
// 思想：使用pre ptr和curr ptr，当pre ptr的值等于curr ptr时，删除curr ptr
ListNode* deleteDuplication3(ListNode* pHead) {
    ListNode* p=pHead, * pre=pHead;
    if(pHead==nullptr)
        return nullptr;
    while(p->next!=nullptr){
        p=p->next;
        if(pre->val==p->val){
            pre->next=p->next;
            p=pre;
            continue;
        }
        pre=pre->next;
    }
    return pHead;
}