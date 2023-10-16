class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1);
        for (int i = 1; i <= rowIndex; i++) {
            long long res=result[i-1];
            res*=(rowIndex-i+1);
            //+1 because 4th row has an index 3 here, and parameter passed is 3
            res/=i;
            result.push_back(res);
        }
        return result;
    }
};