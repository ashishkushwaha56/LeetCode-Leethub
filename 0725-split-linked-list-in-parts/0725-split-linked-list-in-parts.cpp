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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        vector<ListNode*> v;
        while(head!=NULL){
            v.push_back(head);
            head = head->next;
            len++;
        }
        while(v.size()<k){
            ListNode * temp = NULL;
            v.push_back(temp);
            len++;
        }
        vector<ListNode*> ans;
        int d = len/k;
        int mod = len%k;
        int i = 0;
        int cnt = 0;
        while(mod--){
            ans.push_back(v[i]);
            cnt = 0;
            while(cnt<d+1){
                // i++;
                if(cnt == d){
                    v[i]->next = NULL;
                }
                cnt++;
                i++;
            }
        }
        while(i<len){
            ans.push_back(v[i]);
            cnt = 0;
            while(cnt<d){
                if(cnt == d-1){
                    if(v[i]!=NULL)
                    v[i]->next  =NULL;
                }
                cnt++;
                i++;
            }
        }
        // while(ans.size()<)
        return ans;
    }
};