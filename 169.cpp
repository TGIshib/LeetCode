class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int el1, n1 = 0;
		int n = nums.size();
		for (int i : nums) {
			if (!n1) {
				el1 = i;
				n1++;
				continue;
			}
			if (i == el1) {
				n1++;
				continue;
			}
			n1--;
		}
		return el1;
	}
};