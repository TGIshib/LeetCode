class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i] - 1;
            if(nums[i] < 0){
                x = -nums[i] - 1;
            }
            else if(nums[i] > nums.size()){
                x = nums[i] - 2 * nums.size() - 1;
            }
            if(nums[x] < 0){
                nums[x] = -nums[x] + 2 * nums.size();
            }
            else{
                nums[x] = -nums[x];
            }
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0 && nums[i] <= nums.size()) ans.push_back(i + 1);
        }
        return ans;
    }
};
