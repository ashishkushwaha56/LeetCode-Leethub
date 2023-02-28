class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
  		int i = 0;
  		int j = people.size()-1;
  		sort(people.begin(),people.end());
  		int ans = 0;
  		while(i<=j){
  			if(people[i]+people[j]<=limit){
  				ans++;
  				i++;
  				j--;
  			}
  			else{
  				ans++;
  				j--;
  			}
  		}
  		return ans;
    }
};