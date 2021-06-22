#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 // 虚头+存后指前+head->next指空·

class Solution {
public:
    // head-use-after-free: 函数返回的值中包含已经被释放掉的内存。
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* v_head = new ListNode();
        ListNode* front = v_head;
        v_head->next = head;
        ListNode* p = head;
        ListNode* behind = NULL;
        while(p != NULL){
            behind = p->next;
            if(p==head)
                p->next = NULL;
            else
                p->next = front;
            front = p;
            p = behind;
        }
        return front;
    }
};