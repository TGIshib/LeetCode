class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(ans, 0, nums, cur);
        return ans;
    }
    void solve(vector<vector<int>> & ans, int ind, vector<int>& nums, vector<int>& cur){
        if(ind == nums.size()) {
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[ind]);
        solve(ans, ++ind, nums, cur);
        cur.pop_back();
        solve(ans, ind, nums, cur);
    }
};
