class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
       //vector<int>ans;
       unordered_map<int,int>m;
       for(int i=0;i<arr.size();i++){
           m[arr[i]]++;
       }  
        sort(arr.begin(), arr.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
       for(int i=0;i<n;i++){
         if(m[arr[i]]==0){
            continue;
         }
         if(m[arr[i]*2]==0){
            return false;
         }
          //ans.push_back(arr[i]);
          m[arr[i]]--;
          m[arr[i]*2]--;
       }
       return true;
    }
};