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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr)
        {
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* revHalf=reverseList(slow);
        while(revHalf)
        {
            if(revHalf->val != head->val) return false;
            head=head->next;
            revHalf=revHalf->next;
        }
        return true;
    }
};
