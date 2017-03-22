class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() <= 2) return false;
    int cur1 = nums[0], cur2;
    bool cur2flag = false;
    for (int i = 1; i < nums.size(); i++) {
      if (cur2flag && cur2 < nums[i]) return true;
      if (nums[i] > cur1) {
        if (!cur2flag) {
          cur2 = nums[i];
        }
        else {
          cur1 = min(cur1, nums[i]);
          cur2 = nums[i];
        }
        cur2flag = true;
      }
      else {
        cur1 = min(cur1, nums[i]);
      }
    }
    return false;
  }
};