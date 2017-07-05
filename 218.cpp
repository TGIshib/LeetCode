class Solution {
public:
	vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
		vector<pair<int, pair<int, int> > > t;
		vector<pair<int, int> > ans;
		if (buildings.size() == 0) return ans;
		int n = buildings.size();
		int qq = 0;
		for (vector<int> c : buildings) {
			t.push_back(make_pair(c[0], make_pair(-c[2], qq)));
			t.push_back(make_pair(c[1], make_pair(c[2], qq)));
			qq++;
		}
		sort(t.begin(), t.end());
		vector<bool> us(n + 2, false);
		priority_queue<pair<int, int> > cur_h;
		int prev_h = -t[0].second.first;
		for (int i = 0; i < t.size(); i++) {
			int coor = t[i].first;
			int h = abs(t[i].second.first);
			int ind = t[i].second.second;
			if (t[i].second.first > 0) {
				us[ind] = true;
				int prev_h = 0;
				if (cur_h.size()) prev_h = cur_h.top().first;
				while (cur_h.size() && us[cur_h.top().second] == true) {
					cur_h.pop();
				}
				if (cur_h.size() == 0) {
					if (prev_h != 0) ans.push_back(make_pair(coor, 0));
				}
				else if (prev_h != cur_h.top().first) {
					ans.push_back(make_pair(coor, cur_h.top().first));
				}
			}
			else {
				if (cur_h.size() == 0 || h > cur_h.top().first) {
					ans.push_back(make_pair(coor, h));
				}
				cur_h.push(make_pair(h, ind));
			}
		}
		return ans;
	}
};