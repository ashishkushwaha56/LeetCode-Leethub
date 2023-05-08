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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL) return head;
        ListNode* ans;
        // ans->next = head;
        ListNode* temp = new ListNode();
        ListNode*prev = head;
        ListNode*curr = head->next;
        int flag = 0;
        int cnt = 0;
        while(curr!=NULL){
            flag = 0;
            if(prev->val == curr->val){
                flag=1;
                while(curr!=NULL and prev->val == curr->val){
                    curr=curr->next;
                }
                
            }
            if(!flag){
                temp->next = prev;
                
                cnt++;
                if(cnt == 1){
                    ans = temp->next;
                }
                temp=prev;
                prev = curr;
                if(curr == NULL) break;
                curr=curr->next;
            }
            else{
                
                // if(curr->next == NULL) break;
                prev=curr;
                if(prev == NULL) break;
                // if(prev->next == NULL) break;
                curr=prev->next;
            }
            
            
        }
        // cout<<prev->val;
        if(temp->next!=NULL and prev!=NULL){
            if(temp->next->val!=prev->val or temp->next == prev){
                temp->next = prev;
            cnt++;
            if(cnt == 1){
                ans = temp->next;
            }
            }
            else{
                temp->next =NULL;
            }
            
        }
        else{
            temp->next =NULL;
        }
        
        if(cnt == 0 and prev!=NULL) {
            temp->next= prev;
            cnt++;
            if(cnt == 1){
                ans = temp->next;
            }
        }
        else if(cnt == 0) {
            return NULL;
        }
        return ans;
    }
};