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
    vector<int> v1,v2;
    void dfs1(TreeNode* root){
        // if(!root) {
        //     if(flag) v1.push_back(-1);
        //     if(!flag) v2.push_back(-1);
        //     return;
        // }
        v1.push_back(root->val);
      
        if(!root->left){
             v1.push_back(-101);
            
            
        }
        else if(root->left){
            dfs1(root->left);
        }
        
        if(!root->right){
            v1.push_back(-102);
            
            
        }
        else if(root->right){
            dfs1(root->right);
        }
        // dfs(root->right,flag);
        
    }
    void dfs2(TreeNode* root){
        // if(!root) {
        //     if(flag) v1.push_back(-1);
        //     if(!flag) v2.push_back(-1);
        //     return;
        // }
        
      
        if(!root->left){
             v2.push_back(-101);
            
            
        }
        else if(root->left){
            dfs2(root->left);
        }
        
        if(!root->right){
            v2.push_back(-102);
            
            
        }
        else if(root->right){
            dfs2(root->right);
        }
        v2.push_back(root->val);
        // dfs(root->right,flag);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root->left and !root->right) return true;
        if(root->left)
            dfs1(root->left);
        if(root->right)
            dfs2(root->right);
        reverse(v2.begin(),v2.end());
        for(auto &it:v1){
            cout<<it<<" ";
        }
        cout<<endl;
        
        for(auto &it:v2){
            cout<<it<<" ";
        }
        cout<<endl;
        
        bool ans = true;
        if(v1.size()!=v2.size()) return false;
        for(int i = 0;i<v2.size();i++){
        	if(v1[i]<-100){
        		if(v1[i] == -101 and v2[i]!=-102){
        			ans = false;
        			break;
        		}
        		if(v1[i] == -102 and v2[i]!=-101){
        			ans = false;
        			break;
        		}
                if(v1[i]<-100 and v2[i]>=-100){
                    ans = false;
                    break;
                }
        		continue;
        	}
        	if(v2[i]<-100){
        		if(v2[i] == -101 and v1[i]!=-102){
        			ans = false;
        			break;
        		}
        		if(v2[i] == -102 and v1[i]!=-101){
        			ans = false;
        			break;
        		}
                if(v2[i]<-100 and v1[i]>=-100){
                    ans = false;
                    break;
                }
        		continue;
        	}
        	if(v1[i]!=v2[i]){
        		ans = false;
        		break;
        	}
        }
        return ans;
    }
};