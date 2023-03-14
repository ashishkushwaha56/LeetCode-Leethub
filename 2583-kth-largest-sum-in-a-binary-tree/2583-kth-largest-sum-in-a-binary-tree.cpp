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
    vector<long long> v;
    void bfs(TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* temp;
        long long ans = 0;
        int t= 1;
        int c = 0;
        // long long cnt = 0;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            ans+=temp->val;
            t--;
            if(temp->left){
                q.push(temp->left);
                c++;
            }
            if(temp->right){
                q.push(temp->right);
                c++;
            }
            if(t == 0){
                t = c;
                c = 0;
                v.push_back(ans);
                ans = 0;
            }
        }
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        bfs(root);
        if(v.size()<k) return -1;
        sort(v.rbegin(),v.rend());
        return v[k-1];
    }
};