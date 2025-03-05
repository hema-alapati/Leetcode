class Solution {
public:
    long long coloredCells(int n) {
        long long noOfColoredCells=1;
        for(int i=1;i<n;i++){
            noOfColoredCells=noOfColoredCells+4+(4*(i-1));
        }
        return noOfColoredCells;
    }
};