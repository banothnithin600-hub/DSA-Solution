class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        long long profit = 0;
        for(int i=1;i<n;i++){
         if(prices[i]>prices[i-1]){//current value > prev value
            profit +=(prices[i]-prices[i-1]);
         }
        }
        return profit;
    }
};//step 1: draw the graph of array with days ,prices
//step 2 incearing the array in calulator the different between max value-min value
//step 3: add all different value in array 
//Days:  0  1  2  3  4  5
//Price: 7  1  5  3  6  4

//Diff:     -6 +4 -2 +3 -2
//Profit:     0  +4  0 +3  0 = 7
