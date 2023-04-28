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
	vector<int> temp;
	void bfs1(TreeNode*root){
		queue<TreeNode*> q;
		q.push(root);
		TreeNode* tt;
		int t = 1;
		int c =0;
		int cnt = 0;
		while(!q.empty()){
			tt = q.front();
			q.pop();
			cnt+=tt->val;
			t--;
			if(tt->left){
				q.push(tt->left);
				c++;
			}
			if(tt->right){
				q.push(tt->right);
				c++;
			}
			if(t == 0){
				t = c;
				c = 0;
				temp.push_back(cnt);
                cnt=0;
			}
		}
	}

	void bfs2(TreeNode*root){
		queue<pair<TreeNode*,int>> q;
		q.push({root,root->val});
		int i = 0;
		pair<TreeNode*,int> tt;
		int t = 1;
		int c =0;
		// int cnt = 0;
		while(!q.empty()){
			tt = q.front();
			q.pop();
			// cnt+=tt->val;
			tt.first->val = temp[i]-tt.second;
			t--;
			if(tt.first->left and tt.first->right){
				q.push({tt.first->left,tt.first->left->val+tt.first->right->val});
				q.push({tt.first->right,tt.first->left->val+tt.first->right->val});
				c+=2;
			}
			else if(tt.first->left){
				q.push({tt.first->left,tt.first->left->val});
				c++;
			}
			else if(tt.first->right){
				q.push({tt.first->right,tt.first->right->val});
				c++;
			}
			if(t == 0){
				t = c;
				c = 0;
				i++;
				// temp.push_back(cnt);
			}
		}
	}
	TreeNode* replaceValueInTree(TreeNode*root){
		bfs1(root);
		bfs2(root);
        return root;
	}
};