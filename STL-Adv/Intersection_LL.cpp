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
    int lenList(ListNode* head)
    {
        if(head==NULL) return 0;
        if(head->next==NULL) return 1;
        int len=0;
        while(head!=NULL)
        {
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=lenList(headA), lenB=lenList(headB);
        while(lenA>lenB)
        {
            headA=headA->next;
            lenA--;
        }
        while(lenB>lenA)
        {
            headB=headB->next;
            lenB--;
        }
        while(headA != headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
