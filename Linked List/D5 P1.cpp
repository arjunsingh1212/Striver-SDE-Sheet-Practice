/* https://leetcode.com/problems/reverse-linked-list/ */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL) return head; //Empty List
        
        if(head->next==NULL)
            return head;
        
        ListNode* temp=reverseList(head->next);
        
        head->next->next=head; //This is to change the links.        
        head->next=NULL; //This is tricky. Note that we are unwiding recursion, so after one step, head->next will point to its proper place, for now we placing NULL here, becuase first node will have to point to null at the end
        
        return temp; //This will have the returned head, which was base case for the last node.
        
    }
};

//Iterative

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* cur=head;
        ListNode* nxt=cur;
        ListNode* prev=NULL;
        while(cur)
        {
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
        
    }
};