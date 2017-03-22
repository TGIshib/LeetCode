class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int> > ans;
    if (!nums.size()) return ans;
    sort(nums.begin(), nums.end());
    vector<int> cur;
    solve(ans, cur, nums, 0);
    return ans;
  }

  void solve(vector<vector<int> > & ans, vector<int> & cur, vector<int>& nums, int ind) {
    for (int i = ind; i < nums.size(); i++) {
      if (i != ind && nums[i] == nums[i - 1]) continue;
      cur.push_back(nums[i]);
      solve(ans, cur, nums, i + 1);
      cur.pop_back();
    }
    ans.push_back(cur);
  }
};