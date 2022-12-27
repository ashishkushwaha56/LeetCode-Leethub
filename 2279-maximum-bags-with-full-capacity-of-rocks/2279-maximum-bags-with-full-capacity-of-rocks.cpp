class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int k) {
        int n = capacity.size();
        priority_queue<int,vector<int>,greater<int>> p;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(capacity[i]-rocks[i]>0){
                p.push(capacity[i]-rocks[i]);
            }
            else{
                ans++;
            }
        }
        
        while(!p.empty() and k){
            if(k>=p.top()){
                ans++;
                k-=p.top();
                p.pop();
            }
            else{
                break;
            }
        }
        return ans;
    }
};