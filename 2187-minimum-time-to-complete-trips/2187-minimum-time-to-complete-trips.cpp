class Solution {
public:
	bool check(vector<int>&time,int d, long long mid){
		long long cnt = 0;
		for(int i = 0;i<time.size();i++){
			cnt+=(mid/time[i]);
		}
		return cnt>=d;
	}
    long long minimumTime(vector<int>& time, int totalTrips) {
  		long long ans = 100000000000000;
  		long long l = 1;
  		long long r = ans;
  		while(l<=r){
  			long long mid = l+(r-l)/2;
            // cout<<mid<<endl;
  			if(check(time,totalTrips,mid)){
  				ans = mid;
  				r = mid-1;
  			}
  			else{
  				l = mid+1;
  			}
  		}      
  		return ans;
    }
};