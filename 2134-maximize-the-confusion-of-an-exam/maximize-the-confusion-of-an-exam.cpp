class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n =s.length();
        int maxlen =0.;
        int maxfeq =0;
        int right=0,left=0;
        int hash[26]={0};
        while(n>right){
            hash[s[right]-'A']++;
            maxfeq = max(maxfeq,hash[s[right]-'A']);
            if((right-left+1)-maxfeq>k){
                hash[s[left]-'A']--;
                // maxfeq=0;
                // for(int i=0;i<25;i++){
                    // maxfeq=max(maxfeq,hash[i]);
                    left =left+1;
                 }
                if((right-left+1)-maxfeq<=k){
                    maxlen = max(maxlen,right-left+1);
                    right++;
            }
        }
                return maxlen;
    }
};