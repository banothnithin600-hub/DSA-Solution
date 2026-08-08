class Solution {
public:
// int f(string s,string subset){
//     int n = s.size();
//     if(s.size()==0)  return;
//     char ch = s[0];
//     f(str.substr(1,n-1),subset+ch);
//     f(str.substr(1,n-1),subset);
// }
    int balancedStringSplit(string s) {
       int count=0;
       int val =0;
       for(char ch:s ){
        if(ch=='L'){
            val++;
        }else{
            val--;
        }
        if(val==0){
            count++;
        }
       }
       return count;
    }
};