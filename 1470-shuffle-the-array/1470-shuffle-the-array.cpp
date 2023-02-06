class Solution {
public:
    vector<int> shuffle(vector<int>& v, int n) {
        vector<int> ans;
		for (int i = 0; i < n; i++) {
			ans.push_back(v[i]);
			ans.push_back(v[i + n]);
		}
		return ans;
    }
};