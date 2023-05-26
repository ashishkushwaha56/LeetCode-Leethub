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
    queue<TreeNode*> q;
    // TreeNode* temp;
    int t = 1;
    vector<vector<int>> ans;
    vector<int> check(TreeNode* temp,int td){
        if(q.empty() or td == 0) return {};
        int d  =0;
        vector<int> a;
        for(int i = 0;i<td&& !q.empty();i++){
            temp = q.front();
            
            q.pop();

            if(temp)
                a.push_back(temp->val);
            if(temp and temp->left){
                d++;
                q.push(temp->left);
            }
            if(temp and temp->right){
                d++;
                q.push(temp->right);
            }
        }
        vector<int> b = check(temp,d);
        if(b.size()>0){
            ans.push_back(b);
        }
        return a;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        q.push(root);
        TreeNode *temp = q.front();
        vector<int> a = check(temp,1);
        if(a.size()>0) ans.push_back(a);
        return ans;
    }
};