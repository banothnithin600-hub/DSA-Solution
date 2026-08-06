class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
        int val=1;
        int copy = n;
        while(copy){
        val *= copy%10;
        copy/=10;
        //idx++;
        }
        if(val%t){
            n++;
        }else{
          return n;
        }
        }
        return 0;
    }
};