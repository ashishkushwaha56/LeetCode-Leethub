/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> v;
        function<void(TreeNode*)> dfs = [&](TreeNode* root)->void{
            if(!root) return ;
            v.push_back(root);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        bool ok = false;
        function<void(TreeNode* ,ListNode*)> dfs2 = [&](TreeNode* root,ListNode* head)->void{
            if(head == NULL) {
                ok = true;
                return;
            }
            if(!root) return;
            if(root->val!=head->val) return;
            dfs2(root->left,head->next);
            dfs2(root->right,head->next);
        };
        for(int i = 0;i<v.size();i++){
            dfs2(v[i],head);
        }
        return ok;
    }
};