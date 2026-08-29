class Solution {
public:

    bool helper(int src,
                vector<bool>& vis,
                vector<bool>& recpath,
                vector<vector<int>>& adj) {

        vis[src] = true;
        recpath[src] = true;

        for (int v : adj[src]) {

            // v is not visited
            if (!vis[v]) {

                if (helper(v, vis, recpath, adj))
                    return true;
            }

            // v is already in current recursion path
            else if (recpath[v]) {
                return true;
            }
        }

        // DFS of src is complete
        recpath[src] = false;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<bool> vis(V, false);
        vector<bool> recpath(V, false);

        vector<int> ans;

        for (int i = 0; i < V; i++) {

            if (!vis[i]) {
                helper(i, vis, recpath, graph);
            }
        }

        // Check each node again
        for (int i = 0; i < V; i++) {

            vector<bool> tempVis(V, false);
            vector<bool> tempPath(V, false);

            if (!helper(i, tempVis, tempPath, graph)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};