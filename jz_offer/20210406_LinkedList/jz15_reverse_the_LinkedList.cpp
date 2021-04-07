#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
// ListNode* ReverseList(ListNode* pHead) {
// // 思路1，不正规解法：遍历链表，用vector暂存链表每个元素的地址指针，然后反向遍历vector，用temp指针从头到尾重建nHead链表。
// // 不可行思路：遍历链表，用vector暂存每个指针的val，因为重建链表时，p->next=vec[i]的时候会报错。
//     // 定义一个新链表
//     if(pHead==NULL)
//         return NULL;
//     ListNode* p=pHead;
//     ListNode* nHead, *temp;
//     vector<ListNode*> vec;
//     while(p!=NULL){
//         vec.push_back(p);
//         p=p->next;
//     }
//     // 重建链表
//     nHead=vec[vec.size()-1];
//     temp = nHead;
//     for(int i=vec.size()-2; i>=0; i--){
//         temp->next=vec[i];
//         temp=temp->next;
//     }
//     temp->next=nullptr;
//     return nHead;
// }



// 正规解法：


int main()
{
    ListNode A[3] = {1, 2, 3};
    A[0].next = &A[1];
    A[1].next = &A[2];
    A[2].next = nullptr;
    
    ListNode p = ReverseList(A);
    int a = 1;
    return 0;
}
