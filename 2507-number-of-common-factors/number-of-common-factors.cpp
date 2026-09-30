class Solution {
public:
    int commonFactors(int a, int b) {
        vector<int>arr1,arr2;
        int count = 0;
        unordered_map<int,int>m;
        for(int i=1;i<=a;i++){
            if(a%i==0){
                m[i]++;
            }
        }
        for(int i=1;i<=b;i++){
            if(b%i==0){
                if(m.find(i)!=m.end()){
                    count++;
                }
            }
        }
       return count;
    }
};