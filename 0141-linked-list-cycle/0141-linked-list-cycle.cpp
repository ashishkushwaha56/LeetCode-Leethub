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
        ListNode *slow = head;
        ListNode* fast = head;
        while(true){
            if(fast==NULL) return false;
            if(fast->next==NULL) return false;
            if(fast->next->next == NULL) return false;
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) return true;
        }
        return true;
    }
};