class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		map<long double, int> mb;
		int a, b;
		int ans = 1;
		for (int i = 0; i < points.size() - 1; i++) {
			for (int j = i + 1; j < points.size(); j++) {
				b = (points[j][1] - points[i][1]);
				a = (points[j][0] - points[i][0]);
				// debug(mp(i, j))
				// debug(mp(a, b))
				if (points[j][1] == points[i][1]) mb[-90]++;
				else {
					mb[(long double)a / (long double)b]++;
				}
			}
			int t = 0;
			for (auto &it : mb) {
				t = max(t, it.second + 1);
			}
			ans = max(ans, t);
			mb.clear();
		}
		// debug(mb)
		return ans;
	}
};