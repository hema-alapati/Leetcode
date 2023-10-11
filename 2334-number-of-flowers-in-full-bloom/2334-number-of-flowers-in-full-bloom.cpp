class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>start,end;
        for(vector<int> &flower:flowers){
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int>res;
        for(auto t:people){
            //subtracting with starting pointer to get relative index value to first
            int started=upper_bound(start.begin(), start.end(), t)-start.begin();
            //upper_bound returns an iterator that points to index of element greater than given value
            int ended=lower_bound(end.begin(),end.end(), t)-end.begin();
            //lower_bound returns an iterator that points to index of element equal to given value
            res.push_back(started-ended);
        }
        return res;
        // Note: Sorting is a prerequisite for these functions (upper_bound and lower_bound) to work correctly.
    }
};