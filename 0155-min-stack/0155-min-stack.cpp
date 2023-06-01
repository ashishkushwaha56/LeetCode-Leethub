class MinStack {
public:
    map<int,int> mb;
    stack<int> sb;
    MinStack() {
        
    }
    
    void push(int val) {
        sb.push(val);
        mb[val]++;
    }
    
    void pop() {
        int a = sb.top();
        sb.pop();
        mb[a]--;
        if(mb[a] == 0) mb.erase(a);
    }
    
    int top() {
        return sb.top();
    }
    
    int getMin() {
        auto it = mb.begin();
        return (*it).first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */