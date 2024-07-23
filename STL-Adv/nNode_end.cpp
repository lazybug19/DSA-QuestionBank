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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=1, i=1;
        ListNode* tail=head;
        while(tail->next!=NULL)
        {
            tail=tail->next;
            count++;
        }
        if(n==count)
        {
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        tail=head;
        while(i!=count-n)
        {
            tail=tail->next;
            i++;
        }
        ListNode* del=tail->next;
        tail->next=tail->next->next;
        delete del;

        return head;
    }
};
