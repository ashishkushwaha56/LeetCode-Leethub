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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left and !root->right) return 1;
        int a = minDepth(root->left);
        int b = minDepth(root->right);
        if(a == 0){
            return 1+b;
        }
        else if(b == 0){
            return 1+a;
        }
        return 1+min(a,b);
    }
};