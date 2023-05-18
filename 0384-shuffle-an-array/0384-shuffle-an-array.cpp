class Solution {
public:
    vector<int> v,temp;
    int n;
    Solution(vector<int>& nums) {
        srand(time(0));
        temp = nums;
        v=nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        return temp;
    }
    
    vector<int> shuffle() {
        int a= rand()%n;
        int b = rand()%n;
        swap(v[a],v[b]);
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */