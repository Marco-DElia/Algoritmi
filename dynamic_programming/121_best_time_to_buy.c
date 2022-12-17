int maxProfit(int* prices, int pricesSize){

    int profit = 0, max = prices[pricesSize - 1];

    int temp;
    for (int i = pricesSize - 1; i >= 0; i--)
    {
        if (prices[i] > max) max = prices[i];
        if (max - prices[i] > profit) profit = max - prices[i];
    }

    return profit;
}