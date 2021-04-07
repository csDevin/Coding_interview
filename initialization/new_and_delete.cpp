#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x):val(x), next(NULL){}
};

int main(){
    int *t = new int(1);  //***C++中，new返回的是指针
    ListNode *n1 = new ListNode(1);
    ListNode temp = {11};
    ListNode *n2 = &temp;
    n2->next = n1;
    delete n1;
    return 0;
}