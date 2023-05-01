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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode*forward = curr->next;
        head = curr;
        int ok = 0;
        while(forward!=NULL){
            // prev = forward->next;
            curr->next = prev;
            prev->next = forward->next;
            curr = prev->next;
            if(curr!=NULL){
                prev = forward;
                forward = curr->next;
            }
            else {
                ok = 1;
                break;
            }
        }
        if(ok ==0){
            curr->next = prev;
            prev->next = forward;
            
        }
        else{
            prev->next = forward;
        }
        return head;
        // return ans;
    }
};