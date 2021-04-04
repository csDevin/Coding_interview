#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node{
    char x;
    char y;
};

int main(){
    int n;
    cin >> n;
    vector<struct Node> vec(n);
    for (int i = 0; i < n; i++){
        cin >> vec[i].x>>vec[i].y;
    }
    for (int i = 0; i < n; i++){
        cout << vec[i].x<<" "<< vec[i].y<<endl;
    }
    return 0;
}