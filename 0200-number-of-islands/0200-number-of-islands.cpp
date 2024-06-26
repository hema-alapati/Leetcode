// wrong output for one case
// class Solution {
// private:
//     void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int n, int m) {
//         vis[row][col] = 1;
//         queue<pair<int, int>> q;
//         q.push({row, col});

//         while (!q.empty()) {
//             int row = q.front().first;
//             int col = q.front().second;
//             q.pop();

//             for (int delrow = -1; delrow <= 1; delrow++) {
//                 for (int delcol = -1; delcol <= 1; delcol++) {
//                     int nrow = row + delrow;
//                     int ncol = col + delcol;
//                     if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
//                         grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
//                         vis[nrow][ncol] = 1;
//                         q.push({nrow, ncol});
//                     }
//                 }
//             }
//         }
//     }

// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         if (n == 0) return 0; // Handle empty grid
//         int m = grid[0].size();
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         int cnt = 0;
//         for (int row = 0; row < n; row++) {
//             for (int col = 0; col < m; col++) {
//                 if (!vis[row][col] && grid[row][col] == '1') {
//                     cnt++;
//                     bfs(row, col, vis, grid, n, m); // Pass n and m to bfs
//                 }
//             }
//         }
//         return cnt;
//     }
// };


class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int n, int m) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        // Define horizontal and vertical directions (left, right, up, down)
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nrow = row + dr[dir];
                int ncol = col + dc[dir];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0; 
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid, n, m);
                }
            }
        }
        return cnt;
    }
};