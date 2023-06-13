class Solution {
public:
	vector<pair<int, int>> v;
	vector<int> a, b;
	// bool ok = false;
	bool check(vector<int>&heaters, int mid) {
		a.clear();
		b.clear();
		pair<int, int> p;
		for (int i = 0; i < heaters.size(); i++) {
			if (heaters[i] - mid <= 1) {
				p.first = 1;
			}
			if (heaters[i] - mid > 1) {
				p.first = heaters[i] - mid;
			}
			a.push_back(p.first);
			p.second = heaters[i] + mid;
			b.push_back(p.second);
		}
		// debug(b)
		for (int i = 0; i < v.size(); i++) {
			auto it = lower_bound(b.begin(), b.end(), v[i].first) - b.begin();
			auto it1 = upper_bound(a.begin(), a.end(), v[i].first) - a.begin();
			if (it1 <= it) return false;

		}
		return true;
	}
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		for (auto &it : houses) {
			v.push_back({it, it});
		}
		int l = 0;
		int r = 1e9 + 1;
		int ans = 0;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (check(heaters, mid)) {
				ans = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return ans;
	}
};
