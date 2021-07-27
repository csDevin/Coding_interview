#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// solution 1: linked list to array & double pointer judge
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr){
            return true;
        }
        vector<int> nums;
        ListNode* p = head;
        while(p != nullptr){
            nums.push_back(p->val);
            p = p->next;
        }
        int len = nums.size();
        int left=0, right=len-1;
        while(left<right){
            if(nums[left]==nums[right]){
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
};



// solution 2: fast-slow pointers & reverse linked list
// note: fast-slow pointers both initialized with -1
// find the middle node (when odd number, is belong to the first half part; when even number, is just in the middle position)
// we define a function called find first half end: first_half_end, then we reverse(first_half_end->next),we can prove that 
// first half must be less than second half.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // find the first half end
        ListNode* first_half_end = find_first_half_end(head);
        ListNode* second_end_start = reverse_linked_list(first_half_end->next);
        ListNode* left = head;
        ListNode* right = second_end_start;
        while(right != nullptr){  // due to the shorter lenght of second half part
            if(right->val != left->val)
                return false;
            //***fast-slow pointer or double pointer endless loop: may have forgotten to move the pointer.
            left = left->next;
            right = right->next;
        }
        return true;
    }

    // note: fast&fast->next&fast->next->next all can not equal to nullptr
    ListNode* find_first_half_end(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // 定义虚拟头节点,存后指前,依次往后一步
    ListNode* reverse_linked_list(ListNode* head){
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