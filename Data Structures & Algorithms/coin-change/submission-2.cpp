class Solution {
public:
    int fun(vector<int>& coins, int amount, int index)
{
    if(amount == 0)
        return 0;

    if(amount < 0)
        return 10001;

    if(index == coins.size())
        return 10001;

    int take = 1 + fun(coins, amount - coins[index], index);
    int skip = fun(coins, amount, index + 1);

    return min(take, skip);
}
    int coinChange(vector<int>& coins, int amount) {
        int ans = fun(coins,amount,0);
        return (ans>=10001)?-1:ans;
    }
};
