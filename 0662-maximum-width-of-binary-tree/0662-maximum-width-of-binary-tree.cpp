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
    int bfs(TreeNode*root){
        queue<pair<TreeNode*,long long>> q;
        if(!root) return 0;
        q.push({root,0});
        int ans = 1;
        int a,b,d,x;
        
        while(!q.empty()){
            x= q.size();
            a = 0,b = 0;
            d = q.front().second;
            long long k;
            for(int i=0;i<x;i++){
                auto p = q.front();
                k = p.second-d;
                if(i == 0) a = k;
                if(i == x-1) b = k;
                
                q.pop();
                
                if(p.first->left){
                    q.push({p.first->left,2*k+1});
                }
                if(p.first->right){
                    q.push({p.first->right,2*k+2});
                }
                
                
            }
            ans = max(ans,b-a+1);
        }
        return ans;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return bfs(root);
    }
};