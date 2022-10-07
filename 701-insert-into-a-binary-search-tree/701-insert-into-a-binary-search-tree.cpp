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
    // TreeNode* nodeinsert(int val){
    //     TreeNode* node = new TreeNode();
    //     node->val = val;
    //     node->left = NULL;
    //     node->right = NULL;
    //     return node;
    // }
    // TreeNode* dfs(TreeNode * root,int &val){
    //     if(root==NULL){
    //        return new TreeNode(val);
    //     }
    //     if(root->val<val){
    //         return root->left = dfs(root->left,val);
    //     }
    //     else{
    //         return root->right = dfs(root->right,val);
    //     }
    //     return root;
    // }
    TreeNode* insertIntoBST(TreeNode* root, int &val) {
       if(root==NULL){
           return new TreeNode(val);
        }
        if(val<root->val){
            root->left = insertIntoBST(root->left,val);
        }
        else{
            root->right = insertIntoBST(root->right,val);
        }
        return root;
    }
};