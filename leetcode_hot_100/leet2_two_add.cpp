


 /* solution: 逆序很重要，从个位往后推然后构建节点就可以了。
思路：
如果当前两个链表处相应位置的数字为 n1,n2n1,n2，进位值为carry，则它们的和为 n1+n2+carry；其中，
答案链表处相应位置的数字为 (n1+n2+carry)mod10，而新的进位值为(n1+n2+carry)/10
难点1：进位，当前位加上carry之后可能需要进位；
难点2：何时需要创建节点，if判断很重要（if(l1!=NULL || l2!=NULL || carry!=0)）
简化写法：
p->next = new ListNode() + p=p->next + p->val=sum%10 简化成
p->next = new ListNode(sum % 10) + p=p->next
 */
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(5);
        ListNode* p = head;
        int sum = 0;
        while(l1!=NULL || l2!=NULL){
            // p = new ListNode();  // 会出现p->pre->next==NULL != p的问题，修改p并不会修改p->pre->next的值，导致无法衔接。
            if(l1==NULL){
                sum = l2->val + carry;
                l2 = l2->next;
            }
            else if(l2==NULL){
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else{
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            carry = sum/10;
            p->val = sum%10;
            if(l1!=NULL || l2!=NULL || carry!=0)
                p->next = new ListNode();
            p = p->next;
        }
        if(carry!=0){
            p->val = carry;
        }
        return head;
    }
};
