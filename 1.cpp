class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int ind = 0;
        for(int i : nums){
            auto it = mp.find(target - i);
            if(it != mp.end()){
                return vector<int> {it->second, ind};
            }
            mp[i] = ind;
            ind++;
        }
        return vector<int>{};
    }
};