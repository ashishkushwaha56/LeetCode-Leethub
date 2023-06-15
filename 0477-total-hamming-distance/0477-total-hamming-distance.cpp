class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<string> v(nums.size());
        string a = "";
        int d;
        for(int i = 0;i<nums.size();i++){
            a = "";
            d = nums[i];
            while(d){
                if(d&1)a+='1';
                else a+='0';
                d>>=1;
            }
            while(a.size()<32){
                a+='0';
            }
            v[i] = a;
        }
        int zero =0;
        int one = 0;
        int ans =0;
        for(int i = 0;i<32;i++){
            zero = 0;
            one = 0;
            for(int j = 0;j<v.size();j++){
                if(v[j][i] == '1'){
                    ans+=zero;
                    one++;
                }
                else{
                    ans+=one;
                    zero++;
                }
            }
        }
        return ans;
    }
};