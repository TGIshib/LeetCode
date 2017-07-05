class Solution {
public:
	int gcd(int a, int b) {
		while (b) {
			a %= b;
			swap(a, b);
		}
		return a;
	}
	bool canMeasureWater(int x, int y, int z) {
		return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
	}
};