class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int totalDuration = 0;
        int n = timeSeries.size();

        for (int i = 1; i < n; i++) {
            totalDuration += min(timeSeries[i] - timeSeries[i - 1], duration);
        }

        totalDuration += duration;
        return totalDuration;
    }
};
