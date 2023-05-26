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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,int> mb = {{0,-1}};
        int l = -1;
        vector<int> v;
        while(head !=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        vector<int> temp = v;
        bool ok = false;
        int sum = 0;
        int d = 0;
        int last = -1;
        vector<int> md;
        while(!temp.empty()){
            ok = false;
            sum =  0;
            l = -1;
            last = -1;
            d = 0;
            for(int i = 0;i<temp.size();i++){
                // if(l != -1){
                //     if(sum+temp[i]!=sum){
                //         break;
                //     }
                // }
                sum+=temp[i];
                // if(ok){
                //     last = i;
                // }
                if(ok){
                    if(sum == d){
                        last = i;
                    }
                }
                else if(mb.find(sum)==mb.end()){
                    mb[sum] = i;
                }
                else if(!ok and mb.find(sum)!=mb.end()){
                    l = mb[sum]+1;
                    d = sum;
                    last = i;
                    ok = true;
                }
                
            }
            if(!ok) {
                break;
            }
            for(int i = 0;i<temp.size();i++){
                if(i<l or i>last){
                    md.push_back(temp[i]);
                }
            }
            temp = md;
            md.clear();
            mb.clear();
            mb = {{0,-1}};
        }
        ListNode* ans = new ListNode();
        ListNode* res = ans;
        int i = 0;
        while(i<temp.size()){
            ListNode* d = new ListNode(temp[i]);
            ans->next = d;
            ans=ans->next;
            i++;
        }
        
        return res->next;
    }
};