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
    int ans = 0;
	void dfs(TreeNode* root,int flag, int cnt){
		ans= max(ans,cnt);
		if(flag){
			if(root->left){
				dfs(root->left,0,cnt+1);
			}
			if(root->right){
				dfs(root->right,1,1);
			}
		}
		else{
			if(root->right){
				dfs(root->right,1,cnt+1);
			}
			if(root->left){
				dfs(root->left,0,1);
			}
		}
	}
    int longestZigZag(TreeNode* root) {
        if(root->left){
			dfs(root->left,0,1);
		}
		if(root->right){
			dfs(root->right,1,1);
		}
		return ans;
    }
};