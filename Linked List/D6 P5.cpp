/* https://leetcode.com/problems/linked-list-cycle-ii/ */

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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* fp=head, *sp=head;
        while(fp && fp->next)
        {
            fp=fp->next->next;
            sp=sp->next;
            if(sp==fp) break;
        }
        if(sp!=fp) return NULL;
        fp=head;
        while(sp!=fp)
        {
            sp=sp->next;
            fp=fp->next;
        }
        return sp;
    }
};