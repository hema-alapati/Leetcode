class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // currentRow += goingDown ? 1 : -1;
            if(goingDown==true){
                currentRow+=1;
            }
            else{
                currentRow-=1;
            }
        }

        string zigzag;
        for (const string& row : rows) {
            zigzag += row;
        }

        return zigzag;
    }
};