/* https://leetcode.com/problems/middle-of-the-linked-list/ */

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
    ListNode* middleNode(ListNode* head) {
        // int count=0;
        // ListNode* start=head;
        // while(start!=NULL)
        // {
        //     count++;
        //     start=start->next;
        // }
        // count/=2;
        // int c=0;
        // start=head;
        // while(c<count)
        // {
        //     c++;
        //     start=start->next;
        // }
        // return start;
        
        ListNode* sp=head;
        ListNode* fp=head;
        while(fp!=NULL && fp->next!=NULL)
        {
            fp=fp->next->next;
            sp=sp->next;
        }
        return sp;
    }
};