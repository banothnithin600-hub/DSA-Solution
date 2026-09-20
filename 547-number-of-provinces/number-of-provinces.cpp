class Solution {
public:
   void dfs(int src,vector<bool>&vis,vector<vector<int>>&adj){
        vis[src]=true;
        for(auto &edg:adj[src]){
            if(!vis[edg]){
                dfs(edg,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                   adj[i].push_back(j);
                   adj[j].push_back(i);
                }
                //i++;
            }
        }
       int count = 0;
       vector<bool>vis(V,false);
       for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,adj);
            count++;
        }
       }
       return count;
    }
};