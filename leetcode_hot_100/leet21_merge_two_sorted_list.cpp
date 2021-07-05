#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* solution
重点：哨兵头节点：pre_head
p1, p2指向两个链表，当p1<=p2则p->next=p1++；否则，反之；如果p1==nullptr，则p->p2，return，否则，反之。
首先，我们设定一个哨兵节点 prehead ，这可以在最后让我们比较容易地返回合并后的链表。我们维护一个 prev 指针，
我们需要做的是调整它的 next 指针。然后，我们重复以下过程，直到 l1 或者 l2 指向了 null。
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // if(l1==nullptr || l2==nullptr)  //***错了，任何一个为空应该返回另一个。
            // return nullptr;
        if(l1==nullptr)
            return l2;
        else if(l2==nullptr)
            return l1;
        ListNode* vhead = new ListNode();
        ListNode* p1=l1, *p2=l2, *p;
        p = vhead;
        while(p1!=nullptr && p2!=nullptr){
            if(p1->val <= p2->val){
                p->next = p1;
                p1 = p1->next;
            }
            else{
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if(p1!=nullptr){
            p->next = p1;
        }
        else if(p2!=nullptr){
            p->next = p2;
        }
        return vhead->next;
    }
};