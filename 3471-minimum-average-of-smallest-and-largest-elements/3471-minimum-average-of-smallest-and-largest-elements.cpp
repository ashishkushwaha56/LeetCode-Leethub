class Solution {
public:
    double minimumAverage(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int i = 0;
       int j = nums.size()-1;
       vector<double> ave;
        while(i<j){
            double c = (double)(nums[i]+nums[j])/2.0;
            ave.push_back(c);
            i++;
            j--;
        }
        sort(ave.begin(),ave.end());
        return ave[0];
    }
};