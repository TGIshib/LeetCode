class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int not_null_ptr = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i]) nums[not_null_ptr++] = nums[i];
    }
    for (int i = not_null_ptr; i < nums.size(); i++) nums[i] = 0;
  }
};