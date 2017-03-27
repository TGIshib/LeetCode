class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int n : nums){
            if(!map[n]){
                map[n] = map[n-1] + map[n+1] + 1;
                map[ n - map[n-1] ] = map[n];
                map[ n + map[n+1] ] = map[n];
            }
        }
        int ans = 1;
        for(auto t : map) ans = max(ans, t.second);
        return ans;
    }
};