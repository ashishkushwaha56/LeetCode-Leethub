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
    vector<int>ans;
    int a = 0;
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        TreeNode *temp;
        q.push(root);
        int t = 1;
        int c = 0;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            t--;
            ans.push_back(temp->val);
            if(temp->left !=NULL){
                c++;
                q.push(temp->left);
            }
            if(temp->right !=NULL){
                c++;
                q.push(temp->right);
            }
            if(t == 0){
                t =c;
                c = 0;
                a = accumulate(ans.begin(),ans.end(),0ll);
                ans.clear();
            }
        }
        
    }
    int deepestLeavesSum(TreeNode* root) {
        bfs(root);
        return a;
    }
};