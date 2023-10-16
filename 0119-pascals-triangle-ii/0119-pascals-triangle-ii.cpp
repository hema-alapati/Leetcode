// 60% Beast
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<std::vector<int>> triangle;

        for (int i = 0; i <= rowIndex; i++) {
            vector<int> row(i + 1);
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row[j] = 1; 
                } else {
                    row[j] = triangle[i-1][j - 1] + triangle[i-1][j]; 
                }
            }
            triangle.push_back(row);
        }

        return triangle[rowIndex];
    }
};