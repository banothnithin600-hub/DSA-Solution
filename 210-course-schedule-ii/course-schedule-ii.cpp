class Solution {
public:
    bool isCycle(int src,vector<bool>&vis,vector<bool>&recpath,vector<vector<int>>&graph){
        vis[src]=true;
        recpath[src]=true;
        for(int i : graph[src]){
            if(!vis[i]){
                if(isCycle(i,vis,recpath,graph)){
                    return true;
                }
            }else{
                    if(recpath[i]){
                        return true;
                    }
                
            }
        }
        recpath[src]=false;
        return false;
    }
    void path(int src,vector<bool>&vis,stack<int>&st,vector<vector<int>>&adj){
        vis[src]=true;
        for(int i:adj[src]){
            if(!vis[i]){
                path(i,vis,st,adj);
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& graph) {
        int V = numCourses;
        vector<vector<int>>adj(V);
        for(const auto x : graph){
            adj[x[1]].push_back(x[0]);
        }
        stack<int>st;
        vector<bool>vis(V,false);
        vector<bool>recpath(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycle(i,vis,recpath,adj)){
                    return {};
                }
            }
        }
        vector<bool>vis1(V,false);
        for(int i=0;i<V;i++){
            if(!vis1[i]){
                path(i,vis1,st,adj);
            }
        }
       vector<int>ans;
       while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
       }
       return ans;
    }
};