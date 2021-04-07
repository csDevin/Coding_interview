// jz16_合并两个排序的链表
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

// 自己的代码
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    ListNode* np, *nHead;
    if(pHead1==NULL)  //***忘记考虑特殊条件，导致越界
        return pHead2;
    if(pHead2==NULL)
        return pHead1;
    if(pHead1->val <= pHead2->val){
        np = pHead1;
        pHead1 = pHead1->next;
    }
    else{
        np = pHead2;
        pHead2 = pHead2->next;            
    }
    nHead = np;
    while(pHead1!=NULL && pHead2!=NULL){
        if(pHead1->val <= pHead2->val){
            np->next = pHead1;
            pHead1 = pHead1->next;
        }
        else{
            np->next = pHead2;
            pHead2 = pHead2->next;                
        }
        np = np->next;
    }
    // while(pHead1!=NULL){
    //     np->next = pHead1;
    //     pHead1 = pHead1->next;
    //     np = np->next;
    // }
    // while(pHead2!=NULL){
    //     np->next = pHead2;
    //     pHead2 = pHead2->next;
    //     np = np->next;
    // }
    return nHead;
}


// 简化后的代码，因为当pHead1或者pHead2==NULL时，仅剩下一个链表，所以此时不需要使用while循环，继续使用上面的复杂的
// 多次调整指针的循环操作，仅仅需要使用p->next = pHead2即可，这就解决了需要循环调指针的问题，顺利的将两个链表衔接了起来。
ListNode* mergeTwoLists(ListNode* pHead1, ListNode* pHead2) {
    ListNode* np, *nHead;
    if(pHead1==NULL)
        return pHead2;
    if(pHead2==NULL)
        return pHead1;
    if(pHead1->val <= pHead2->val){
        np = pHead1;
        pHead1 = pHead1->next;
    }
    else{
        np = pHead2;
        pHead2 = pHead2->next;            
    }
    nHead = np;
    while(pHead1!=NULL && pHead2!=NULL){
        if(pHead1->val <= pHead2->val){
            np->next = pHead1;
            pHead1 = pHead1->next;
        }
        else{
            np->next = pHead2;
            pHead2 = pHead2->next;                
        }
        np = np->next;
    }
    if(pHead1!=NULL)
        np->next=pHead1;
    if(pHead2!=NULL)
        np->next=pHead2;
    return nHead;
}



int main()
{
    // ListNode A[3] = {1, 2, 3};
    // A[0].next = &A[1];
    // A[1].next = &A[2];
    // A[2].next = nullptr;

    // ListNode B[3] = {1, 2, 3};
    // B[0].next = &B[1];
    // B[1].next = &B[2];
    // B[2].next = nullptr;
    
    // ListNode *p = Merge(A, B);
    ListNode p(10), *q;
    p.val = 100;
    q = &p;
    q = q->next;
    q->val = 222;
    int a = 1;
    return 0;
}
