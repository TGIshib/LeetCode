class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map;
		vector<int> ans;
		if (!k) return ans;
		for (int i : nums) map[i]++;
		auto it = map.begin();
		priority_queue< pair<int, int> > q;
		while (it != map.end()) {
			if (q.size() < k || -q.top().first < it->second) {
				if (q.size() == k) q.pop();
				q.push(make_pair(-it->second, it->first));
			}
			it++;
		}
		while (!q.empty()) {
			ans.push_back(q.top().second);
			q.pop();
		}
		return ans;
	}
};