class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string> > res;
    res = solve(s, 0);
    for (int i = 0; i < res.size(); i++) {
      reverse(res[i].begin(), res[i].end());
    }
    return res;
  }

  vector<vector<string> > solve(string & s, int start) {
    vector<vector<string> > res;
    if (start == s.size()) {
      res.push_back(vector<string>());
      return res;
    }
    for (int i = start; i < s.size(); i++) {
      if (is_pal(s, start, i)) {
        auto sub_res = solve(s, i + 1);
        for (int j = 0; j < r.size(); j++) sub_res[j].push_back(s.substr(start, i - start + 1));
        res.insert(res.end(), sub_res.begin(), sub_res.end());
      }
    }
    return res;
  }

  bool is_pal(string & s, int start, int end) {
    while (start < end) {
      if (s[start++] != s[end--]) return false;
    }
    return true;
  }
};