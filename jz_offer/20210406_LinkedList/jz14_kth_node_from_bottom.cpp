// jz14: 链表中倒数第k个结点

// 方法1：p指针遍历链表统计元素个数为num，q指针从head处走到num-k的元素处
ListNode* FindKthToTail(ListNode* pHead, int k) {
    // 特殊情况考虑，首先是pHead特殊的时候，其次是k特殊的时候
    if(pHead==NULL)  //***第1种结果为NULL的情况，pHead+NULL
        return NULL;
    ListNode* p = pHead;
    ListNode* q = pHead;
    int num = 1;
    while(p->next!=NULL){  // 计算链表种一共有几个数，算得倒数第k大的数的下标为：num-k
        p = p->next;
        num++;
    }
    if(num<k)  //***第2种结果为NULL的情况，k>len
        return NULL;
    for(int i=0; i<num-k; i++)
        q=q->next;
    return q;
}

// 方法2：双指针
ListNode* FindKthToTail(ListNode* head, int k) {
    // 特殊情况1：链表为空
    if(head==NULL || k==0)  //***k==0的情况没有考虑到
        return NULL;
    // 快指针fast先走k-1步
    ListNode *fast=head, *slow=head;
    int i=0;
    while(i<k-1){
        if(fast->next==NULL || fast==NULL)  //***特殊情况2：k大于链表的长度。只写了fast==NULL,没想到
                                            //fast->next==NULL也是不符合情况的。
            return NULL;
        i++;
        fast = fast->next;
    }
    // 快慢指针同时走，直到fast->next==NULL
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}