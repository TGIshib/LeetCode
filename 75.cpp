class Solution {
public:
	void sortColors(vector<int>& nums) {
		int a = -1, b = nums.size(), i = 0;
		while (i < nums.size()) {
			if (nums[i] == 0) {
				swap(nums[++a], nums[i]);
				i++;
			}
			else if (nums[i] == 1) {
				i++;
			}
			else {
				swap(nums[--b], nums[i]);
			}

			if (i >= b) break;
		}
	}
};