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
    vector<double> ans;
    void bfs(TreeNode *root){
        cout<<setprecision(5)<<fixed;
		queue<TreeNode*> q;
		TreeNode *temp;
		q.push(root);
		int t = 1;
		int c = 0;
		int d = 0;
		long long cnt = 0;
		while(!q.empty()){
			temp  = q.front();
            q.pop();
			t--;
			cnt+=temp->val;
			d++;
			if(temp->left){
				q.push(temp->left);
				c++;

			}
			if(temp->right){
				q.push(temp->right);
				c++;
			}
			if(t == 0){
				ans.push_back((double)cnt/d);
				t = c;
				c = 0;
				d = 0;
				cnt = 0;
			}

		}
	}
    vector<double> averageOfLevels(TreeNode* root) {
        cout<<setprecision(5)<<fixed;
        bfs(root);
		return ans;
    }
};