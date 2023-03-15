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
    bool bfs(TreeNode*root){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        vector<int> v;
        v.push_back(root->val);
        bool ok = true;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            
            if(temp->left){
                v.push_back(temp->left->val);
                q.push(temp->left);
            }
            if(!temp->left){
                v.push_back(-1);
            }
            if(temp->right){
                v.push_back(temp->right->val);
                q.push(temp->right);
            }
            
            if(!temp->right){
                v.push_back(-1);
            }
            
        }
        // for(auto &it:v){
        //     cout<<it<<" "; 
        // }
        // cout<<endl;
        for(int i = 0;i<v.size();i++){
            if(v[i] == -1 and ok){
                ok = false;
            }
            if(v[i]!=-1 and !ok){
                return false;
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        return bfs(root);
    }
};