/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,int> mb;
        map<int,Node*> mb1;
        int i = 0;
        Node* temp = new Node(0);
        Node* head1 = head;
        Node* head2= head;
        Node* head3 = head;
        i = 0;
        while(head1!=NULL){
            mb[head1] = i;
            head1 = head1->next;
            i++;
        }
        
        Node* ans = temp;
        Node* res = temp;
        while(head!=NULL){
            Node* d = new Node(head->val);
            temp->next = d;
            temp = temp->next;
            
            // i++;
            head = head->next;
        }  
        i = 0;
        head2 = ans->next;
        while(head2!=NULL){
            mb1[i] = head2;
            head2 = head2->next;
            i++;
        }
        // temp = ans->next;
        for(auto &it:mb){
            Node* from = it.first;
            if(from->random !=NULL){
                Node* to = (*mb.find(from->random)).first;
                int from_idx = it.second;
                int to_idx = (*mb.find(from->random)).second;
                mb1[from_idx]->random = mb1[to_idx];
            }
            
        }

        
        // if(res->next !=NULL){
        //     res = res->next;
        // }
        // while(res!=NULL){
        //     res->random = mb[]
        // }
        return ans->next;
    }
};