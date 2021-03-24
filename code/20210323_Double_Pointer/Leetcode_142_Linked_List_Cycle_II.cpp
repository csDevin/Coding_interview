// 哈希表：用哈希表记录下访问过的元素
// 使用map
ListNode *detectCycle(ListNode *head) {
    ListNode *p=head;
    map<ListNode *, int> m;
    while(p!=nullptr)
    {
        if(m.find(p)!=m.end())
            return p;
        else
        {
            m[p] = 0;
            p = p->next;
        }   
    }
    return nullptr;
}


// 使用set
ListNode *detectCycle(ListNode *head) {
    ListNode *p=head;
    set<ListNode *> s;
    while(p!=nullptr)
    {
        if(s.find(p)!=s.end())
            return p;
        else
        {
            s.insert(p);
            p = p->next;
        }   
    }
    return nullptr;
}


// floyd判圈法（快慢指针）
/*
1. fast指针步幅为2，low指针步幅为1，从起点出发，直到第一次相遇。
2. 将fast指针移到链表起点，和low指针一起以步幅为1移动，直到第二次相遇，该相遇点即为入环点。
*/
ListNode *detectCycle(ListNode *head) {
    ListNode *fast=head, *low=head;
    // fast等于low的同时等于head 
    while(fast!=nullptr)
    {
        if(fast->next==nullptr)
            return nullptr;
        fast = fast->next->next;
        low = low->next;
        if(fast==low)
        {
            fast=head;
            while(fast!=low)
            {
                fast=fast->next;
                low=low->next;
            }
            return low;
        }        
    }
    return NULL;
}


// 自己的错误代码：超时错误
ListNode *detectCycle(ListNode *head) {
    ListNode *fast=head, *low=head;
    // while(fast!=low)  //***把fast!=low写while里是错误的，因为fast一开始就等于low，所以此处恒成立，不会执行while循环。
    while(fast!=low || fast==head)
    //***当fast==low或fast==head恒成立时，就会陷入死循环，例如[0, 2]和0时。
    {
        if(fast==nullptr || fast->next==nullptr)
            return nullptr;
        fast = fast->next->next;
        low = low->next;
    }
    fast=head;
    // [1,2]
    //  0
    while(fast!=low)
    {
        fast=fast->next;
        low=low->next;
    }
    return low;
}
// 改正后的代码
ListNode *detectCycle(ListNode *head) {
    ListNode *fast=head, *low=head;
    do  // do-while能完美地避免一开始判断条件就不满足的，从而不能执行while循环的问题。
    {
        if(fast==nullptr || fast->next==nullptr)
            return nullptr;
        fast = fast->next->next;
        low = low->next;
    }while(fast!=low);

    fast=head;
    
    while(fast!=low)
    {
        fast=fast->next;
        low=low->next;
    }
    return fast;
}