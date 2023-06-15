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
    
    int maxLevelSum(TreeNode* root) {
        int ans = root->val;
        int cnt = 0;
        queue<TreeNode*> q;
        TreeNode*temp;
        q.push(root);
        int t = 1;
        int c = 0;
        int i=1;
        int id = 1;
        while(!q.empty()){
            temp = q.front();
            cnt+=temp->val;
            q.pop();
            t--;
            if(temp->left){
                c++;
                q.push(temp->left);
            }
            if(temp->right){
                c++;
                q.push(temp->right);
            }
            if(t==0){
                t =c;
                c = 0;
                if(ans<cnt){
                    ans = cnt;
                    id = i;
                }
                // ans = max(ans,cnt);
                cnt = 0;
                i++;
            }
        }    
        return id;
    }
};