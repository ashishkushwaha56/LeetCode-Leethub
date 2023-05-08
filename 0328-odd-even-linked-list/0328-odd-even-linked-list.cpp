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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode*even = head;
        ListNode*odd = head->next;
        ListNode* temp1 = even;
        ListNode* temp2 = odd;
        while(true){
            if(odd->next==NULL) {even->next = odd->next;break;}
            even->next = odd->next;
            even=even->next;
            if(even->next==NULL){
                odd->next=even->next;
                break;
            }
            odd->next = even->next;
            odd=odd->next;
        }
        even->next = temp2;
        return temp1;
    }
};