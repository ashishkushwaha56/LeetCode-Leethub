class Solution {
public:
    int halveArray(vector<int>& nums) {
        int ans = 0;
        priority_queue<long double> p;
        long double d = accumulate(nums.begin(),nums.end(),0ll)/2.0;
        for(int i = 0;i<nums.size();i++){
            p.push((long double)nums[i]);
        }
        long double g = 0;
        long double a;
        while(true){
            if(g>=d){
                break;
            }
            a = p.top();
            g+=a/2;
            p.pop();
            p.push(a/2);
            ans++;
        }
        return ans;
        
    }
};