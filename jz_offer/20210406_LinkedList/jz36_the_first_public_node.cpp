// 两个链表的第一个公共结点
// 本题的隐含条件，本题的两个链表长得像一个躺着的丫字。
// 思路1，一般：Hashmap or Hashset
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    map<ListNode*, int> map1;
    ListNode* p=pHead1, *q=pHead2;
    while(p!=NULL){
        map1[p]++;
        p=p->next;
    }
    while(q!=NULL){
        if(map1[q]>=1)
            return q;
        q=q->next;
    }
    return NULL;
}

// 思路2，好：双指针法，浪漫相遇
// 设head1到公共节点的距离为a，head2到公共节点的距离为b，公共节点到tail的距离为c。
// 让p1和p2分别从两个链表的表头出发，当任何一个指针到达末尾之后，都从另一个表的表头重新出发，另一个指针也是如此。
// 当两个指针相遇时，即是这两个链表的公共节点，因为a+c+b == b+c+a
//***错误代码：p1=pHead2;和p1=p1->next这两步是互斥的，只能二者择一！！！
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    if(pHead1==NULL || pHead2==NULL)
        return NULL;
    ListNode* p1=pHead1, *p2=pHead2;
    while(p1!=p2){
        if(p1==NULL)
            p1=pHead2;
        if(p2==NULL)
            p2=pHead1;
        p1=p1->next;
        p2=p2->next;
    }
    return p1;
}
// 正确代码
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    if(pHead1==NULL || pHead2==NULL)
        return NULL;
    ListNode* p1=pHead1, *p2=pHead2;
    // while(p1!=p2){
    //     if(p1==NULL)
    //         p1=pHead2;
    //     else
    //         p1=p1->next;
    //     if(p2==NULL)
    //         p2=pHead1;
    //     else
    //         p2=p2->next;
    // }
    while(p1!=p2){
        p1 = p1==NULL ? pHead2 : p1->next;
        p2 = p2==NULL ? pHead1 : p2->next;
    }
    return p1;
}