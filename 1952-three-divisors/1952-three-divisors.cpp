class Solution {
public:
    bool isThree(int n) {
	int d = sqrt(n);
	if (d * d != n)return false;
	if (d == 1) return false;
	for (int i = 2; i * i <= d; i++) {
		if (d % i == 0) return false;
	}
	return true;
}
};