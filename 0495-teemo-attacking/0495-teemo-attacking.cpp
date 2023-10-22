class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int totalDuration = 0;
        int endTime = 0;

        for (int timePoint : timeSeries) {
            totalDuration += min(duration, timePoint + duration - endTime);
            endTime = timePoint + duration;
        }

        return totalDuration;
    }
};
