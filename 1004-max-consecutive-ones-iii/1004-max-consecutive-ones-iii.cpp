class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        int ans = 0;
        
		vector<int> temp;
		for(int i = 0;i<v.size();i++){
			if(v[i] == 0) temp.push_back(i); 
		}
        if(k == 0){
           int cnt = 0;
            for(int i = 0;i<v.size();i++){
                if(v[i] == 0){
                    ans =max(ans,cnt);
                    cnt = 0;
                }
                else {
                    cnt++;
                }
            }
            ans = max(ans,cnt);
            return ans;
        }
		if(k>=temp.size()) return v.size();
		int l,r;
        // for(auto &it:temp){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
		for(int i = 0;i<=temp.size()-k;i++){
            // cout<<temp[i]<<" "<<temp[i+k]<<endl;
			if(i == 0) l = 0;
			else if(i>0) l = temp[i-1]+1;

			if(i+k-1 == temp.size()-1) r = v.size()-1;
			else if(i+k-1<temp.size()-1) r = temp[i+k]-1;
            
			ans = max(ans,r-l+1);
		}
		return ans;
    }
};