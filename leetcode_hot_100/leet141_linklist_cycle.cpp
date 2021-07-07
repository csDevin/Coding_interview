#include<bits/stdc++.h>
using namespace std;

// 方法1：哈希表
// 方法2：快慢指针

/*
观察下面的代码，我们使用的是 while 循环，循环条件先于循环体。由于循环条件一定是判断快慢指针是否重合，
如果我们将两个指针初始都置于 head，那么 while 循环就不会执行。因此，我们可以假想一个在 head 之前的虚拟节点，
慢指针从虚拟节点移动一步到达 head，快指针从虚拟节点移动两步到达 head.next，这样我们就可以使用 while 循环了。
当然，我们也可以使用 do-while 循环。此时，我们就可以把快慢指针的初始值都置为 head。
*/

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