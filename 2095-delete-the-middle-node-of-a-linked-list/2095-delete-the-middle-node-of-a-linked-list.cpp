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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        int n = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            n++;
            temp= temp->next;
        }
        int c= (n)/2-1;
        ListNode* prev = head;
        int i = 0;
        while(i<c){
            prev = prev->next;
            i++;
        }
        ListNode* next = prev->next;
        ListNode* n_next = next->next;
        prev->next = n_next;
        next->next = NULL;
        delete(next);
        return head;
    }
};