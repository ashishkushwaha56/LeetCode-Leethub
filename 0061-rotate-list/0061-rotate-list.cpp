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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 or head == NULL) return head;
        ListNode* temp = head;
        int cnt = 1;
        while(temp->next!=NULL){
            cnt++;
            temp = temp->next;
        }
        temp->next = head;
        k = k%cnt;
        int t = cnt-k;
        while(t){
            temp = temp->next;
            t--;
            
        }
        head=temp->next;
        temp->next = NULL;
        return head;
    }
};