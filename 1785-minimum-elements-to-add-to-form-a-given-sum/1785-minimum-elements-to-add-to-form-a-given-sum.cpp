class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
        long long t;
        if(sum>0 and goal<0){
            t = sum-goal;
            
        }
        else if((sum<0 and goal<0) or (sum>0 and goal>0)){
            t = abs(sum-goal);
        }
        else if(sum<0 and goal>0){
            t = goal-sum;
        }
        else if( sum == 0 or goal == 0){
            t = abs(sum-goal);
        }
        int ans = ceil((long double)t/limit);
        return ans;
    }
};