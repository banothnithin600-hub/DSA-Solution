class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        int count = 0;
        for(auto x:m){
            if(x.second==1){
                return -1;
            }
            if(x.second%3==0){
                count+=x.second/3;
            }else{
                count+=x.second/3+1;
            }
        }
        return count;
    }
};