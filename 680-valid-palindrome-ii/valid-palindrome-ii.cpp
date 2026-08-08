class Solution {
public:
bool ispalidrome(string s ,int i,int j){
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else return  false;
    }
    return true;
}
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }else return ispalidrome(s,left+1,right) || ispalidrome(s,left,right-1);
        }
        return true;
    }
};