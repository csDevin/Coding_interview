#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
    return;
}

void bubble_sort(vector<int> &vec)
{
    int len = vec.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
    return;
}

int main()
{
    vector<int> vec = {7, 8, 90, 23, 21, 20, 1, 4, 65, 3, 3, 4, 50, 34, 33};
    bubble_sort(vec);
    for (auto p : vec)
    {
        cout << p << " ";
    }
    return 0;
}