class Solution {
public:
	string f(int n){
		string ans= "";
		while(n){
			if(n&1) ans+='1';
			else ans+='0';
			n>>=1;
		}
		return ans;
	}
    int maximumXOR(vector<int>& nums) {
  		int cnt = 0;
  		vector<string> v(nums.size());
  		// string ans = "";
  		for(int i = 0;i<nums.size();i++){
  			v[i] = f(nums[i]);
  			while(v[i].size()<32){
  				v[i]+='0';
  			}
  			reverse(v[i].begin(),v[i].end());
  		}
  		string ans = string(32,'0');
  		int d;
  		for(int i = 31;i>=0;i--){
  			d = 0;
  			for(int j = 0;j<v.size();j++){
  				if(v[j][i] == '1') d++;
  			}
  			if(d&1) ans[i] = '1';
  			else{
  				if(d>0) ans[i] = '1';
  			}
  		}
  		long long i = 1;
  		for(int h = 31;h>=0;h--){
  			if(ans[h] == '1') cnt+=i;
  			i*=2;
  		}
  		return cnt;
    }
};