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
    vector<vector<int>> ans;
    void bfs(TreeNode *root){
        queue<TreeNode*> q;
        q.push(root);
        int t = 1;
        int c = 0;
        TreeNode* temp ;
        vector<int> d;
        while(!q.empty()){

        	temp = q.front();
            // if(temp!=NULL)
        	    d.push_back(temp->val);
        	q.pop();
        	t--;
            if(temp->left!=NULL){
            	c++;
            	q.push(temp->left);
            }
            if(temp->right!=NULL){
            	c++;
            	q.push(temp->right);
            }
            if(t == 0){
            	ans.push_back(d);
            	d.clear();
            	t = c;
            	c= 0;
            }
        }

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return ans;
    	bfs(root);
        return ans;
    }
};