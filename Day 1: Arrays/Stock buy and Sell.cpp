class Solution
{
public:
    int maxPofit(vector<int> &prices)
    {
        int maximumProfit = 0;
        int minPrice = INT_MAX;

        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maximumProfit = max(maximumProfit, prices[i] - minPrice);
        }
        return maximumProfit;
    }
};