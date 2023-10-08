class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int left = 0;
        int right = 0;
        int i = 0;
        long long ans = 0;
        while(i<prices.size()){
            if(i<prices.size()-1){
                if(prices[i]-prices[i+1] !=1){
                    ans+=((long long)(right-left+1)*(right-left+2))/2;
                    left = i+1;
                    right = i+1;
                }
                else{
                    right = i+1;
                }
            }
            i++;
        }
        ans+=((long long)(right-left+1)*(right-left+2))/2;
        return ans;
    }
    
};