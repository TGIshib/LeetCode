class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int l = 0, r = n - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (nums[mid] == target) return mid;
			if (nums[r] < nums[l]) {
				if (nums[mid] < nums[l]) { // 7 0 1 2 3
					if (nums[mid] < target) {
						if (nums[r] >= target) l = mid + 1;
						else r = mid - 1;
					}
					else r = mid - 1;
				}
				else { // 7 8 9 0 1
					if (nums[mid] < target) l = mid + 1;
					else {
						if (nums[r] >= target) l = mid + 1;
						else r = mid - 1;
					}
				}
			}
			else {
				if (nums[mid] < target) l = mid + 1;
				else r = mid - 1;
			}
		}
		return nums[l] == target ? l : -1;
	}
};