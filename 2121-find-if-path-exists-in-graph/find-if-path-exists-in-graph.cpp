class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
      queue<int>q;
      vector<int>vis(n,false);
      q.push(source);
      vis[source]=true;
      while(q.size()>0){
        int u = q.front();
        q.pop();
        if(u==destination){
            return true;
        }
        for(int v:graph[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
      }
      return false;
    }
};