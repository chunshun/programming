- stock in leetcode
- best-time-to-buy-and-sell-stock-ii
- // Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
```c++
/***************************************************************************************************** 
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 * (i.e., buy one and sell one share of the stock multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock 
 * before you buy again).
 * 
 * Example 1:
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 *              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 *              engaging multiple transactions at the same time. You must sell before buying again.
 * 
 * Example 3:
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 ******************************************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit02(prices);
        return maxProfit01(prices);
    }
    // Solution 1 
    // find all of ranges: which start a valley with the nearest peak after
    // add their delta together 
    //
    int maxProfit01(vector<int> &prices) {

        int max = 0;
        int low = -1;
	int len = prices.size();
        for (int i=0; i < len - 1; i++){
            //meet the valley, then goes up
            if (prices[i] < prices[i+1] && low < 0 ) {
                low = i;
            }
            //meet the peak, then goes down
            if (prices[i] > prices[i+1] && low >= 0) {
                max += ( prices[i] - prices[low] ) ;
                low = -1; // reset the `low`
            }
        }

        // edge case
        if ( low >= 0 ) {
            max += ( prices[prices.size()-1] - prices[low] );
        }

        return max;
    }

    // Solution 2 
    // if we find we can earn money, we just sell
    int maxProfit02(vector<int>& prices) {
        int profit = 0 ;
        for(int i=1; i< prices.size(); i++) {
            profit += max(0, prices[i] - prices[i-1]);
        }
        return profit;
    }
};
```
- best-time-to-buy-and-sell-stock
```c++
// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/

/***************************************************************************************************** 
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of 
 * the stock), design an algorithm to find the maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *              Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * Example 2:
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 ******************************************************************************************************/

class Solution {
public:
    //
    // This solution is O(1) space dynamic programming 
    //
    // We can make sure the max profit at least be ZERO. So,
    //    1) we have two pointers (begin & end ) 
    //    2) if prices[end] - prices[begin] >  0, then move the "end" pointer to next
    //    3) if prices[end] - prices[begin] <= 0, then move the "begin" pointer to current posstion.
    //    4) tracking the max profit
    //
    // Notes:
    //    Some people think find the highest-price & lowest-price, this is wrong. 
    //    Because the highest-price must be after lowest-price
    //
    int maxProfit(vector<int> &prices) {
        
        int max=0, begin=0, end=0, delta=0;
        
        for (int i=0; i<prices.size(); i++) {
            
            end = i;
            
            delta = prices[end] - prices[begin];
            
            if (delta <= 0){
                begin = i;
            }
            
            if ( delta > max ){
                max = delta;
            }
            
        }
        
        return max;
        
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        for (auto p : prices) {
    	    // Keep tracking the previous lowest price
            buy = min (buy, p);
	    // Keep tacking the current max profit
            profit = max(profit, p - buy);
        }
        return profit;
    }
};
```
- best-time-to-buy-and-sell-stock-iii
```c++
// Source : https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Date   : 2014-08-22

/***************************************************************************************************** 
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock 
 * before you buy again).
 * 
 * Example 1:
 * 
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 *              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
 * 
 * Example 2:
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 *              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 *              engaging multiple transactions at the same time. You must sell before buying again.
 * 
 * Example 3:
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 ******************************************************************************************************/


class Solution {
public:
    // Dynamic Programming
    //
    //     Considering prices[n], and we have a position "i", we could have
    //       1) the maxProfit1 for prices[0..i]  
    //       2) the maxProfit2 for proices[i..n]
    //
    //    So, 
    //      for 1) we can go through the prices[n] forwardly.
    //          forward[i] = max( forward[i-1], price[i] - lowestPrice[0..i] ) 
    //      for 2) we can go through the prices[n] backwoardly.
    //          backward[i] = max( backward[i+1], highestPrice[i..n] - price[i]) 
    //
    int maxProfit(vector<int> &prices) {
        if (prices.size()<=1) return 0;
        
        int n = prices.size();
        
        vector<int> forward(n);
        forward[0] = 0;
        int lowestBuyInPrice = prices[0];
        for(int i=1; i<n; i++){
            forward[i] = max(forward[i-1], prices[i] - lowestBuyInPrice);
            lowestBuyInPrice = min(lowestBuyInPrice, prices[i]);
        }
        
        vector<int> backward(n);
        backward[n-1] = 0;
        int highestSellOutPrice = prices[n-1];
        for(int i=n-2; i>=0; i--){
            backward[i] = max(backward[i+1], highestSellOutPrice - prices[i]);
            highestSellOutPrice = max(highestSellOutPrice, prices[i]);
        }
        
        int max_profit = 0;
        for(int i=0; i<n; i++){
            max_profit = max(max_profit, forward[i]+backward[i]);
        }
        
        return max_profit;
    }
};
```
- best-time-to-buy-and-sell-stock-iv
```c++
// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

/***************************************************************************************************** 
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before 
 * you buy again).
 * 
 * Example 1:
 * 
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
 * 
 * Example 2:
 * 
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
 *              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 ******************************************************************************************************/

class Solution {
    public:
        /*
         *  profits[trans, day]
         *  - `trans` represents the number of transactions we've done so far. ( 0 <= trans <= k )
         *  - `day` represents the number of days so far. ( 0 <= day <= prices.size() )
         *
         *  So, we have the initialization as below:
         *
         *  profits[0, day] = 0; // 0 <= day <= prices.size()
         *  profits[trans, 0] = 0; // 0 <= trans <= k
         *
         *  And the iteration logic as below:
         *
         *  profits[trans, day] = max (
         *                              profits[trans, day-1], // same times transactions, but one days before.
         *                              profits[trans-1, i-1] + (prices[day] - prices[i]) // for all of (0 <= i < day )
         *                                                                                // this means find max profit from
         *                                                                                // previous any of days
         *                            )
         *
         */

        int maxProfit(int k, vector<int> &prices) {
            int ndays = prices.size();

            // error case
            if (ndays<=1) return 0;

            // Edge case
            // ---------
            // if the number of transactions is too many, it means we can make
            // as many transactions as we can, that brings us the problem back to
            // Best-Time-To-Buy-And-Sell-Stock-II which can be simply solve in O(n)
            // by using a greedy approach.
            if(k > ndays/2){
                int sum = 0;
                for (int i=1; i<ndays; i++) {
                    sum += max(prices[i] - prices[i-1], 0);
                }
                return sum;
            }

            return maxProfit_DP03(k, prices);//8ms
            return maxProfit_DP02(k, prices);//8ms
            return maxProfit_DP01(k, prices);//492ms
        }


        //DP solution - O(kn^2) complexity
        int maxProfit_DP01 (int k, vector<int> &prices) {
            int ndays = prices.size();
            vector< vector<int> > profits(k+1, vector<int>( ndays+1, 0));
            for(int trans=1; trans<=k; trans++) {
                for (int day=1; day<=ndays; day++) {
                    int m=0;
                    for (int i=1; i<=day; i++) {
                        m = max(m, profits[trans-1][i-1]+ prices[day-1] - prices[i-1]);
                    }
                    profits[trans][day] =  max( profits[trans][day-1], m);
                }
            }
            return profits[k][ndays];
        }

        //DP solution - O(kn) complexity
        //Actually, we could save the loop in above- for(int i=1; i<=day; i++)
        //Becasue there are so many dupliations

        int maxProfit_DP02 (int k, vector<int> &prices) {

            int ndays = prices.size();

            vector< vector<int> > profits(k+1, vector<int>( ndays+1, 0));
            vector<int> m(ndays+1, 0); // tracking the max profits of previous days

            for(int trans=1; trans<=k; trans++) {
                m[0] = profits[trans-1][0] - prices[0];
                for (int day=1; day<=ndays; day++) {
                    profits[trans][day] =  max( profits[trans][day-1], m[day-1]+prices[day-1]);
                    if (day < ndays) {
                        m[day] = max(m[day-1], profits[trans-1][day] - prices[day]);
                    }
                }
            }
            return profits[k][ndays];
        }


        // save the memory, remove the m[ ] array
        int maxProfit_DP03 (int k, vector<int> &prices) {
            int ndays = prices.size();
            vector< vector<int> > profits(k+1, vector<int>( ndays+1, 0));

            for(int trans=1; trans<=k; trans++) {
                int m = profits[trans-1][0] - prices[0];
                for (int day=1; day <= ndays; day++) {
                    profits[trans][day] = max(profits[trans][day-1], m + prices[day-1]);
                    if ( day < ndays ) {
                        m = max(m, profits[trans-1][day] - prices[day]);
                    }
                }
            }

            return profits[k][ndays];
        }
};
```
- best-time-to-buy-and-sell-stock-with-transaction-fee
```c++
// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
/***************************************************************************************************** 
 *
 * Your are given an array of integers prices, for which the i-th element is the price of a given 
 * stock on day i; and a non-negative integer fee representing a transaction fee.
 *
 * You may complete as many transactions as you like, but you need to pay the transaction fee for each 
 * transaction.  You may not buy more than 1 share of a stock at a time (ie. you must sell the stock 
 * share before you buy again.)
 *
 * Return the maximum profit you can make.
 * 
 * Example 1:
 * 
 * Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * Output: 8
 *
 * Explanation: The maximum profit can be achieved by:
 * Buying at prices[0] = 1Selling at prices[3] = 8Buying at prices[4] = 4Selling at prices[5] = 9The 
 * total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 * 
 * Note:
 * 0 < prices.length <= 50000.
 * 0 < prices[i] < 50000.
 * 0 <= fee < 50000.
 ******************************************************************************************************/


class Solution {
private:
    int max(int x, int y) {
        return x > y ? x: y;
    }
    int max(int x, int y, int z) {
        return max(x, max(y,z));
    }

public:

    int maxProfit(vector<int>& prices, int fee) {
        return maxProfit_dp03(prices, fee); // 100ms
        return maxProfit_dp02(prices, fee); // 100ms
        return maxProfit_dp01(prices, fee); // 2700ms
    }

    // find the [buy-low, sell-high] prices pairs,
    // and remove the unnecessary prices.
    void genPricesPairs(vector<int> &prices, vector< pair<int, int> > &prices_pairs, int fee){

        int low = -1;
        for (int i=0; i<prices.size()-1; i++){
            //meet the valley, then goes up
            if (prices[i] < prices[i+1] && low < 0 ) {
                low = i;
            }
            //meet the peak, then goes down
            if (prices[i] > prices[i+1] && low >= 0) {
                prices_pairs.push_back( make_pair( prices[low], prices[i]) );
                low = -1; // reset the `low` & `high`
            }
        }

        // edge case
        if ( low >= 0 ) {
            prices_pairs.push_back( make_pair( prices[low], prices[prices.size()-1] ) );
        }

    }

    int maxProfit_dp01(vector<int> &prices, int &fee) {

        vector< pair<int, int> > prices_pairs;
        genPricesPairs(prices, prices_pairs, fee);

        vector<int> dp(prices_pairs.size()+1, 0);

        for (int i=0; i<prices_pairs.size(); i++) {
            for ( int j=0; j<=i; j++ ) {
                int profit = prices_pairs[i].second - prices_pairs[j].first - fee;
                // if the profit is negative, skip the transaction
                if ( profit < 0 ) profit = 0;
                dp[i+1] = max ( dp[i+1], dp[j] + profit);
            }
        }

        return dp[dp.size()-1];
    }

    int maxProfit_dp02(vector<int> &prices, int &fee) {

        vector< pair<int, int> > prices_pairs;
        genPricesPairs(prices, prices_pairs, fee);

        if ( prices_pairs.size() < 1 ) return 0;


        // first - represent  the max profit if we buy.
        // second - represent the max profit if we sell.
        vector< pair<int,int> > dp(prices_pairs.size() , make_pair(0,0) );

        //buy profit - if we buy it in day 0, then we got negtive profit.
        dp[0].first = - prices_pairs[0].first;

        //sell profit - if we sell it in day 0, then we have the profits
        //              if the profit is negtive, then won't sell it.
        dp[0].second = max(0, prices_pairs[0].second - prices_pairs[0].first - fee);

        for (int i=1; i<prices_pairs.size(); i++) {
            // BUY - we could have three options
            //   1) hold the stock do nothing.  profit = previous day's buy profit
            //   2) sell & buy. profit = previous sell profit - spent money to buy.
            //   3) fresh buy, give up the pervious buy, just buy it today.
            // find the max profit of these 3 options.

            dp[i].first = max (dp[i-1].first,                          // option 1) do nothing
                               dp[i-1].second - prices_pairs[i].first, // option 2) sell & buy
                               - prices_pairs[i].first );              // option 3) fresh buy

            // SELL - we could have three options
            //   1) hold the stock do nothing. profit = previous day's sell profit
            //   2) sell it. profit = previous day's buy + today's sell.
            //   3) sell previous and sell today. profit = previous's sell + today's sell
            // Find the max profit of these 3 options
            dp[i].second = max(dp[i-1].second,
                               dp[i-1].first + prices_pairs[i].second - fee,
                               dp[i-1].second + prices_pairs[i].second - prices_pairs[i].first - fee );
        }

        return max( dp[dp.size()-1].second, 0 );

    }

    //
    // Actually, by given any day, we can have two status:
    // 1) BUY status - we can have two options at Day X.
    //     i) buy stock - need previous sell status.(you cannot buy if you haven't sold)
    //    ii) do nothing - need previous buy status.
    //
    // 2) SELL status - we can have two options at Day X.
    //     i) sell stock - need previous buy status.(you cannot sell if you haven't bought)
    //    ii) do nothing - keep the previous sell status.
    //
    // For example:
    //
    //    if we have [1,3,2,8,4,9], fee = 2
    //    then we could have the following BUY & SELL status
    //
    //    Day One
    //        1 - BUY: the profit is -1 ,becuase we spent 1 money
    //            SELL: you cannot sell, the profit is 0.
    //    Day Two
    //        3 - BUY : pre-SELL - 3 = -3, but do nothing has max profit pre-BUY: -1
    //            SELL: pre-BUY + 3 -2 = -1+3-2 = 0 , the max profit: 0
    //    Day Three
    //        2 - BUY : pre-SELL - 2 = 0 - 2 = -2, do nothing has max profit: -1
    //            SELL: pre-BUY + 2 -2 = -1 + 2 -2 = -1, do nothing has max profit: 0
    //    Day Four
    //        8 - BUY : pre-SELL - 8 =  0 - 8 = -8, so, just hold, the max buy profit: -1
    //            SELL: pre-BUY + 8 - 2 = -1+8-2 =5, the max profit is 5
    //    Day Five
    //        4 - BUY : pre-SELL - 4 = 5-4 = 1, do nothing profit is -1, so should buy it.
    //                  so, the max buy profit is 1.
    //            SELL: pre-BUY + 4 -2 = -1 + 4 -2= 1, it's has lower profit than previous,
    //                  so, we won't sell, the max sell profit is 5.
    //    Day Six
    //        9 - BUY : pre-SELL - 9 = 5-9= -4, so won't buy, the max buy profit is 1.
    //            SELL: pre-BUY + 9 -2 = 1 + 9 -2 = 8, it's has higher profit. so we sell
    //
    //   Let's use an table
    //
    //            prices =   1,  3,  2,  8,  4,  9
    //    max buy profit =  -1, -1, -1, -1,  1,  5
    //   max sell profit =   0,  0,  0,  5,  5,  8
    //
    //   We can see we keep tracking the max buy and sell profit for everyday.
    //
    //       buy[i] = max( buy[i-1],                // do nothing
    //                     sell[i-1] - prices[i] ); // sell in previous day can buy today
    //
    //       sell[i] = max( sell[i-1],                    // do nothing
    //                      buy[i-1] + prices[i] - fee ); // sell today
    //
    int maxProfit_dp03(vector<int> &prices, int &fee) {
        int buy=-prices[0], sell=0;
        int pre_buy=0, pre_sell=0;

        for(auto price: prices) {
            pre_buy = buy;
            buy = max (sell - price, pre_buy);

            pre_sell = sell;
            sell = max( pre_buy + price - fee, pre_sell);
        }

        return sell;
    }
};
```
- best-time-to-buy-and-sell-stock-with-cooldown
```c++
// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Author : Hao Chen
// Date   : 2019-02-01

/***************************************************************************************************** 
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 * (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 * 
 * 	You may not engage in multiple transactions at the same time (ie, you must sell the stock 
 * before you buy again).
 * 	After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * 
 * Example:
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 ******************************************************************************************************/
class Solution {
public:
    //
    //Define 
    //
    //  - buy[i] as the max profit when you buy the stock at day i. 
    //  - sell[i] as the max profit when you sell the stock at day i. 
    //
    // Therefore set buy[0] = -prices[0], because spend the money, the profit is -prices[0].
    // Also set sell[0] = 0, that you do nothing in the first day.
    //
    // So,
    //     buy[i] = max(buy[i-1],                // do nothing - keep holding
    //                  sell[i-2] - prices[i] )  // sell previous day, buy today
    //                                           // i-1 is cooldown day
    //     sell[i] = max(sell[i-1],              // do nothing 
    //                   buy[i-1] + prices[i] )  // buy previous day, sell today.
    //  
    
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if ( len < 2 ) return 0;
        
        vector<int> buy(len, 0);
        vector<int> sell(len, 0);
        
        //day 0
        buy[0] = -prices[0];
        sell[0] = 0;
        
        //day 1
        buy[1] = max(buy[0], 0 - prices[1]);
        sell[1] = max(sell[0], buy[0] + prices[1]);
        
        for (int i=2; i<len; i++) {
            buy[i]  = max( buy[i - 1], sell[i - 2] - prices[i]);   
            sell[i] = max(sell[i - 1],  buy[i - 1] + prices[i]);
        }
        
        return sell[len-1];
    }
};
```