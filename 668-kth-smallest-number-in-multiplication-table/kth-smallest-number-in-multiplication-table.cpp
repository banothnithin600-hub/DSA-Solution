class Solution {
public:
    int count(int mid,int n,int m){
        int count = 0;
        for(int i=1;i<=m;i++){
          count +=min(mid/i,n);
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        //vector<int>arr;
    //     priority_queue<int> pq;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             pq.push(i*j);
    //         }
    //     }
    //     //sort(arr.begin(),arr.end());
    //    // return arr[k-1];
    //    //(arr.begin(), arr.end());
    //    while(pq.size()>k){
    //        pq.pop();
     //  }
     //  return pq.top();
     int low = 0;
     int high = m*n;
     while(low<=high){
        int mid = low+(high-low)/2;
        int paircount = count(mid,n,m);
         if(paircount<k){
            low = mid+1;
         }else{
            high = mid-1;
         }
     }
     return low;
    }
};