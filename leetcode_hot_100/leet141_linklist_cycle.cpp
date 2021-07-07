#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* fast = head;
        ListNode* slow = head;

        //***此代码会超出时间限制，因为while循环会执行fast==head的指针，无论fast是否等于slow，所以若环出现在head处，你的代码将陷入死循环。
        // 用do while结构解决这个问题，绕过初始的fast==slow的尴尬情形。
        // while(fast==head || fast!=slow){  // fast!=slow一开始就成立，直接返回false，所以需要增加fast!=head
        //     if(fast==nullptr || fast->next==nullptr || fast->next->next==nullptr)
        //         return false;
        //     fast = fast->next->next;
        //     slow = slow->next;
        // }

        do{
            if(!fast || !(fast->next) || !(fast->next->next))
                return false;
            fast = fast->next->next;
            slow = slow->next;
        }while(slow!=fast);
        return true;
    }
};