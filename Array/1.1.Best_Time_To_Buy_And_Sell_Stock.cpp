/*
QUESTION:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the
future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

/*
APPROACH:
1. Initialize `j = 0`, where `j` represents the index of the minimum buying price seen so far.
2. Traverse the array from `i = 1` to `n - 1`.
3. If `prices[i] < prices[j]`, update `j = i` because we found a new minimum buying price.
4. Calculate the profit by selling on the current day:
   `prices[i] - prices[j]`
5. Update `profit` with the maximum profit found so far using `max()`.
6. Return `profit` at the end.
*/

//CODE:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit =0;
        int j=0;
        for(int i =1; i<n; i++){
            if(prices[i] < prices[j] ){
                j=i;
            }
            profit= max(profit,prices[i] - prices[j]);
        }
        return profit;
        
    }
};

/*
Time Complexity= `O(n)` — We traverse the array only once.
Space Complexity= `O(1)` — We use only a few variables, so no extra space is required.
*/
