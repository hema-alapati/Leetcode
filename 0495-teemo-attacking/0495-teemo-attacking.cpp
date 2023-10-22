class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;

        int totalDuration = duration;
        int endTime = timeSeries[0] + duration;

        for (int i = 1; i < timeSeries.size(); i++) {
            totalDuration += min(duration, timeSeries[i] - timeSeries[i - 1]);
            endTime = timeSeries[i] + duration;
        }

        return totalDuration;
    }
};
