class StockSpanner {
public:
    stack<pair<int,int>> s;
    int i = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        if(s.empty()){
            s.push({price,i});
        }
        else{
            int l = i;
            while(!s.empty() and s.top().first<=price){
                s.pop();
            }
            if(!s.empty()){
                cnt+=(i-s.top().second-1);    
            }
            else{
                cnt+=i;
            }
            s.push({price,i});
        }
        i++;
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */