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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        for(auto &it:v){
            cout<<it<<" ";
        }
        cout<<endl;
        swap(v[k-1],v[v.size()-k]);
        ListNode* temp = new ListNode();
        ListNode* ans = temp;
        int i = 0;
        
        while(i<v.size()){
            ListNode *d = new ListNode(v[i]);
            temp->next  = d;
            temp = temp->next;
            i++;
        }
        return ans->next;
    }
};