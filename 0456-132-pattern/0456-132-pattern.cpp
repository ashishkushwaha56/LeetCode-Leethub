class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int,int>> sd;
        vector<int> a(nums.size());
        int minele = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            minele = min(minele,nums[i]);
            a[i] = minele;
        }
        if(nums.size()<=2) return false;
        for(int i = 0;i<nums.size();i++){
            if(i<=1){
                if(sd.empty()){
                    sd.push({nums[i],i});
                }
                else{
                    if(sd.top().first<=nums[i]){
                        sd.pop();
                    }
                    sd.push({nums[i],i});
                }
            }
            else{
                while(!sd.empty() and sd.top().first<=nums[i]){
                    sd.pop();
                }
                if(!sd.empty()){
                    int d = sd.top().second;
                    if(d>0){
                        if(a[d-1]<nums[d] and a[d-1]<nums[i]) return true;
                    }
                }
                sd.push({nums[i],i});
            }
        }
        return false;
    }
};