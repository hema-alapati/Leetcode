class Solution {
private:
    // Write code for dfs/bfs, mark the visited nodes
    void dfs(int node, vector<int> adjLs[], vector<int>& vis) {
        vis[node] = 1; 
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

        vector<int> adjLs[V]; 
        
        // Convert adjacency matrix to list 
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Self nodes are not considered
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        
        vector<int> vis(V, 0); // Initialize vis as a vector

        int cnt = 0; 
        for (int i = 0; i < V; i++) {
            // If the node is not visited
            if (!vis[i]) {
                // Counter to count the number of provinces 
                cnt++;
                dfs(i, adjLs, vis); 
            }
        }
        return cnt; 
    }
};
