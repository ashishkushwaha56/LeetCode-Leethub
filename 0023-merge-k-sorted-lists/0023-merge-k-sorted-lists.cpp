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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>> q;
        for(int i = 0;i<lists.size();i++){
            ListNode* head= lists[i];
            while(head!=NULL){
                q.push({head->val,head});
                head = head->next;
            }
            
        }
        if(q.size() == 0) return NULL;
       // priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>> p =q;
       //  while(!p.empty()){
       //      cout<<p.top().first<<endl;
       //      p.pop();
       //  }
        ListNode* temp = q.top().second;
        q.pop();
        ListNode* head =temp;
        while(!q.empty()){
            temp->next = q.top().second;
            temp = temp->next;
            q.pop();
        }
        return head;
    }
};