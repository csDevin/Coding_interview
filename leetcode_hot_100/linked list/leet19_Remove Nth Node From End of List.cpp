#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// remove链表节点使用虚头节点dummy会更方便删除头节点。
// 删除节点p从前一个节点p-1处删除更简单。故快指针和慢指针之间的距离为n。
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 创建dummy head节点。
        ListNode *dummy_node = new ListNode(0);
        dummy_node->next = head;
        ListNode *res = dummy_node->next;
        // 定义快慢指针
        ListNode* slow=dummy_node, *fast=dummy_node;
        // 先走快指针，使得快指针与慢指针之间相隔N个节点
        for(int i=0; i<=n; i++){
            fast = fast->next;
        }
        // 快慢指针同时走，直到快指针==nullptr，此时慢指针的后继节点即为倒数第N个节点。
        while(fast){  //***写成了while(!fast)应该写成while(fast!=nullptr)
            fast = fast->next;
            slow = slow->next;
        }
        // 删除slow的后继节点。
        slow->next = slow->next->next;
        res = dummy_node->next;
        return res;
    }
};