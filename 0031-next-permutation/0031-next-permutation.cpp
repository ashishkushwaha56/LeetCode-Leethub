class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = 0;
        
        do {
            i++;
            if(i == 2){
                break;
            }
        }while(next_permutation(nums.begin(),nums.end()));
    }
};