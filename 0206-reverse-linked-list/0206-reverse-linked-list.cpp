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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode * temp = NULL;
        ListNode * next = head->next;
        while(next!=NULL){
            head->next = temp;
            temp = head;
            head = next;
            next = next->next;
        }
        head->next = temp;
        temp = head;
        return head;
    }
};