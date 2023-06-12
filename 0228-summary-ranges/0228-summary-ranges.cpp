class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0) return ans;
        int a = nums[0],b = nums[0];
        string s = "";
        
        for(int i = 1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1){
                if(a<b){
                    s = to_string(a)+"->"+to_string(b);
                }
                else{
                    s = to_string(a);
                }
                a = nums[i];
                ans.push_back(s);
            }
            else{
                b = nums[i];
            }
        }
        if(a<b){
                    s = to_string(a)+"->"+to_string(b);
                }
                else{
                    s = to_string(a);
                }
                ans.push_back(s);
                return ans;
    }
};