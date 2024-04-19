class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergedIntervals;
        if(intervals.size()==0){
            return mergedIntervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int>tempInterval=intervals[0];
        for(vector i:intervals){
            if(i[0]<=tempInterval[1]){
                tempInterval[1]=max(i[1],tempInterval[1]);
            }
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval=i;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};