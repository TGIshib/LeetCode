class Solution {
public:
string minWindow(string s, string t) {
  int best_s = -1, best_e = -1;
  unordered_map<char, int> set;
  for (char c : t) set[c]++;
  int cnt = t.size();
  int start = 0, end = 0, cur = 0;
  unordered_map<char, int> pos; int n = s.size();
  while (end < n) {
    auto tit = set.find(s[end]);
    if (tit == set.end());
    else {
      auto sit = pos.find(s[end]);
      if (sit == pos.end() || sit->second < set[s[end]]) cur++;
      pos[s[end]]++;
      while (set.find(s[start]) == set.end() || set[s[start]] < pos[s[start]]) pos[s[start++]]--;
    }
    if (cur == cnt) {
      if (best_s == -1 || best_e - best_s > end - start) {
        best_s = start;
        best_e = end;
      }
    }
    end++;
  }
  return best_e == -1 ? "" : s.substr(best_s, best_e - best_s + 1);

}
};