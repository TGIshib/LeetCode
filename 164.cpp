class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		vector<pair<int, int> > b(nums.size());
		int mmax = 0, mmin = 1;
		if (nums[mmax] < nums[mmin]) swap(mmax, mmin);
		for (int i = 0; i < nums.size(); i++) b[i].first = -1, b[i].second = -1;
		for (int i = 2; i < nums.size(); i++) {
			if (nums[mmax] < nums[i]) mmax = i;
			if (nums[mmin] > nums[i]) mmin = i;
		}
		int n = nums.size();
		int step = (nums[mmax] - nums[mmin] + 1) / n;
		if ((nums[mmax] - nums[mmin] + 1) % n) step++;
		for (int i = 0; i < nums.size(); i++) {
			int pl = (nums[i] - nums[mmin] + 1) / step - 1;
			if ((nums[i] - nums[mmin] + 1) % step != 0) pl++;
			if (b[pl].first == -1) {
				b[pl].first = i;
				b[pl].second = i;
			}
			else {
				if (nums[i] < nums[b[pl].first]) b[pl].first = i;
				else if (nums[i] > nums[b[pl].second]) b[pl].second = i;
			}
		}
		int maxGap = 0;
		int l = -1;
		for (int i = 0; i < b.size(); i++) {
			if (b[i].first != -1) {
				l = i;
				maxGap = nums[b[i].second] - nums[b[i].first];
				break;
			}
		}
		for (int i = l + 1; i < b.size(); i++) {
			if (b[i].first == -1) continue;
			maxGap = max(maxGap, max(nums[b[i].first] - nums[b[l].second], nums[b[i].second] - nums[b[i].first]));
			l = i;
		}
		return maxGap;
	}
};