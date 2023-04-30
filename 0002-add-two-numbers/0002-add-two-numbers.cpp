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
    ListNode* check(ListNode* l1,ListNode* l2, int carry){
        if(l1 == NULL and l2 ==NULL){
            if(carry!=0){
                return (new ListNode(carry));
            }
            else return NULL;
        }
        else if(l1 == NULL){
            ListNode* temp;
            // ListNode* d = check(l1,l2->next,(carry+l2->val)/10);
            temp = new ListNode((l2->val+carry)%10);
            temp->next = check(l1,l2->next,(carry+l2->val)/10);
            return temp;
        }
        else if(l2 == NULL){
            ListNode* temp;
            // ListNode* d = check(l1->next,l2,(carry+l1->val)/10);
            temp = new ListNode((carry+l1->val)%10);
            temp->next = check(l1->next,l2,(carry+l1->val)/10);
            return temp;
        }
        else{
            ListNode* temp;
            // ListNode* d = check(l1->next,l2->next,(carry+l1->val+l2->val)/10);
            temp = new ListNode((carry+l1->val+l2->val)%10);
            temp->next = check(l1->next,l2->next,(carry+l1->val+l2->val)/10);
            return temp;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head;
        head = check(l1,l2,carry);
        ListNode* temp = head;
        // while(temp!=NULL){
        //     cout<<temp->val<<" ";
        //     temp = temp->next;
        // }
        // cout<<endl;
        
        return head;
    }
};