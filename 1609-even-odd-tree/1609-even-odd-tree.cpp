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
    vector<int> ans;
    bool bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int l = 1;
        int t = 1,c = 0;
        TreeNode* temp;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            ans.push_back(temp->val);
            t--;
            if(temp->left!=NULL) {
                c++;
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                c++;
                q.push(temp->right);
            }
            if(t == 0){
                t = c;
                c= 0;
                for(auto &it:ans){
                    cout<<it<<" ";
                }
                cout<<endl;
                cout<<l<<endl;
                if(l&1){
                    if(ans.size() == 1){
                        if(!(ans[0]&1)){
                            return false;
                        }
                    }
                    for(int i = 1;i<ans.size();i++){
                        if(!(ans[i-1]&1) or !(ans[i]&1) or ans[i]<=ans[i-1]){
                            return false;
                        }
                    }
                }
                else{
                    if(ans.size() == 1){
                        if((ans[0]&1)){
                            return false;
                        }
                    }
                    for(int i = 1;i<ans.size();i++){
                        if((ans[i-1]&1) or (ans[i]&1) or ans[i]>=ans[i-1]){
                            return false;
                        }
                    }
                }
                l++;
                ans.clear();
            }
        }
        // if(l&1){
        //             for(int i = 1;i<ans.size();i++){
        //                 if(!(ans[i]&1) or !(ans[i-1]&1) or ans[i]<=ans[i-1]){
        //                     return false;
        //                 }
        //             }
        //         }
        //         else{
        //             for(int i = 1;i<ans.size();i++){
        //                 if((ans[i]&1) or (ans[i-1]&1) or ans[i]>=ans[i-1]){
        //                     return false;
        //                 }
        //             }
        //         }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        return bfs(root);
    }
};