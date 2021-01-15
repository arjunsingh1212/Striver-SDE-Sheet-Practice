/* https://leetcode.com/problems/copy-list-with-random-pointer/ */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node *cur, *nxt;
        cur=head;
        while(cur)
        {
            nxt=cur->next;
            Node *new_node=new Node(cur->val);
            cur->next=new_node;
            new_node->next=nxt;
            cur=nxt;
        }
        
        cur=head;
        while(cur)
        {
            if(cur->random)
                cur->next->random=cur->random->next; //Maing it point to cloned node
            cur=cur->next->next;
        }
        
        cur=head;
        Node *pseudoHead=new Node(0);
        Node *itr=pseudoHead;
        while(cur)
        {
            nxt=cur->next->next;
            itr->next=cur->next;
            cur->next=nxt;
            itr=itr->next;
            cur=nxt;
        }
        
        return pseudoHead->next;
    }
};