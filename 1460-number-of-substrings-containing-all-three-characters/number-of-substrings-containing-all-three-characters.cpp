class Solution {
public:
    int numberOfSubstrings(string s) {
        
//         int count = 0;
//         int n = s.length();
        
//         for(int i = 0; i < n; i++) {
//             int hash[3] = {0}; // Reset for every new starting point
//             for(int j = i; j < n; j++) {
//                 // ERROR FIX 1: You must update the hash based on the character at s[j]
//                 hash[s[j] - 'a']++; 
                
//                 // ERROR FIX 2: Check if ALL three characters are present (at least 1 each)
//                 if(hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
//                     count = count + (n - j); // If i...j is valid, all substrings i...j+1, i...j+2 are also valid
//                     break; 
//                 }
//             }
//         }
//         return count;
//     }
// };/ 
int n =s.length();
int lastseen[3]={-1,-1,-1};
int count = 0;
for(int i=0;i<n;i++){
    lastseen[s[i]-'a']=i;
    if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1)
    count = count + (1 + min({lastseen[0], lastseen[1], lastseen[2]}));
            
}
return count;
    }
};