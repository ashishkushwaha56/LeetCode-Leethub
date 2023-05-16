/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> ans;
    void bfs(Node *root,vector<int>&temp){
        if(!root) return;
        queue<Node*>q;
        Node* d;
        q.push(root);
        int t = 1;
        int c = 0;
        while(!q.empty()){
            d=q.front();
            temp.push_back(d->val);
            t--;
            q.pop();
            for(auto &it:d->children){
                if(it){
                    q.push(it);
                    c++;
                }
            }
            if(t == 0){
                t = c;
                c = 0;
                ans.push_back(temp);
                temp.clear();
            }
        }
        
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<int> temp;
        bfs(root,temp);
        return ans;
    }
};