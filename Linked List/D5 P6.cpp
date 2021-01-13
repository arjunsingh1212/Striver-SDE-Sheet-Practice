/* https://leetcode.com/problems/add-two-numbers/ */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy_head=new ListNode(0); 
        ListNode* temp=dummy_head;
        int sum=0,carry=0;
        while(l1 || l2 || carry)
        {
            sum=0;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            sum+=carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return dummy_head->next;
    }
};