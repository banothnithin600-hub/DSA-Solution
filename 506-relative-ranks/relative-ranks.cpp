class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        vector<string>ans(score.size());
        string s1 = "Gold Medal",s2="Silver Medal",s3="Bronze Medal";
        int i = 0;
        while(!pq.empty()){
           if(i==0){
            ans[pq.top().second]=s1;
            pq.pop();
            i++;
           }
           else if(i==1){
            ans[pq.top().second]=s2;
            pq.pop();
            i++;
           }else if(i==2){
            ans[pq.top().second]=s3;
            pq.pop();
            i++;
           }else{
            int t = i+1;
            ans[pq.top().second]=to_string(t);
            pq.pop();
            i++;
           }
        } 
        return ans;
    }
};