class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(),false);
        int maxe = *max_element(candies.begin(),candies.end());
        for(int i = 0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxe){
                ans[i] = true;
            }
        }
        return ans;
    }
};