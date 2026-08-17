class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      int n = stones.size();
      priority_queue<int>pq;
      for(int i=0;i<n;i++){
        pq.push(stones[i]);
      }
      while(pq.size()>1){
        int v1 = pq.top(); pq.pop();
        int v2 = pq.top(); pq.pop();
        if(v1!=v2){
            pq.push(v1-v2);
        }
      }

      return pq.empty()?0:pq.top();
    }
};