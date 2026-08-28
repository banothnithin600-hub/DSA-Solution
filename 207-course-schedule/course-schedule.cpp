class Solution {
public:
    bool isCycle(int src, vector<bool>& vis, vector<bool>& recpath, vector<vector<int>>& adj) {
        recpath[src] = true;
        vis[src] = true;
        
        for(int i : adj[src]) {
            if(!vis[i]) {
                if(isCycle(i, vis, recpath, adj)) {
                    return true;
                }
            } else if(recpath[i]) {
                return true;
            }
        }
        
        recpath[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build the adjacency list from the prerequisites pairs
        vector<vector<int>> adj(numCourses);
        for(auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]); // To take course edge[0], you must first take edge[1]
        }
        
        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);
        
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
               if(isCycle(i, vis, recpath, adj)) {
                   return false; // Cycle detected, cannot finish all courses
               }
            }
        }
        return true;
    }
};
