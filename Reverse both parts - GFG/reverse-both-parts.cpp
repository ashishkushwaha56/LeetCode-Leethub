//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   
    Node *reverse(Node *head, int k)
    {
        // code here
        vector<Node*> v;
        Node * temp = head;
        for(int i = 0;i<k;i++){
            v.push_back(temp);
            temp  = temp->next;
        }
        int j = 0;
        int d = k-1;
        int cnt = 0;
        while(j<d){
            cnt = v[j]->data;
            v[j]->data = v[d]->data;
            v[d]->data = cnt;
            j++;
            d--;
        }
        while(temp!=NULL){
            v.push_back(temp);
            temp = temp->next;
        }
        j = k;
        d = v.size()-1;
        while(j<d){
            cnt = v[j]->data;
            v[j]->data = v[d]->data;
            v[d]->data = cnt;
            j++;
            d--;
        }
        return head;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends