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
    
    TreeNode* dfs(vector<int>&pre,vector<int>&post,vector<int>&pre_id,vector<int>&post_id,vector<int>&vis,int i){
        TreeNode* root = new TreeNode(i);
        vis[i] = 1;
        bool ok1 = false;
        bool ok2 = false;
        if(pre_id[i]+1<=pre.size()-1){
            if(!vis[pre[pre_id[i]+1]]){
                vis[pre[pre_id[i]+1]] = 1;
                ok1 = true;
            }
        }
        if(post_id[i]-1>=0){
            if(!vis[post[post_id[i]-1]]){
                vis[post[post_id[i]-1]]=1;
                ok2 = true;
            }
        }
        if(pre_id[i]+1<=pre.size()-1){
            if(ok1){
                root->left = dfs(pre,post,pre_id,post_id,vis,pre[pre_id[i]+1]);
            }
        }
        if(post_id[i]-1>=0){
            if(ok2){
                root->right = dfs(pre,post,pre_id,post_id,vis,post[post_id[i]-1]);
            }
        }
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        vector<int> pre_id(preorder.size()+1),post_id(preorder.size()+1);
        vector<int> vis_pre(preorder.size()+1),vis_post(preorder.size()+1);
        for(int i = 0;i<preorder.size();i++){
            pre_id[preorder[i]] = i;
        }
        for(int i = 0;i<postorder.size();i++){
            post_id[postorder[i]] = i;
        }
        TreeNode * root = dfs(preorder,postorder,pre_id,post_id,vis_pre,preorder[0]);
        return root;
    }
};