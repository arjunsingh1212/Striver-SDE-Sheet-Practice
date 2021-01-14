/* https://leetcode.com/problems/reverse-nodes-in-k-group/ */

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        
        int cnt=0;
        ListNode *counter=head;
        while(counter)
        {
            cnt++;
            counter=counter->next;
        }
        
        ListNode* prev=dummy, *cur, *nxt;
        while(cnt>=k)
        {
            cur=prev->next;
            nxt=cur->next;
            int c=k-1;
            while(c)
            {
                cur->next=nxt->next;
                nxt->next=prev->next;
                prev->next=nxt;
                nxt=cur->next;
                c--;
            }
            prev=cur;
            cnt-=k;
        }
        return dummy->next;
    }
};