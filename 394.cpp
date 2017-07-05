class Solution {
public:
	string conc_n_times(int &n, const string &str) {
		string res;
		while (n) {
			res += str;
			n--;
		}
		return res;
	}

	string decode(string s) {
		string res;
		int st = -1;
		int c = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[') {
				if (c == 0) {
					int n = atoi(s.substr(st, i - st).c_str());
					res += conc_n_times(n, decode(s.substr(i + 1)));
					st = -1;
				}
				c++;
			}
			else if (s[i] == ']') {
				if (c == 0 || s.size() - 1 == i) return res;
				c--;
				st = i + 1;
			}
			else if (s[i] >= 'a' && s[i] <= 'z' && c == 0)
				res += s[i], st = -1;
			else if (st == -1) st = i;
		}
		return res;
	}

	string decodeString(string s) {
		if (s.size() <= 1) return s;
		return decode(s);
	}

};