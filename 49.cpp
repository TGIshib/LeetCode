class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto s : strs){
            auto sorted = s;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(s);
        }
        vector<vector<string> > ans;
        auto it = mp.begin();
        while(it != mp.end()){
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};