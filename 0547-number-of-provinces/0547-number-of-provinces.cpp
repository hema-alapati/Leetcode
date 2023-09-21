class Solution {
private:
    // Write code for dfs/bfs, mark the visited nodes
    void dfs(int node, vector<vector<int>>& adjLs, vector<bool>& vis) {
        vis[node] = true;
        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Get the number of nodes
        int V = isConnected.size();

        // Create an adjacency list
        vector<vector<int>> adjLs(V);
        // Change adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        // Create visited array
        vector<bool> vis(V, false);
        int cnt = 0;
        // Traverse the list and call dfs if the node is not visited
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adjLs, vis);
                // Increment count every time dfs is called
                cnt++;
            }
        }
        return cnt;
    }
};
