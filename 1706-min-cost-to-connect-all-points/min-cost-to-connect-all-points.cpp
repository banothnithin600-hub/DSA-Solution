class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
       int V = points.size();
       //(wt,u)
       int src = 0;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       vector<bool> mst(V, false);
       pq.push(make_pair(0,src));
       int cost = 0;
       int mincost = 0;
       while(pq.size()>0){
        int u = pq.top().second; 
        int cost = pq.top().first;
        pq.pop();
        if(!mst[u]){
            mst[u]=true;
           mincost +=cost;
           for(int v=0;v<V;v++){
            if(u!=v){//u--v
              int wt = abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]);
              pq.push(make_pair(wt,v));
            }
           }
        }
       }
       return mincost;
    }
};