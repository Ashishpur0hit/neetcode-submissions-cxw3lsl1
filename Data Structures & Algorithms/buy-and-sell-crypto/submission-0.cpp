class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),buy=0,sell=0,max_profit=0;
        while(sell<n)
        {
            if(prices[sell]<prices[buy])    buy=sell;
            else    max_profit = max(max_profit,prices[sell++]-prices[buy]);
        }
        return max_profit;
    }
};
