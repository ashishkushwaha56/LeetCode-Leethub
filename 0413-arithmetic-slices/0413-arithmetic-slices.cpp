class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		map<int, int> mb;
		int ans = 0;
		int l = 0;
		int i;
		for (i = 1; i < nums.size(); i++) {
			mb[nums[i] - nums[i - 1]]++;
			if (mb.size() > 1) {
				if (i - l >= 3) {
					ans += ((i - l) * (i - l + 1)) / 2;
					ans -= (i - l);
					ans -= (i - l - 1);
				}
				l = i - 1;
				mb.clear();
				mb[nums[i] - nums[i - 1]]++;
			}
		}
		if (i - l >= 3) {
			ans += ((i - l) * (i - l + 1)) / 2;
			ans -= (i - l);
			ans -= (i - l - 1);
		}
		return ans;
	}
};