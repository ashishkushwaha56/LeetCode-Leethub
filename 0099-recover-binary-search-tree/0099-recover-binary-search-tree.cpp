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
    vector<TreeNode*> v;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        v.push_back(root);
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        vector<TreeNode*> temp = v;
        sort(temp.begin(),temp.end(),[&](TreeNode*a,TreeNode*b){
            return a->val<b->val;
        });
        bool ok1 = false,ok2 = false;
        TreeNode* l1;
        TreeNode* l2;
        for(int i = 0;i<v.size();i++){
            if(v[i]->val!=temp[i]->val){
                if(!ok1){
                    ok1=true;
                    l1 = v[i];
                }
                else{
                    l2 = v[i];
                }
            }
        }
        int a = l1->val;
        l1->val = l2->val;
        l2->val = a;
        
    }
};