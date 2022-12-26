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
    void bfs(TreeNode *root,vector<int>&ans){
        queue<TreeNode*>q;
        TreeNode * temp;
        q.push(root);
        int res = INT_MIN;
        int t = 1,c = 0;
        bool ok = false;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            t--;
            ok = false;
            if(temp){
                res = max(res,temp->val);
                if(temp->left){
                    q.push(temp->left);
                    c++;
                }
                if(temp->right){
                    q.push(temp->right);
                    c++;
                }
                ok = true;
            }
            if(t == 0){
                if(ok)
                    ans.push_back(res);
                res = INT_MIN;
                t = c;
                c= 0;
            }
        }
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        bfs(root,ans);
        return ans;
    }
};