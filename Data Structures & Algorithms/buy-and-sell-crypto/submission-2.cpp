class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),buy=0,sell=1,curr_profit=0,max_profit=0;
        while(sell<n)
        {
            if(prices[sell]<prices[buy])buy=sell;
            curr_profit = prices[sell]-prices[buy];
            max_profit=max(max_profit,curr_profit);
            sell++;
        }
        return max_profit;
    }
};
