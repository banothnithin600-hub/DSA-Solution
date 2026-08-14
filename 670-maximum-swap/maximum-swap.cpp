class Solution {
public:
    int maximumSwap(int num) {
      string s = to_string(num);
      int n=s.size();
      priority_queue<pair<char,int>>pq;
      for(int i=0;i<n;i++){
        pq.push({s[i],i});
      }
      for(int j=0;j<n;j++){
        while(!pq.empty() && pq.top().second<j)
        pq.pop();
        if(pq.top().first>s[j]){
            swap(s[j],s[pq.top().second]);
            break;
        }
      }
        return stoi(s);
    }
};
// Approach
// Convert number to string: We convert the number num into a string st so we can easily access and manipulate each digit.
// Build a max-heap:
// • We construct a max-heap (priority queue) where each element is a pair containing a digit and its index (digit, index). The max-heap orders the elements based on the digit values, so we can quickly retrieve the largest digit available at any point in time.
// Traverse the string:
// • For each digit in the number (from left to right), check if there's a larger digit available later (using the heap).
// • If we find a larger digit at a later position, we swap the current digit with it to maximize the number. After performing the swap, we terminate, as only one swap is allowed.
// Return result:
// • After the potential swap, the modified string is converted back into an integer using stoi(), and the result is returned.