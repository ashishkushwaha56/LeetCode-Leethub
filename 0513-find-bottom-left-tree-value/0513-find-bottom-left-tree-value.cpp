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
    vector<int> ans;
    int bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        int c = 0;
        int t = 1;
        
        while(!q.empty()){
            temp = q.front();
            q.pop();
            ans.push_back(temp->val);
            t--;
            if(temp->left!=NULL){
                c++;
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                c++;
                q.push(temp->right);
            }
            if(t==0){
                t = c;
                c = 0;
                ans.clear();
            }
        }
        // if(!ans.empty()){
            return ans[0];
        
        
    }
    int findBottomLeftValue(TreeNode* root) {
        return bfs(root);
        // return ans;
            
    }
};