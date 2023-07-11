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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        int l = 0;
        for(int i = 0;i<v.size();i++){
            if(v[i]<x){
                int a = v[i];
                v.erase(v.begin()+i);
                v.insert(v.begin()+l,a);
                l++;
            }
        }
        ListNode* temp = new ListNode(0);
        ListNode* ans=temp;
        int i = 0;
        while(i<v.size()){
            ListNode* d = new ListNode(v[i]);
            temp->next =d;
            temp = temp->next;
            i++;
        }
        return ans->next;
    }
};