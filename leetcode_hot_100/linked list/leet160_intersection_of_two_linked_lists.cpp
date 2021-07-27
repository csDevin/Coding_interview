#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0), next(NULL){}
    ListNode(int x):val(x),next(NULL){}
};

// solution 1: 哈希表
// solution 2: double pointer，pA, pB同时遍历两个链表，当任何一个指向空的时候，从另一个链表的头节点开始遍历，直到两链表相等，返回这个相等值。
// 如果不相交，则这个相等值为NULL，如果相交，那么这个相等值为相交节点，应为(a+c)+(b)=(b+c)+(a)
//***重点细节，(pA++和pB++)操作和(pA=headB和pB=headA)操作是互斥的！
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *pa, *pb;
        pa = headA;
        pb = headB;
        if(headA==headB)
            return headA;
        if(headA==nullptr || headB==nullptr)
            return nullptr;
        while(pa != pb){
            // if(pa==nullptr)
            //     pa = headB;
            // else
            //     pa = pa->next;
            // if(pb==nullptr)
            //     pb = headA;
            // else
            //     pb = pb->next;
            pa = pa==nullptr?headB:pa->next;
            pb = pb==nullptr?headA:pb->next;
        }
        return pa;
    }
};

int main(){
    ListNode l1;
    ListNode l2(3);
    return 0;
}