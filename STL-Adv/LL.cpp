
 /*struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry  = 0;
        ListNode* head = new ListNode();
        ListNode* temp = head;
        while(l1->next != NULL || l2->next != NULL)
        {
            int sum = 0;
            sum = l1->val + l2->val;
            sum += carry;
            carry = sum/10;
            ListNode* f = new ListNode(sum%10);
            head->next = f;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        return temp->next;
    }
};