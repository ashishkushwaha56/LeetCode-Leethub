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
    ListNode* tt;
    int dfs(ListNode* curr,ListNode* prev, int n,ListNode* head,bool &ok){
        if(curr==NULL) return 0;
        int a = dfs(curr->next,curr,n,head,ok);
        // cout<<curr->val<<" "<<prev->val<<endl;
        // cout<<a<<endl;
        if(ok) return 0;
        if(a == n-1){
            // cout<<1<<endl;
            if(n == 1){
                if(curr==head){
                    // cout<<2<<endl;
                    // cout<<curr->val<<" "<<head->val<<endl;
                    // cout<<head->next<<endl;
                    // curr->next= NULL;
                    ListNode* temp = head;
                    // temp = head;
                    tt=NULL;
                    // temp->next = NULL;
                    // delete temp;
                    // delete(temp);
                }
                else{
                    prev->next = curr->next;
                }
            }
            else {
                if(curr == head){
                    // cout<<1<<endl;
                    // head = head->next;
                    ListNode* temp = head;
                    // temp = head;
                    tt=tt->next;
                    // cout<<tt->val<<endl;
                    // temp->next = NULL;
                    // delete(temp);
                    // delete temp;
                }
                else
                {
                    prev->next = curr->next;
                }
            }
            
            ok = true;
        }
        return 1+a;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        bool ok = false;
        // if(head == NULL) return headl
        // if(head->next == NULL){
        //     return NULL;
        // }
        ListNode* curr = head;
        ListNode* prev = head;
        tt = head;
        int ans = dfs(curr,prev,n,head,ok);
        // cout<<tt->val<<endl;
        return tt;
    }
};