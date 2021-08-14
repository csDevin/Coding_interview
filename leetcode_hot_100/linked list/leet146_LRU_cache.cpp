#include<bits/stdc++.h>
using namespace std;

/* STL双向链表库list<pair<int, int>>解法
unordered_map: map< key<int>, DListNode<DListNode*> >, 通过访问key来快速找到链表节点的位置
double_linked_list: list<pair<key, value>>实现，正常双向链表只需要存value，这里需要增加key是因为，当cache的capacity溢出的时候，
需要删除双向链表最后一个节点，此时，需要删除当前节点和hash map中的对应key。通过当前链表节点的key反向定位到hash map中的key，做两个删除操作即可。
*/

class LRUCache {
private:
    int cap;
    int count;  // 记录当前容量是多少
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> queue;

public:
    LRUCache(int capacity) {
        cap = capacity;
        count = 0;
    }

    int get(int key) {
        int res = -1;
        auto p = m.find(key);
        if (p != m.end()) {
            res = p->second->second;
            queue.erase(p->second);
            queue.push_front(make_pair(key, res));
            p->second = queue.begin();
        }
        return res;
    }

    void put(int key, int value) {
        auto p = m.find(key);
        if (p != m.end()) {
            queue.erase(p->second);
        }
        else if (count == cap) {
            int delkey = queue.back().first;
            queue.pop_back();
            m.erase(delkey);
        }
        else {
            ++count;
        }
        queue.push_front(make_pair(key, value));
        m[key] = queue.begin();
    }
};



/* 手写双向链表解法
*/
class LRUCache {
public:
    //定义双链表
    struct Node{
        int key,value;
        Node* prev, *next;
        Node(int _key,int _value): key(_key),value(_value),prev(NULL),next(NULL){}
    }*head,*tail;//双链表的最左和最右节点，不存贮值。
    int n;
    unordered_map<int,Node*>hash;

    void remove(Node* p)
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;
    }
    void insert(Node *p)
    {
        p->next = head->next;
        p->prev = head;
        head->next->prev = p;
        head->next = p;
    }
    LRUCache(int capacity) {
        n = capacity;
        head = new Node(-1,-1),tail = new Node(-1,-1);
        head->next = tail;  // 这里是双向链表，不是循环双向链表，所以虚头节点的prev不需要指向tail
        tail->prev = head;    
    }
    int get(int key) {
        if(hash.count(key) == 0) return -1; //不存在关键字 key 
        auto p = hash[key];
        remove(p);
        insert(p);//将当前节点放在双链表的第一位
        return p->value;
    }
    
    void put(int key, int value) {
        if(hash.count(key)) //如果key存在，则修改对应的value
        {
            auto p = hash[key];
            p->value = value;
            remove(p);
            insert(p);
        }
        else 
        {
            if(hash.size() == n) //如果缓存已满，则删除双链表最右侧的节点
            {
                auto  p = tail->prev;
                remove(p);
                hash.erase(p->key); //更新哈希表
                delete p; //释放内存
            }
            //否则，插入(key, value)
            auto p = new Node(key,value);
            hash[key] = p;
            insert(p);
        }
    }
};