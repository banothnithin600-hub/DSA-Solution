class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        //postive :- right , negative :- left
        //vector<int>ans(n);
        stack<int>s;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>0){//arr is postive value
                s.push(arr[i]);
            }else{//arr is Negative value
                while(s.size()>0 && s.top()>0 && s.top()<abs(arr[i])){
                    s.pop();
                }
               if(s.size()==0 || s.top()<0){
                s.push(arr[i]);
               }else{
                if(s.top()==abs(arr[i])){
                    s.pop();
                }//else if(s.top()<abs(arr[i])){
                 //  s.pop();
              //  }
               }
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};