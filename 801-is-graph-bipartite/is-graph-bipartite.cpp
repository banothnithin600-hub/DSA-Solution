class Solution {
public:
    bool bfs(int src,vector<bool>&vis,vector<bool>&color,vector<vector<int>>&adj){
        queue<int>q;
        q.push(src);
        vis[src]=true;
        color[src]=true;
        while(q.size()>0){
            int cur = q.front();
            q.pop();
        for(int v:adj[cur]){
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
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        // vector<vector<int>>adj(graph.size());
        // for(int grap : graph){
        //     adj[grap[0]].push_back(grap[1]);
        //     adj[grap[1]].push_back(grap[0]);
        // }
       vector<bool>vis(V,false);
       vector<bool>color(V,false);
       for(int i=0;i<V;i++){
        if(!vis[i]){
          if(!bfs(i,vis,color,graph)){
            return false;
          }
       }
       }
       return true;
    }
};