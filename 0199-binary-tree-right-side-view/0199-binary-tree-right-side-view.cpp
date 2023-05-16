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
    void bfs(TreeNode *root){
        if(!root) return;
        queue<TreeNode*> q;
        TreeNode*temp;
        int t = 1;
        int c = 0;
        q.push(root);
        int d;
        while(!q.empty()){
            temp = q.front();
            d = temp->val;
            t--;
            q.pop();
            if(temp->left){
                q.push(temp->left);
                c++;
            }
            if(temp->right){
                q.push(temp->right);
                c++;
            }
            if(t==0){
                t = c;
                c = 0;
                ans.push_back(d);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return ans;
    }
};