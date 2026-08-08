class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int k) {
        int n = arr.size();
    for(int i=0;i<n;i++){
        bool left = i==0 || arr[i-1]==0;
        bool right = i==n-1||arr[i+1]==0;
        if(left&& right &&arr[i]==0){
            arr[i]=1;
            k--;
        }
    }
     return k<=0;
    }
};