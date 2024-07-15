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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> parent,child;
        for(auto &it:descriptions){
            if(parent.find(it[0])==parent.end()){
                TreeNode* temp = new TreeNode(it[0]);
                parent[it[0]] = temp;
            }
            if(parent.find(it[1])==parent.end()){
                TreeNode* temp=new TreeNode(it[1]);
                parent[it[1]] = temp;
            }
        }
        for(auto &it:descriptions){
            int children = it[1];
            if(parent.find(children)!=parent.end()){
                child[children] = parent[children];
                if(parent.find(it[0])!=parent.end()){
                    if(it[2] == 1){
                        TreeNode* temp = parent[it[0]];
                        temp->left = parent[children];
                    }
                    else{
                        TreeNode* temp = parent[it[0]];
                        temp->right = parent[children];
                    }
                }
                else{
                    if(it[2] == 1){
                        TreeNode* temp = child[it[0]];
                        temp->left = child[children];
                    }
                    else{
                        TreeNode* temp = child[it[0]];
                        temp->right = child[children];
                    }
                }
                
                parent.erase(children);
            }
            // else{
            //     if()
            // }
        }
        auto it = parent.begin();

        return (*it).second;
    }
};