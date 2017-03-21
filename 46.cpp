class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(!n) return ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        if(n == 1) return ans;
        while(1){
            int last = nums.back();
            int j = n - 2;
            while(j >= 0 && nums[j] > nums[j+1]) j--;
            if(j == -1) break;
            int j2 = n - 1;
            while(j2 >= 0 && nums[j2] < nums[j]) j2--;
            if(j2 == -1) break;
            swap(nums[j], nums[j2]);
            reverse(nums.begin() + j + 1, nums.end());
            ans.push_back(nums);
        }
        return ans;
    }
};
