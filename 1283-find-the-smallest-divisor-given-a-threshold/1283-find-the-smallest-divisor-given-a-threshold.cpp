class Solution {
public:
	bool check(vector<int>&v,int d,int mid){
		int cnt = 0;
		for(int i= 0;i<v.size();i++){
			cnt+=ceil((long double)v[i]/mid);
		}
		return cnt<=d;
	}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = 1000001;
        int ans = r;
        while(l<=r){
        	int mid = l+(r-l)/2;
        	if(check(nums,threshold,mid)){
        		ans=mid;
        		r = mid-1;
        	}
        	else{
        		l = mid+1;
        	}
        }
        return ans;
    }
};