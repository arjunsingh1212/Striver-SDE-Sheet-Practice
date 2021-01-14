/* https://leetcode.com/problems/rotate-list/ */

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        
        int len=1;
        ListNode *temp=head;
        while(temp->next) 
        {
            len++;
            temp=temp->next;
        }
        temp->next=head;
        k=k%len;
        int cnt=1;
        temp=head;
        while(cnt<(len-k))
        {
            temp=temp->next;
            cnt++;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};