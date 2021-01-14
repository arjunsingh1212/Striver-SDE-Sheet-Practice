/* https://leetcode.com/problems/intersection-of-two-linked-lists/ */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *h1=headA, *h2=headB;
        if(h1==NULL || h2==NULL) return NULL;
        while(h1!=h2)
        {
            if(h1==NULL) h1=headB;
            if(h2==NULL) h2=headA;
            if(h1==h2) break;
            h1=h1->next;
            h2=h2->next;
        }
        return h1;
    }
};