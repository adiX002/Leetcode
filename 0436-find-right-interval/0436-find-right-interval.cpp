class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> si; //(start point, index)
        for(int i = 0; i < intervals.size(); i++){
            si[intervals[i][0]] = i;
        }
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++){
            auto it = si.lower_bound(intervals[i][1]);
            if(it == si.end()){
                ans[i] = -1;
            }else{
                ans[i] = it->second;
            }
        }
        
        return ans;
    }
};