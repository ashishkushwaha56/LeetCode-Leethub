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
        set<int> sd;
        if(head==NULL) return NULL;
        while(head!=NULL){
            sd.insert(head->val);
            head = head->next;
        }
        vector<int> v(sd.begin(),sd.end());
        int i = 0;
        ListNode * temp = new ListNode(0);
        ListNode *ans = temp;
        while(i<v.size()){
            ListNode* d = new ListNode(v[i]);
            temp->next = d;
            temp = temp->next;
            i++;
        }
        return ans->next;
    }
};