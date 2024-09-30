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
    ListNode* getMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right)
    {
        if(left==NULL) return right;
        if(right==NULL) return left;

        ListNode* dum=new ListNode();
        ListNode* prev=dum;
        while(left!=NULL && right!=NULL)
        {
            if(left->val < right->val)
            {
                prev->next=left;
                prev=left;
                left=left->next;
            }
            else
            {
                prev->next=right;
                prev=right;
                right=right->next;
            }
        }
        while(left!=NULL)
        {
            prev->next=left;
            prev=left;
            left=left->next;
        }
        while(right!=NULL)
        {
            prev->next=right;
            prev=right;
            right=right->next;
        }
        dum=dum->next;
        return dum;

    }
    ListNode* sortList(ListNode* head) { //mergeSort
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid = getMid(head);

        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};
