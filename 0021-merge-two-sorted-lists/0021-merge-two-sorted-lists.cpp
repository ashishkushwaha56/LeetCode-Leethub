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
    ListNode* check(ListNode*l1,ListNode*l2){
        if(l1==NULL and l2 == NULL){
            return NULL;
        }
        else if(l1 == NULL and l2!=NULL){
            ListNode* temp = new ListNode();
            temp->val=l2->val;
            temp->next = check(l1,l2->next);
            return temp;
        }
        else if(l1!=NULL and l2 == NULL){
            ListNode*temp = new ListNode();
            temp->val = l1->val;
            temp->next = check(l1->next,l2);
            return temp;
        }
        
        
        if(l1->val<=l2->val){
            ListNode *temp = new ListNode();
            temp->val = l1->val;
            temp->next = check(l1->next,l2);
            return temp;
        }
        else{
            ListNode*temp = new ListNode();
            temp->val = l2->val;
            temp->next = check(l1,l2->next);
            return temp;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp = check(list1,list2);
        return temp;
    }
};