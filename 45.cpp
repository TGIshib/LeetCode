class Solution {
public:
int jump(vector<int>& nums) {
  int n = nums.size();
  if (n <= 1) return 0;
  vector<int> steps(n);
  int p = 0;
  steps[0] = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    while (steps[p] < i) p++;
      if (steps[p + 1]) {
        steps[p + 1] = max(steps[p + 1], i + nums[i]);
      }
      else {
        steps[p + 1] = i + nums[i];
      }
  }
  return p + 1;
}

};