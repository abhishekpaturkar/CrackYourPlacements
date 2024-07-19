class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minimumSoFar = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int mini = prices[i];
            minimumSoFar = min(mini, minimumSoFar);
            int maxi = prices[i] - minimumSoFar;
            maxProfit = max(maxProfit, maxi);
        }
        return maxProfit;
    }
};