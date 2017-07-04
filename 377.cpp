class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		map<int, int> combSum;
		for (int i : nums) combSum[i] = 1;
		auto it = combSum.begin();
		while (it != combSum.end()) {
			if (it->first > target) break;
			for (int i : nums) combSum[it->first + i] += it->second;
			it++;
		}
		return combSum[target];
	}

	void sum(vector<int>& nums, int target, int ind, int & ans) {
		if (target < 0) return;
		if (target == 0) {
			ans++;
			return;
		}
		for (int i = ind; i < nums.size(); i++) {
			for (int j = 0; target - j * nums[i] >= 0; j++)
				sum(nums, target - nums[i] * j, i + 1, ans);
		}
	}
};