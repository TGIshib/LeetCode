class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(auto ch : s) map[ch]++;
        vector<pair<int, char> > chars;
        for(auto p : map) chars.push_back(make_pair(p.second, p.first));
        sort(chars.begin(), chars.end());
        reverse(chars.begin(), chars.end());
        string ans;
        for(auto pr : chars){
            for(int j = 0; j < pr.first; j++) ans.push_back(pr.second);
        }
        return ans;
    }
};
