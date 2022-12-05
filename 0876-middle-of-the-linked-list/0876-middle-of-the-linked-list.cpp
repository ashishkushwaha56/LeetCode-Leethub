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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = head;
        while(temp->next!=NULL){
            if(temp->next!=NULL and temp->next->next!=NULL){
                prev = prev->next;
                temp=temp->next->next;
            }
            else if(temp->next!=NULL and temp->next->next==NULL){
                prev = prev->next;
                temp=temp->next;
            }
        }
        return prev;
    }
};