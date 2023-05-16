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
    void bfs(TreeNode*root,vector<vector<int>>&ans,vector<int>&temp){
        if(!root) return;
        queue<TreeNode*> q;
        TreeNode* d;
        q.push(root);
        int t = 1;
        int c = 0;
        int flag = 0;
        while(!q.empty()){
            d = q.front();
            temp.push_back(d->val);
            t--;
            q.pop();
            
            if(d->left){
                q.push(d->left);
                c++;
            }
            if(d->right){
                q.push(d->right);
                c++;
            }
            if(t==0){
                t = c;
                c= 0;
                if(flag == 0){
                    flag = 1;
                }
                else{
                    flag = 0;
                    reverse(temp.begin(),temp.end());
                    
                }
                ans.push_back(temp);
                temp.clear();
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        bfs(root,ans,temp);
        return ans;
    }
};