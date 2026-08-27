class Solution {
public:
    int dirCycle(int src,vector<bool>&vis,vector<bool>&recpath,vector<vector<int>>&graph,vector<int>&ans){
        vis[src]=true;
        recpath[src]=true;
        ans.push_back(src);
        int maxl = -1;
        for(int v:graph[src]){
            if(!vis[v]){
              int res = dirCycle(v,vis,recpath,graph,ans);
                    maxl = max(maxl,res);
            }
            else{
                if(recpath[v]){
                    for(int i=0;i<ans.size();i++){
                        if(ans[i]==v){
                            int cyclength = ans.size()-i;
                            maxl = max(cyclength,maxl);
                            break;
                        }
                    }
                }
            }
        }
        recpath[src]=false;
        ans.pop_back();
        return maxl;
    }
    int longestCycle(vector<int>& edges) {
        int V = edges.size();
        vector<vector<int>>graph(edges.size());
        for(int i=0;i<V;i++){
            if(edges[i]!=-1)
            //graph[edges[i]].push_back(edges[i]);//tle due infinte loop is goes
            graph[i].push_back(edges[i]);

        }
        vector<bool>vis(V,false);
        vector<bool>recpath(V,false);
        vector<int>ans;
        int maxl = -1;
        for(int i=0;i<edges.size();i++){
            if(!vis[i]){
                int res = dirCycle(i,vis,recpath,graph,ans);
                    maxl = max(maxl,res);
            }
        }
        return maxl;
    }
};