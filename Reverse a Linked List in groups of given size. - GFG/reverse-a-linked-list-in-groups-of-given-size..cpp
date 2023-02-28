//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        
        // int i = 0;
        vector<node*> a;
        node* temp = head;
        
        int j,d,cnt;
        int r;
        int flag = 0;
        while(temp!=NULL){
        	
        	for(int i = 0;i<k && temp!=NULL;i++){
            	a.push_back(temp);
            	temp = temp->next;
        	}
        // 	for(auto &it:a){
        // 	    cout<<it->data<<" ";
        // 	}
        // 	cout<<endl;
        	j = a.size()-k;
        	if(a.size()-(r+1)<k and flag){
        		j = r+1;
        	}
        	d = a.size()-1;
        	r = d;
        	if(!flag){
        	    flag = 1;
        	}
        	cnt = 0;
        	while(j<d){
        		cnt = a[j]->data;
        		a[j]->data = a[d]->data;
        		a[d]->data = cnt;
        		j++;
        		d--;
        	}
        }
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends