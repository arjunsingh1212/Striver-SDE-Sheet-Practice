/* https://leetcode.com/problems/palindrome-linked-list/ */

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
    bool isPalin(ListNode* &left, ListNode* right)
    {
        if(right==NULL) return true;
        
        bool first=isPalin(left,right->next);
        
        if(!first) return false;
        bool second=left->val==right->val;
        left=left->next;
        return second;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        return isPalin(head,head->next);
    }
};