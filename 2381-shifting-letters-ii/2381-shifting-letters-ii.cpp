class Solution {
public:
	string shiftingLetters(string s, vector<vector<int>>& shifts) {
		vector<int> one_left, one_right, zero_left, zero_right;
		for (int i = 0; i < shifts.size(); i++) {
			if (shifts[i][2] == 1) {
				one_left.push_back(shifts[i][0]);
				one_right.push_back(shifts[i][1]);
			}
			if (shifts[i][2] == 0) {
				zero_left.push_back(shifts[i][0]);
				zero_right.push_back(shifts[i][1]);
			}
		}
		sort(one_left.begin(), one_left.end());
		sort(one_right.begin(), one_right.end());
		sort(zero_left.begin(), zero_left.end());
		sort(zero_right.begin(), zero_right.end());
		string ans = "";
		// debug(one_left);
		// debug(one_right);
		// debug(zero_left);
		// debug(zero_right);
		char c;
		int a, b;
		int temp;
		// 3 5
		// 4 6
		// 0 1 1 1 0 0 0
		// y z a b a z y
		for (int i = 0; i < s.size(); i++) {
			auto one1 = upper_bound(one_left.begin(), one_left.end(), i) - one_left.begin();
			auto one2 = lower_bound(one_right.begin(), one_right.end(), i) - one_right.begin();
			one1 -= one2;
			// debug(i)
			// debug(mp(one1, one2))
			auto zero1 = upper_bound(zero_left.begin(), zero_left.end(), i) - zero_left.begin();
			auto zero2 = lower_bound(zero_right.begin(), zero_right.end(), i) - zero_right.begin();
			zero1 -= zero2;
			// debug(mp(zero1, zero2))
			a = one1;
			b = zero1;
			if (a <= b) {
				temp = b - a;
				c = (((s[i] - 'a') + (26 - (temp)%26)) % 26) + 'a';
				ans += c;
			}
			else {
				temp = a - b;
				c = (((s[i] - 'a') + (temp)) % 26) + 'a';
				ans += c;
			}

		}
		return ans;
	}
};