class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1!=NULL){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            s2.push(l2->val);
            l2=l2->next;
        }
        int i=0;
        ListNode*temp;
        int carry=0,a = 0,b = 0;
        while(!s1.empty() and !s2.empty()){
            if(i==0){
                a = s1.top();
                b = s2.top();
                i++;
                ListNode* d = new ListNode((carry+a+b)%10);
                carry = (carry+a+b)/10;
                temp = d;
                s1.pop();
                s2.pop();
            }
            else{
                a = s1.top();
                b = s2.top();
                // i++;
                ListNode* d = new ListNode((carry+a+b)%10);
                carry = (carry+a+b)/10;
                d->next = temp;
                temp = d;
                s1.pop();
                s2.pop();
            }
        }
        while(!s1.empty()){
            if(i==0){
                a = s1.top();
                i++;
                ListNode* d = new ListNode((carry+a)%10);
                carry = (carry+a)/10;
                temp = d;
                s1.pop();
            }
            else{
                a = s1.top();
                // i++;
                ListNode* d = new ListNode((carry+a)%10);
                carry = (carry+a)/10;
                d->next = temp;
                temp = d;
                s1.pop();
            }
        }
        while(!s2.empty()){
            if(i==0){
                b = s2.top();
                i++;
                ListNode* d = new ListNode((carry+b)%10);
                carry = (carry+b)/10;
                temp = d;
                s2.pop();
            }
            else{
                b = s2.top();
                // i++;
                ListNode* d = new ListNode((carry+b)%10);
                carry = (carry+b)/10;
                d->next = temp;
                temp = d;
                s2.pop();
            }
        }
        if(carry!=0){
            ListNode* d = new ListNode(carry);
            d->next = temp;
            temp = d;
        }
        return temp;
    }
};class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1!=NULL){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            s2.push(l2->val);
            l2=l2->next;
        }
        int i=0;
        ListNode*temp;
        int carry=0,a = 0,b = 0;
        while(!s1.empty() and !s2.empty()){
            if(i==0){
                a = s1.top();
                b = s2.top();
                i++;
                ListNode* d = new ListNode((carry+a+b)%10);
                carry = (carry+a+b)/10;
                temp = d;
                s1.pop();
                s2.pop();
            }
            else{
                a = s1.top();
                b = s2.top();
                // i++;
                ListNode* d = new ListNode((carry+a+b)%10);
                carry = (carry+a+b)/10;
                d->next = temp;
                temp = d;
                s1.pop();
                s2.pop();
            }
        }
        while(!s1.empty()){
            if(i==0){
                a = s1.top();
                i++;
                ListNode* d = new ListNode((carry+a)%10);
                carry = (carry+a)/10;
                temp = d;
                s1.pop();
            }
            else{
                a = s1.top();
                // i++;
                ListNode* d = new ListNode((carry+a)%10);
                carry = (carry+a)/10;
                d->next = temp;
                temp = d;
                s1.pop();
            }
        }
        while(!s2.empty()){
            if(i==0){
                b = s2.top();
                i++;
                ListNode* d = new ListNode((carry+b)%10);
                carry = (carry+b)/10;
                temp = d;
                s2.pop();
            }
            else{
                b = s2.top();
                // i++;
                ListNode* d = new ListNode((carry+b)%10);
                carry = (carry+b)/10;
                d->next = temp;
                temp = d;
                s2.pop();
            }
        }
        if(carry!=0){
            ListNode* d = new ListNode(carry);
            d->next = temp;
            temp = d;
        }
        return temp;
    }
};
