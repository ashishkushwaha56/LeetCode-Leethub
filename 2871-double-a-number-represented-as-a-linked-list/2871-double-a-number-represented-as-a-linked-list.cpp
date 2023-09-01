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
    ListNode* doubleIt(ListNode* head) {
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->val);
            head = head->next;
        }
        int carry = 0;
        for(int i = v.size()-1;i>=0;i--){
            int a = v[i];
            v[i] = (a*2+carry)%10;
            carry = (a*2+carry)/10;
        }
        if(carry!=0){
            reverse(v.begin(),v.end());
            v.push_back(carry);
            reverse(v.begin(),v.end());
        }
        ListNode * temp = new ListNode(0);
        ListNode *ans = temp;
        int i = 0;
        while(i<v.size()){
            ListNode * d = new ListNode(v[i]);
            temp->next = d;
            temp = temp->next;
            i++;
        }
        return ans->next;
    }
};