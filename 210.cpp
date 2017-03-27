class Solution {
public:
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
  vector<vector<int> > list(numCourses);
  unordered_map<int, vector<int> > map;
  for (auto p : prerequisites) {
    list[p.first].push_back(p.second);
    map[p.first].push_back(p.second);
  }
  vector<int> ans;
  vector<bool> used(numCourses, false);
  bool flag = true;
  for (int i = 0; i<numCourses; ++i)
    if (!used[i])
      dfs(i, used, list, ans);
  for (int i = 0; i < numCourses; ++i) used[i] = false;
  for (int i : ans) {
    for (int j : map[i]) {
      if (!used[j]) 
        return vector<int>();
    }
    used[i] = true;
  }
  return ans;
}
    
    void dfs (int v, vector<bool> &used, vector<vector<int> > & g, vector<int> & ans) {
    	used[v] = true;
    	for (size_t i=0; i<g[v].size(); ++i) {
    		int to = g[v][i];
    		if (!used[to])
    			dfs (to, used, g, ans);
    	}
    	ans.push_back (v);
    }

};