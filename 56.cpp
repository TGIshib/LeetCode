class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(!intervals.size()) return ans;
        vector<pair<int,int> > sorted_intervals;
        for(auto it : intervals){
            sorted_intervals.push_back(make_pair(it.start, -1));
            sorted_intervals.push_back(make_pair(it.end, 1));
        }
        sort(sorted_intervals.begin(), sorted_intervals.end());
        int start = sorted_intervals[0].first;
        int num = 1;
        for(int i = 1; i < sorted_intervals.size(); i++){
            if(sorted_intervals[i].second == -1){
                if(!num) start = sorted_intervals[i].first;
                num++;
            }
            else num--;
            if(!num){
                ans.push_back(Interval(start, sorted_intervals[i].first));
            }
        }
        return ans;
    }
};
