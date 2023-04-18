class Solution {
public:
    bool canJump(vector<int>& arr) {
        int i = 0;
        if(arr.size() == 1) return true;
		if (arr[i] == 0) return false;
		int j = arr[i];
		int diff = j - i;
		int ans = 0;
        int n = arr.size();
		while (i < n - 1) {
			int maxlen = 0;
			int t = j;
			int k = j;
			if (j >= n) break;
			while (t > i) {
				if (arr[t] + t - i > maxlen) {
					maxlen  = arr[t] + t - i;
					k = t;
				}
				t--;
			}

			i = k;
			j = i + arr[i];
            if(i>=n-1) break;
			if (j == i) return false;
			ans++;
		}
		return true;
    }
};