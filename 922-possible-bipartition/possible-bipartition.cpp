class Solution {
public:
    bool bfs(int src,vector<bool>&vis,vector<bool>&color,vector<vector<int>>&adj){
        queue<int>q;
        vis[src]=true;
        color[src]=true;
        q.push(src);
        while(q.size()>0){
            int cur = q.front();
            q.pop();
            for(int v : adj[cur]){
                if(!vis[v]){
                    vis[v]=true;
                    color[v]=!color[cur];
                    q.push(v);
                }else{
                    if(color[v]==color[cur]){
                    return false;
                    }
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for (auto& edge : dislikes) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n+1,false);
        vector<bool>color(n+1,false);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(!bfs(i,vis,color,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};