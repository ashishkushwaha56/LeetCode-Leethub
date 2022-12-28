//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int ans = 0;
    void bfs1(Node*root){
        queue<Node*> q;
        Node*temp;
        q.push(root);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            ans = max(ans,temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    void bfs(Node*root,vector<vector<int>>&adj){
        queue<Node*> q;
        Node*temp;
        q.push(root);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp->left){
                adj[temp->data].push_back(temp->left->data);
                adj[temp->left->data].push_back(temp->data);
                q.push(temp->left);
            }
            if(temp->right){
                adj[temp->data].push_back(temp->right->data);
                adj[temp->right->data].push_back(temp->data);
                
                q.push(temp->right);
            }
        }
    }
    
    int bfs2(vector<vector<int>>&adj,vector<int>&vis,int start,int end){
        queue<int>q;
        int temp;
        q.push(start);
        vis[start] = 1;
        int t = 1;
        int c = 0;
        int res = 0;
        while(!q.empty()){
            temp = q.front();
            vis[temp]=1;
            q.pop();
            t--;
            if(temp == end){
                break;
            }
            for(auto &it:adj[temp]){
                if(!vis[it]){
                    q.push(it);
                    c++;
                }
            }
            if(t == 0){
                t = c;
                c = 0;
                res++;
            }
        }
        return res;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        bfs1(root);
        vector<vector<int>> adj(ans+1);
        vector<int> vis(ans+1);
        bfs(root,adj);
        return bfs2(adj,vis,a,b);
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends