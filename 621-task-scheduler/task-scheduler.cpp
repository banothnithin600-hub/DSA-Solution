class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //step 1
        vector<int>freq(26,0);
        for(int i=0;i<tasks.size();i++){
            char ch = tasks[i];
            freq[ch-'A']++;
        }
        //step 2
        sort(freq.begin(),freq.end(),greater<int>());//decre order
        //step3
            int group = freq[0]-1; //groups 
            int idel = group*n;  //slots
        for(int i=1;i<26;i++){
            if(freq[i]==freq[0]){
              idel-=group;
            }else{
                idel-=freq[i];
            }

        }
        if(idel<=0) return tasks.size();
        return tasks.size()+idel;
    }
};