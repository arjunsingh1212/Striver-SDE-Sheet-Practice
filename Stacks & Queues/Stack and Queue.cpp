/* https://leetcode.com/problems/lru-cache/ */

/* Credits: https://leetcode.com/problems/lru-cache/discuss/1029455/Runtime%3A-76-ms-faster-than-99.35-of-C%2B%2B-online-submissions */

/*
146. LRU Cache
Runtime: 76 ms, faster than 99.35% of C++ online submissions for LRU Cache.
Memory Usage: 39.7 MB, less than 97.66% of C++ online submissions for LRU Cache.
*/
class node{
public:
    int key;
    int val;
    node* next = nullptr;
    node* pre = nullptr;
    
    node(int k, int v){
        key = k;
        val = v;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        C = capacity;
        head = new node(-1, -1);
        tail = head;
    }
    
    int get(int key) {
        if( m.find(key) != m.end() ){
            node* curNode = m[key];
            
            if( curNode != tail ){
                node* pre = curNode->pre;
                node* next = curNode->next;
            
                pre->next = next;
                next->pre = pre;
            
                tail->next = curNode;
                curNode->pre = tail;
                tail = curNode;
            }
            
            return tail->val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if( m.find(key) != m.end() ){
            node* curNode = m[key];
            
            if( curNode != tail ){
                node* pre = curNode->pre;
                node* next = curNode->next;
            
                pre->next = next;
                next->pre = pre;
            
                tail->next = curNode;
                curNode->pre = tail;
                tail = curNode;
            }
            
            tail->val = value;
        }
        else{
            if( m.size() == C ){
                node *curNode = head->next;
                m.erase(curNode->key);
                
                if( curNode != tail ){
                    head->next = curNode->next;
                    curNode->next->pre = head;
                }
                else{
                    curNode->pre->next = nullptr;
                    tail = curNode->pre;
                }
                
                delete curNode;
            }
            
            node* curNode = new node(key, value);
            tail->next = curNode;
            curNode->pre = tail;
            tail = curNode;
            
            m[key] = tail;
        }
    }

private:
    int C;
    unordered_map<int, node*> m;
    node *head, *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */