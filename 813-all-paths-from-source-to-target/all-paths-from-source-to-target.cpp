class Solution {
public: 
   void path(int src,int target,vector<int>&curPath,vector<vector<int>>&res,vector<vector<int>>&graph){
       curPath.push_back(src);
         if(src==target){
            res.push_back(curPath);
         }
         else{
              for(int i : graph[src]){
                 path(i,target,curPath,res,graph);
              }
         }
         curPath.pop_back();
   }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size()-1;
        vector<int>curPath;
        vector<vector<int>>res;
        path(0,target,curPath,res,graph);
        return res;
    }
};