class Solution {
public:
    bool hasCycle(ListNode *head) {
	
		// if head is NULL then return false;
        if(head == NULL)
            return false;
        
		// making two pointers fast and slow and assignning them to head
        ListNode *fast = head;
        ListNode *slow = head;
        
		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        
		// if traversal reaches to NULL this means no cycle.
        return false;
    }
};


//if LL has unique elements
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
    bool hasCycle(ListNode *head) {
        map<int, bool> mp;
        if(head != NULL && head->next != NULL)
        {
            while(head->next != NULL)
            {
                if(mp.find(head->val) != mp.end())
                    break;
                mp[head->val] = true;
                head = head->next;
            }
            if(head->next == NULL)
                return false;
            return true;
        }
        return false;
        
    }
};