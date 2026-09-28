class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>arr;
        int count = 0;
        for(int i=0;i<seq.length();i++){
           if(seq[i]=='('){
            arr.push_back(count%2);
              count++;
           }else{
             count--;
             arr.push_back(count%2);
           }
        } 
        return arr;   
    }
};