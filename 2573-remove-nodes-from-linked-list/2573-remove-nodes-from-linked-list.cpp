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
    ListNode* removeNodes(ListNode* head) {
        // stack<int> sd;
        
        vector<int> v;
        vector<int> ad;
        while(head!=NULL){
            v.push_back(head->val);
            head = head->next;
        }
        int maxd = v[v.size()-1];
        ad.resize(v.size(),1);
        ad[v.size()-1] = 1;
        for(int i = v.size()-2;i>=0;i--){
            if(v[i]<maxd){
                ad[i] =0;
            }
            maxd = max(v[i],maxd);
        }
        ListNode* temp = new ListNode(0);
        head = temp;
        int i = 0;
        while(i<ad.size()){
            if(ad[i]){
                ListNode* d = new ListNode(v[i]);
                temp->next = d;
                temp = temp->next;
            }
            i++;
        }
        return head->next;

    }
};