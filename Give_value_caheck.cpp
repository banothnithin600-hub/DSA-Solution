//https://atcoder.jp/contests/abc453/tasks/abc453_a
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n),ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<0<<" "<<arr[0]<<endl;
    int value = arr[0];
    for(int i=1;i<=n;i++){
        if(abs(arr[i]-value)>=k){
            cout<<i<<" "<<arr[i]<<endl;
        }
    }
}