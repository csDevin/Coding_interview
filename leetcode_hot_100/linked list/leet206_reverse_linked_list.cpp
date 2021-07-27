struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 // 虚头+存后指前
class Solution {
public:
    // head-use-after-free: 函数返回的值中包含已经被释放掉的内存。
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr != nullptr){
            // 存后指前,依次往后一步
            ListNode* tmp_next = curr->next;  // 存后
            curr->next = prev;  // 指前
            // 依次往后一步
            prev = curr;
            curr = tmp_next;
        }
        return prev;
    }
};