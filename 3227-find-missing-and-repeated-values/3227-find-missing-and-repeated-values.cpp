class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int missing, repeating;
        int n=grid[0].size();
        int size=n*n;
        vector<int> freq(size+1,0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                freq[grid[i][j]]++;
            }
        }
        for(int i=1;i<=size;i++){
            if(freq[i]==2){
                repeating=i;
            }
            if(freq[i]==0){
                missing=i;
            }
        }
        return {repeating, missing};
    }
};