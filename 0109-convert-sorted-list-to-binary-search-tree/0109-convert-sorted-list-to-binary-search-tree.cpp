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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    TreeNode* divide(vector<int>&v,int l,int r){
        if(l<=r){
            int mid= l+(r-l)/2;
            TreeNode* temp = new TreeNode(v[mid]);
            // cout<<temp->val<<endl;
            temp->left = divide(v,l,mid-1);
            temp->right = divide(v,mid+1,r);
            return temp;
        }
        else{
            return NULL;
        }
    }
    TreeNode* sortedListToBST(ListNode* head) {
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        TreeNode *temp = divide(v,0,v.size()-1);
        return temp;
    }
};