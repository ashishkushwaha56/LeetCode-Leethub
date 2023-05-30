class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       vector<int> ans;
       int d;
       if(nums.size()%3 == 0){
           d = nums.size()/3;
           d++;
       }
       else{
           d = nums.size()/3;
           d++;
       }
       map<int,int> cd;
       for(int i = 0;i<nums.size();i++){
           cd[nums[i]]++;
       } 
       for(auto &it:cd){
           if(it.second>=d){
               ans.push_back(it.first);
           }
       }
       return ans;
    }
};