class Solution {
public:
    string largestNumber(vector<int>& nums) {
       vector<string> sd;
       for(auto &it:nums){
           sd.push_back(to_string(it));
       } 
       
       sort(sd.begin(),sd.end(),[&](string &a,string &b){
           return a+b>b+a;
       });
       if(sd[0] == "0") return "0";
       string ans = "";
       for(auto &it:sd){
           ans+=it;
       }
       return ans;
    }
};