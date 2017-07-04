class Solution {
public:
	static bool cmp(int a, int b) {
		vector<vector<int> > p(2);
		do {
			p[0].push_back(a % 10);
			a /= 10;
		} while (a);
		do {
			p[1].push_back(b % 10);
			b /= 10;
		} while (b);
		reverse(p[0].begin(), p[0].end());
		reverse(p[1].begin(), p[1].end());
		bool fl = true;
		if (p[1].size() > p[0].size()) { swap(p[0], p[1]); fl = false; }
		int i0 = 0, i1 = 0;
		while (i0 < p[0].size()) {
			if (p[0][i0] < p[1][i1]) {
				return fl == true ? false : true;
			}
			if (p[0][i0] > p[1][i1]) {
				return fl == true ? true : false;
			}
			i0++;
			i1++;
			i1 %= p[1].size();
		}
		return fl == false ? p[1][0] <= p[1][i1] : p[1][0] > p[1][i1];
	}
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), cmp);
		string n;
		for (int i : nums) {
			n += to_string(i);
		}
		reverse(n.begin(), n.end());
		int d = n.size() - 1;
		while (d > 0 && n[d] == '0') { n.pop_back(); d--; }
		if (n.size() == 0) n.push_back('0');
		reverse(n.begin(), n.end());
		return n;
	}
};