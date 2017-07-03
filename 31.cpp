class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return;
		for (int i = 0; i < nums.size(); i++) {
			if (i && nums[i] > nums[i - 1]) break;
			if (i + 1 == nums.size()) {
				reverse(nums.begin(), nums.end());
				return;
			}
		}
		auto sorted_end = is_sorted_until(nums.rbegin(), nums.rend());
		auto least_bound = upper_bound(nums.rbegin(), sorted_end, *sorted_end);
		swap(nums[nums.size() - 1 - (sorted_end - nums.rbegin())], nums[nums.size() - 1 - (least_bound - nums.rbegin())]);
		reverse(nums.rbegin(), sorted_end);
	}
};