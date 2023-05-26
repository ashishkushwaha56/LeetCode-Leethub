//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    void helper(Node * head,Node** front, Node** back){
        Node * slow_ = head;
        Node* fast_ = head->next;
        while(fast_!=NULL){
            fast_ = fast_->next;
            if(fast_!=NULL){
                slow_ = slow_->next;
                fast_ = fast_->next;
            }
        }
        *front = head;
        *back = slow_->next;
        slow_->next = NULL;
    }
    Node* merge(Node*a,Node*b){
        Node* temp = NULL;
        if(a ==NULL) return b;
        if(b == NULL )return a;
        if(a->data<=b->data){
            temp = a;
            temp->next = merge(a->next,b);
        }
        else{
            temp=b;
            temp->next = merge(a,b->next);
        }
        return temp;
    }
    void mergesort(Node** headref){
        Node *head = *headref;
        if((head) == NULL or (head)->next == NULL) return;
        Node* front = head;
        Node* back = head;
        helper(head,&front,&back);
        // Node* a = *;
        // Node* b = slow->next;
        // slow->next = NULL;
        mergesort(&front);
        mergesort(&back);
        Node* temp = merge(front,back);
        *headref=temp;
    }
    Node* mergeSort(Node* head) {
        // your code here
        mergesort(&head);
        return head;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends