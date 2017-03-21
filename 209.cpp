class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = 0, ind = 0, cur = 0;
        for(int i = 0; i < nums.size(); i++){
            cur += nums[i];
            if(cur < s) continue;
            else {
                while(ind < i && cur - nums[ind] >= s){
                    cur-= nums[ind];
                    ind++;
                }
                if(ans == 0 || ans > i - ind + 1) ans = i - ind + 1;
            }
        }
        return ans;
    }
};
