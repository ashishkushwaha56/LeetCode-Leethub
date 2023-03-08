class Solution {
public:
	bool check(vector<int>& v, int mid, int h) {
		int cnt = 0;
		int i = 0;

		for (i = 0; i < v.size();) {

			cnt += ceil((long double)v[i] / mid);
			i++;
			if (cnt >= h) {
				break;
			}

		}
		// debug(mid)
		// debug(cnt)
		// debug(i)
		if (cnt <= h and i >= v.size()) return true;
		// if (i >= v.size()) return true;
		return false;
	}
	int minEatingSpeed(vector<int>& piles, int h) {
		int ans = *max_element(piles.begin(), piles.end());
		int l = 1;
		int r = ans;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (check(piles, mid, h)) {
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