class Solution {
public:
    bool isMatch(string s, string p) {
        return match(p, s, 0, 0);
    }

    bool match(string & s, string & p, int ind1, int ind2) {
        if (ind1 + 1 < s.size() && s[ind1 + 1] == '*') {
            if (s[ind1] == '.') {
                bool flag = false;
                for (int i = ind2; i <= p.size(); i++) {
                    flag = match(s, p, ind1 + 2, i);
                    if (flag) return true;
                }
                return false;
            }
            else {
                bool flag = match(s, p, ind1 + 2, ind2);
                if (flag) return true;
                for (int i = ind2; i < p.size(); i++) {
                    if (p[i] != s[ind1]) break;
                    flag = match(s, p, ind1 + 2, i + 1);
                    if (flag) return true;
                }
                return false;
            }
        }
        if (ind1 == s.size() && ind2 == p.size()) return true;
        if (ind1 == s.size() || ind2 == p.size()) return false;

        if (s[ind1] == '.') {
            return match(s, p, ind1 + 1, ind2 + 1);
        }
        else {
            if (s[ind1] == p[ind2])
                return match(s, p, ind1 + 1, ind2 + 1);
            else {
                return false;
            }
        }
    }

};
