//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    Node *primeList(Node *head){
        Node * temp = head;
        bool tl = true;
        while(temp!=NULL){
            int t1;
            tl=true;
            if(temp->val == 1) {temp->val = 2; temp=temp->next;continue;}
            if(temp->val == 2) {temp = temp->next; continue;}
            int i = temp->val;
            if(!(i&1) and i!=2) i--;
            for(;i>=sqrt(temp->val);i-=2){
               for(int j = 2;j*j<=i;j++){
                   if(i%j ==0){
                       tl = false;
                       break;
                   }
               }
               if(tl){
                   t1 = i;
                   break;
               }
               tl = true;
            }
            int k = temp->val;
            if(!(k&1) and k!=2) k++;
            int t2;
            tl = true;
            for(;k<=temp->val*temp->val;k+=2){
               for(int j = 2;j*j<=k;j++){
                   if(k%j ==0){
                       tl = false;
                       break;
                   }
               }
               if(tl){
                   t2 = k;
                   break;
               }
               tl = true;
            }
            int d;
            if(temp->val-t1>t2-temp->val){
                d = t2;
            }
            else if(temp->val-t1<t2-temp->val){
                d = t1;
            }
            else{
                d = t1;
            }
            temp->val = d;
            temp=temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends