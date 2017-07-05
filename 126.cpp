class Solution {
public:
	void getPath(string b, string e, unordered_map<string, unordered_set<string> > &path, vector<string> &ans, vector<vector<string> > &answer) {
		if (b == e) {
			ans.push_back(b);
			reverse(ans.begin(), ans.end());
			answer.push_back(ans);
			reverse(ans.begin(), ans.end());
			ans.pop_back();
			return;
		}
		auto it = path.find(e);
		for (auto el : it->second) {
			ans.push_back(it->first);
			getPath(b, el, path, ans, answer);
			ans.pop_back();
		}
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		vector<vector<string> > ans;
		if (wordList.size() == 0 || beginWord == endWord) return ans;
		unordered_map<string, vector<string> > map;
		for (auto word : wordList) {
			for (int j = 0; j < word.size(); j++) {
				for (int i = 0; i < 26; i++) {
					if (i == word[j] - 'a') continue;
					string cur = word.substr(0, j) + (char)(i + 'a') + word.substr(j + 1);
					if (wordList.find(cur) != wordList.end()) map[word].push_back(cur);
				}
			}
		}
		unordered_set<string> used;
		unordered_map<string, unordered_set<string> > path;
		unordered_map<string, int> num;
		queue<pair<string, int> > q;
		q.push(make_pair(beginWord, 0));
		used.insert(beginWord);
		int sh = -1;
		while (!q.empty()) {
			auto pr = q.front();
			string cur = pr.first;
			int ind = pr.second;
			q.pop();
			if (sh != -1 && ind >= sh) break;
			for (auto s : map[cur]) {
				if (s == endWord) {
					vector<string> v{ s };
					getPath(beginWord, cur, path, v, ans);
					sh = ind + 1;
					continue;
				}
				if (used.find(s) != used.end()) {
					if (num[s] == ind + 1) path[s].insert(cur);
					continue;
				}
				num[s] = ind + 1;
				path[s].insert(cur);
				q.push(make_pair(s, ind + 1));
				used.insert(s);
			}
		}
		return ans;
	}
};