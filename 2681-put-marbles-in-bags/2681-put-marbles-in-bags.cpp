class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        priority_queue<long long> pq1;
        priority_queue<long long,vector<long long>,greater<long long>> pq2;
        for(int i = 0;i<v.size()-1;i++){
            pq1.push(v[i]+v[i+1]);
            pq2.push(v[i]+v[i+1]);
            if(pq1.size()>k-1){
                pq1.pop();
                pq2.pop();
            }
        }
        long long ans = 0;
        while(!pq1.empty()){
            ans+=(pq2.top()-pq1.top());
            pq1.pop();
            pq2.pop();
        }
        return ans;
    }
};