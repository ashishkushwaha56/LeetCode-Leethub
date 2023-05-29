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
    int sum = 0;
    int cnt = 0;
    void dfs(TreeNode* root,string &s){
        s+=(root->val+'0');
        if(!root->left and !root->right) {
            int i = 1;
            cnt = 0;
            // cout<<s<<endl;
            for(int j = s.size()-1;j>=0;j--){
                if(s[j] == '1') cnt+=i;
                i=i*2;
            }
            sum+=cnt;
            // sum+=(stoi(s));
            // return;
        }
        // if(!root) return;
        // cout<<s<<endl;
        
        if(root->left){
            dfs(root->left,s);
        }
        if(root->right){
            dfs(root->right,s);
        }
        s.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        string s=  "";
        dfs(root,s);
        return sum;
    }
};