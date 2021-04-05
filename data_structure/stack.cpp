#include<stack>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

int main(){
    vector<int> vec1, vec2;
    queue<int> q1, q2;
    stack<int> stk1, stk2;
    for (int i = 0; i < 5;i++)
        stk1.push(i);
    stk2.swap(stk1);
    int a = 0;
    return 0;
}