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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> a;
        while(head!=NULL){
            a.push_back(head->val);
            head=head->next;
        }
        stack<int> s;
        vector<int> ans(a.size());
        for(int i = a.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(a[i]);
            }
            else if(s.top()>a[i]){
                ans[i] = s.top();
                s.push(a[i]);
            }
            else{
                while(!s.empty() and s.top()<=a[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push(a[i]);
                }
                else{
                    ans[i] = s.top();
                    s.push(a[i]);
                }
                
                
            }
        }
        return ans;
    }
};