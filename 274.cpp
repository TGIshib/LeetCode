class Solution {
public:
int hIndex(vector<int>& citations) {
	int n = citations.size();
	vector<int> cnt(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
	    if(citations[i] >= n) cnt[n]++;
	    else cnt[citations[i]]++;
	}
	
	int s = 0;
	
	for(int i = n; i >= 0; i--){
	    if(s + cnt[i] >= i && s <= i) return i;
	    s += cnt[i];
	}
	return 0;
}
};