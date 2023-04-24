class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(auto &it:stones) {p.push(it);}
        int a,b;
        // while(!q.empty()){
        //     cout<<q.top()<<" ";
        //     q.pop();
        // }
        // cout<<endl;
        while(p.size()>1){
            a = p.top();
            p.pop();
            b = p.top();
            p.pop();
            
            // cout<<a<<" "<<b<<endl;
            // cout<<p.size()<<endl;
            if(abs(a-b)>0) p.push(abs(a-b));
        }
        return (p.size()==0?0:p.top());
    }
};